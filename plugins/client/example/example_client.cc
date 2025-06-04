#include "client/example/example_pch.hh"

#include "common/plugin.hh"

static void clientExample_initializeEarly(void)
{
    spdlog::info("example client plugin: initializeEarly()");
}

static void clientExample_initialize(void)
{
    spdlog::info("example client plugin: initialize()");
}

static void clientExample_shutdownEarly(void)
{
    spdlog::info("example client plugin: shutdownEarly()");
}

static void clientExample_shutdown(void)
{
    spdlog::info("example client plugin: shutdown()");
}

static void clientExample_fixedUpdate(void)
{
    spdlog::info("example client plugin: fixedUpdate()");
}

static void clientExample_fixedUpdateLate(void)
{
    spdlog::info("example client plugin: fixedUpdateLate()");
}

static void clientExample_update(void)
{
    spdlog::info("example client plugin: update()");
}

static void clientExample_updateLate(void)
{
    spdlog::info("example client plugin: updateLate()");
}

static void clientExample_render(void)
{
    spdlog::info("example client plugin: render()");
}

static void clientExample_layout(void)
{
    spdlog::info("example client plugin: layout()");
}

// This is the entry point for the plugin; it is
// pulled by the generated code and registered at link time;
// NOTENOTE: the name of the variable must match the target name
qf::Plugin example_client({
    { qf::PluginCallback::InitializeEarly, &clientExample_initializeEarly },
    { qf::PluginCallback::Initialize, &clientExample_initialize },
    { qf::PluginCallback::ShutdownEarly, &clientExample_shutdownEarly },
    { qf::PluginCallback::Shutdown, &clientExample_shutdown },
    { qf::PluginCallback::FixedUpdate, &clientExample_fixedUpdate },
    { qf::PluginCallback::FixedUpdateLate, &clientExample_fixedUpdateLate },
    { qf::PluginCallback::Update, &clientExample_update },
    { qf::PluginCallback::UpdateLate, &clientExample_updateLate },
    { qf::PluginCallback::Render, &clientExample_render },
    { qf::PluginCallback::Layout, &clientExample_layout },
});
