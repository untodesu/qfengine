#include "shared/example/example_pch.hh"

#include "common/module.hh"

static void sharedExample_initializeEarly(void)
{
    spdlog::info("example shared module: initializeEarly()");
}

static void sharedExample_initialize(void)
{
    spdlog::info("example shared module: initialize()");
}

static void sharedExample_shutdownEarly(void)
{
    spdlog::info("example shared module: shutdownEarly()");
}

static void sharedExample_shutdown(void)
{
    spdlog::info("example shared module: shutdown()");
}

static void sharedExample_fixedUpdate(void)
{
    spdlog::info("example shared module: fixedUpdate()");
}

static void sharedExample_fixedUpdateLate(void)
{
    spdlog::info("example shared module: fixedUpdateLate()");
}

// This is the entry point for the module; it is
// pulled by the generated code and registered at link time;
QF_IMPLEMENT_MODULE({
    { qf::ModuleCallback::InitializeEarly, &sharedExample_initializeEarly },
    { qf::ModuleCallback::Initialize, &sharedExample_initialize },
    { qf::ModuleCallback::ShutdownEarly, &sharedExample_shutdownEarly },
    { qf::ModuleCallback::Shutdown, &sharedExample_shutdown },
    { qf::ModuleCallback::FixedUpdate, &sharedExample_fixedUpdate },
    { qf::ModuleCallback::FixedUpdateLate, &sharedExample_fixedUpdateLate },
});
