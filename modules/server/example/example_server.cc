#include "server/example/example_pch.hh"

#include "common/module.hh"

static void serverExample_initializeEarly(void)
{
    spdlog::info("example server module: initializeEarly()");
}

static void serverExample_initialize(void)
{
    spdlog::info("example server module: initialize()");
}

static void serverExample_shutdownEarly(void)
{
    spdlog::info("example server module: shutdownEarly()");
}

static void serverExample_shutdown(void)
{
    spdlog::info("example server module: shutdown()");
}

static void serverExample_fixedUpdate(void)
{
    spdlog::info("example server module: fixedUpdate()");
}

static void serverExample_fixedUpdateLate(void)
{
    spdlog::info("example server module: fixedUpdateLate()");
}

// This is the entry point for the module; it is
// pulled by the generated code and registered at link time;
QF_IMPLEMENT_MODULE({
    { qf::ModuleCallback::InitializeEarly, &serverExample_initializeEarly },
    { qf::ModuleCallback::Initialize, &serverExample_initialize },
    { qf::ModuleCallback::ShutdownEarly, &serverExample_shutdownEarly },
    { qf::ModuleCallback::Shutdown, &serverExample_shutdown },
    { qf::ModuleCallback::FixedUpdate, &serverExample_fixedUpdate },
    { qf::ModuleCallback::FixedUpdateLate, &serverExample_fixedUpdateLate },
});
