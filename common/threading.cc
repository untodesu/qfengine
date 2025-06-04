#include "common/pch.hh"

#include "common/threading.hh"

#include "common/commandline.hh"
#include "common/debug/assert.hh"

constexpr static const char* DEFAULT_POOL_SIZE_ARG = "4";

static BS::light_thread_pool* s_thread_pool;
static std::deque<Task*> s_task_deque;

static void taskProcess(Task* task)
{
    task->setStatus(TaskStatus::Processing);
    task->process();

    if(task->getStatus() == TaskStatus::Processing) {
        // If the task status is still PROCESSING
        // it can be deduced it hasn't been cancelled
        task->setStatus(TaskStatus::Completed);
    }
}

TaskStatus Task::getStatus(void) const
{
    return m_status;
}

void Task::setStatus(TaskStatus status)
{
    m_status = status;
}

void threading::initialize(void)
{
    auto argument = commandline::getOption("threads", DEFAULT_POOL_SIZE_ARG);
    auto num_concurrent_threads = std::thread::hardware_concurrency();
    unsigned int thread_pool_size;

    if(num_concurrent_threads && 0 == std::strcmp(argument, "max")) {
        // Use the maximum available number of concurrent
        // hardware threads provided by the implementation
        thread_pool_size = num_concurrent_threads;
    }
    else {
        if(num_concurrent_threads) {
            thread_pool_size = std::clamp<unsigned int>(std::strtoul(argument, nullptr, 10), 1U, num_concurrent_threads);
        }
        else {
            thread_pool_size = std::clamp<unsigned int>(std::strtoul(argument, nullptr, 10), 1U, 10U);
        }
    }

    spdlog::info("threading: allocating {} threads for pooled tasks", thread_pool_size);

    s_thread_pool = new BS::light_thread_pool(thread_pool_size);
    s_task_deque.clear();
}

void threading::shutdown(void)
{
    for(auto task : s_task_deque) {
        auto status = task->getStatus();

        if(status != TaskStatus::Cancelled || status != TaskStatus::Completed) {
            task->setStatus(TaskStatus::Cancelled);
        }
    }

    s_thread_pool->purge();
    s_thread_pool->wait();

    for(auto task : s_task_deque)
        delete task;
    s_task_deque.clear();

    delete s_thread_pool;
}

void threading::update(void)
{
    auto task_iter = s_task_deque.cbegin();

    while(task_iter != s_task_deque.cend()) {
        auto task_ptr = *task_iter;
        auto status = task_ptr->getStatus();

        if(status == TaskStatus::Cancelled) {
            delete task_ptr;
            task_iter = s_task_deque.erase(task_iter);
            continue;
        }

        if(status == TaskStatus::Completed) {
            task_ptr->finalize();
            delete task_ptr;
            task_iter = s_task_deque.erase(task_iter);
            continue;
        }

        task_iter = std::next(task_iter);
    }
}

void threading::detail::submitTask(Task* task)
{
    qf_assert(task);

    task->setStatus(TaskStatus::Enqueued);

    static_cast<void>(s_thread_pool->submit_task(std::bind(&taskProcess, task)));

    s_task_deque.push_back(task);
}
