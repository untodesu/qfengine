#include "client/pch.hh"

#include "client/main.hh"

#include "modules/client_modules.hh"
#include "modules/shared_modules.hh"

void client::main(void)
{
    shared_modules::invoke(qf::ModuleCallback::Initialize);
    client_modules::invoke(qf::ModuleCallback::Initialize);
}
