#include "server/example/example_pch.hh"

#include "common/plugin.hh"

static void serverExample_initializeEarly(void)
{
    spdlog::info("example server plugin: initializeEarly()");
}

static void serverExample_initialize(void)
{
    spdlog::info("example server plugin: initialize()");
}

static void serverExample_shutdownEarly(void)
{
    spdlog::info("example server plugin: shutdownEarly()");
}

static void serverExample_shutdown(void)
{
    spdlog::info("example server plugin: shutdown()");
}

static void serverExample_fixedUpdate(void)
{
    spdlog::info("example server plugin: fixedUpdate()");
}

static void serverExample_fixedUpdateLate(void)
{
    spdlog::info("example server plugin: fixedUpdateLate()");
}

// This is the entry point for the plugin; it is
// pulled by the generated code and registered at link time;
// NOTENOTE: the name of the variable must match the target name
qf::Plugin example_server({
    { qf::PluginCallback::InitializeEarly, &serverExample_initializeEarly },
    { qf::PluginCallback::Initialize, &serverExample_initialize },
    { qf::PluginCallback::ShutdownEarly, &serverExample_shutdownEarly },
    { qf::PluginCallback::Shutdown, &serverExample_shutdown },
    { qf::PluginCallback::FixedUpdate, &serverExample_fixedUpdate },
    { qf::PluginCallback::FixedUpdateLate, &serverExample_fixedUpdateLate },
});
