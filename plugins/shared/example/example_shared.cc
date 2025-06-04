#include "shared/example/example_pch.hh"

#include "common/plugin.hh"

static void sharedExample_initializeEarly(void)
{
    spdlog::info("example shared plugin: initializeEarly()");
}

static void sharedExample_initialize(void)
{
    spdlog::info("example shared plugin: initialize()");
}

static void sharedExample_shutdownEarly(void)
{
    spdlog::info("example shared plugin: shutdownEarly()");
}

static void sharedExample_shutdown(void)
{
    spdlog::info("example shared plugin: shutdown()");
}

static void sharedExample_fixedUpdate(void)
{
    spdlog::info("example shared plugin: fixedUpdate()");
}

static void sharedExample_fixedUpdateLate(void)
{
    spdlog::info("example shared plugin: fixedUpdateLate()");
}

// This is the entry point for the plugin; it is
// pulled by the generated code and registered at link time;
// NOTENOTE: the name of the variable must match the target name
qf::Plugin example_shared({
    { qf::PluginCallback::InitializeEarly, &sharedExample_initializeEarly },
    { qf::PluginCallback::Initialize, &sharedExample_initialize },
    { qf::PluginCallback::ShutdownEarly, &sharedExample_shutdownEarly },
    { qf::PluginCallback::Shutdown, &sharedExample_shutdown },
    { qf::PluginCallback::FixedUpdate, &sharedExample_fixedUpdate },
    { qf::PluginCallback::FixedUpdateLate, &sharedExample_fixedUpdateLate },
});
