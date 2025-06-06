#include "shared/pch.hh"

#include "shared/game.hh"

#include "shared/gameinfo.hh"

#include "modules/shared_modules.hh"

void shared_game::initializeEarly(void)
{
    gameinfo::initializeEarly();

    spdlog::info("gameinfo: game_name: {}", gameinfo::game_name);
    spdlog::info("gameinfo: game_author: {}", gameinfo::game_author);

    shared_modules::invoke(qf::ModuleCallback::InitializeEarly);
}

void shared_game::initialize(void)
{
    shared_modules::invoke(qf::ModuleCallback::Initialize);
}

void shared_game::shutdownEarly(void)
{
    shared_modules::invoke(qf::ModuleCallback::ShutdownEarly);
}

void shared_game::shutdown(void)
{
    shared_modules::invoke(qf::ModuleCallback::Shutdown);
}

void shared_game::fixedUpdate(void)
{
    shared_modules::invoke(qf::ModuleCallback::FixedUpdate);
}

void shared_game::fixedUpdateLate(void)
{
    shared_modules::invoke(qf::ModuleCallback::FixedUpdateLate);
}
