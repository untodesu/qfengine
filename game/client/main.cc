#include "client/pch.hh"

#include "client/main.hh"

#include "client/clientmodule.hh"
#include "shared/sharedmodule.hh"

extern qf::ClientModule qfortress_client;

void client::main(void)
{
    qf::ClientModule::invokeAll(qf::ModuleFunction::InitializeEarly);
}
