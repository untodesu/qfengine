#include "game/client/pch.hh"

#include "common/config/map.hh"
#include "common/config/number.hh"
#include "common/module.hh"

#include "game/client/globals.hh"

static config::Floating perflog_frequency(2.0, 1.0, 30.0);

static std::uint64_t perflog_us;
static std::uint64_t perflog_next_time;

static void perflog_initializeEarly(void)
{
    globals::client_config.add("perflog.frequency", perflog_frequency);
}

static void perflog_initialize(void)
{
    perflog_us = 1.0e6 / perflog_frequency;
    perflog_next_time = globals::curtime + perflog_us;
}

static void perflog_updateLate(void)
{
    if(globals::curtime >= perflog_next_time) {
        spdlog::debug("perflog: {:.03f} FPS [{:.03f} ms]", 1.0 / globals::frametime_avg, 1000.0 * globals::frametime_avg);
        perflog_next_time = globals::curtime + perflog_us;
    }
}

qf::Module perflog_client({
    { qf::ModuleCallback::InitializeEarly, &perflog_initializeEarly },
    { qf::ModuleCallback::Initialize, &perflog_initialize },
    { qf::ModuleCallback::UpdateLate, &perflog_updateLate },
});
