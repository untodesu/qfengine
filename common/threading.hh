#ifndef COMMON_THREADING_HH
#define COMMON_THREADING_HH
#pragma once

enum class TaskStatus : unsigned int {
    Enqueued,
    Processing,
    Completed,
    Cancelled,
};

class Task {
public:
    virtual ~Task(void) = default;
    virtual void process(void) = 0;
    virtual void finalize(void) = 0;

    TaskStatus getStatus(void) const;
    void setStatus(TaskStatus status);

protected:
    std::atomic<TaskStatus> m_status;
    std::future<void> m_future;
};

template<typename T> concept DerivedTask = std::derived_from<T, Task>;

namespace threading
{
void initialize(void);
void shutdown(void);
void update(void);
} // namespace threading

namespace threading::detail
{
void submitTask(Task* task);
} // namespace threading::detail

namespace threading
{
template<DerivedTask T, typename... Args>
void submit(Args&&... args);
} // namespace threading

template<DerivedTask T, typename... Args>
inline void threading::submit(Args&&... args)
{
    threading::detail::submitTask(new T(std::forward<Args>(args)...));
}

#endif // COMMON_THREADING_HH
