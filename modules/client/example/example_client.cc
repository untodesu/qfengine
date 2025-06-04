#include "client/example/example_pch.hh"

#include "common/module.hh"

static void clientExample_initializeEarly(void)
{
    spdlog::info("example client module: initializeEarly()");
}

static void clientExample_initialize(void)
{
    spdlog::info("example client module: initialize()");
}

static void clientExample_shutdownEarly(void)
{
    spdlog::info("example client module: shutdownEarly()");
}

static void clientExample_shutdown(void)
{
    spdlog::info("example client module: shutdown()");
}

static void clientExample_fixedUpdate(void)
{
    spdlog::info("example client module: fixedUpdate()");
}

static void clientExample_fixedUpdateLate(void)
{
    spdlog::info("example client module: fixedUpdateLate()");
}

static void clientExample_update(void)
{
    spdlog::info("example client module: update()");
}

static void clientExample_updateLate(void)
{
    spdlog::info("example client module: updateLate()");
}

static void clientExample_render(void)
{
    spdlog::info("example client module: render()");
}

static void clientExample_layout(void)
{
    spdlog::info("example client module: layout()");
}

// This is the entry point for the module; it is
// pulled by the generated code and registered at link time;
// NOTENOTE: the name of the variable must match the target name
qf::Module example_client({
    { qf::ModuleCallback::InitializeEarly, &clientExample_initializeEarly },
    { qf::ModuleCallback::Initialize, &clientExample_initialize },
    { qf::ModuleCallback::ShutdownEarly, &clientExample_shutdownEarly },
    { qf::ModuleCallback::Shutdown, &clientExample_shutdown },
    { qf::ModuleCallback::FixedUpdate, &clientExample_fixedUpdate },
    { qf::ModuleCallback::FixedUpdateLate, &clientExample_fixedUpdateLate },
    { qf::ModuleCallback::Update, &clientExample_update },
    { qf::ModuleCallback::UpdateLate, &clientExample_updateLate },
    { qf::ModuleCallback::Render, &clientExample_render },
    { qf::ModuleCallback::Layout, &clientExample_layout },
});
