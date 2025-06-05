#include "client/pch.hh"

#include "client/game.hh"

#include "common/utils/epoch.hh"

#include "shared/game.hh"

#include "client/globals.hh"

#include "modules/client_modules.hh"

void client_game::initializeEarly(void)
{
    shared_game::initializeEarly();
    client_modules::invoke(qf::ModuleCallback::InitializeEarly);
}

void client_game::initialize(void)
{
    shared_game::initialize();
    client_modules::invoke(qf::ModuleCallback::Initialize);
}

void client_game::shutdownEarly(void)
{
    client_modules::invoke(qf::ModuleCallback::ShutdownEarly);
    shared_game::shutdownEarly();
}

void client_game::shutdown(void)
{
    client_modules::invoke(qf::ModuleCallback::Shutdown);
    shared_game::shutdown();
}

void client_game::fixedUpdate(void)
{
    shared_game::fixedUpdate();
    client_modules::invoke(qf::ModuleCallback::FixedUpdate);
}

void client_game::fixedUpdateLate(void)
{
    client_modules::invoke(qf::ModuleCallback::FixedUpdateLate);
    shared_game::fixedUpdateLate();
}

void client_game::update(void)
{
    client_modules::invoke(qf::ModuleCallback::Update);
}

void client_game::updateLate(void)
{
    client_modules::invoke(qf::ModuleCallback::UpdateLate);
}

void client_game::layout(void)
{
    client_modules::invoke(qf::ModuleCallback::Layout);
}
