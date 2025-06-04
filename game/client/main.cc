#include "client/pch.hh"

#include "client/main.hh"

#include "plugins/client_plugins.hh"
#include "plugins/shared_plugins.hh"

void client::main(void)
{
    shared_plugins::invoke(qf::PluginCallback::Initialize);
    client_plugins::invoke(qf::PluginCallback::Initialize);
}
