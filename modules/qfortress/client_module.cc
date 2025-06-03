#include "qfortress/client_pch.hh"

#include "game/client/clientmodule.hh"

static void qfortress_initializeEarly(void)
{
    spdlog::info("QFortress Client Module!");
}

__declspec(selectany) qf::ClientModule qfortress_client({
    { qf::ModuleFunction::InitializeEarly, &qfortress_initializeEarly },
});
