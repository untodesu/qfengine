#ifndef SERVER_SERVERMODULE_HH
#define SERVER_SERVERMODULE_HH
#pragma once

#include "common/enginemodule.hh"

namespace qf
{
class ServerModule final : public EngineModule {
public:
    static void invokeAll(ModuleFunction function);

    explicit ServerModule(const std::unordered_map<ModuleFunction, ModuleFunctionSignature*>& functions);
    virtual ~ServerModule() override = default;

private:
    static ServerModule* s_instances;
    ServerModule* m_next_instance;
};
} // namespace qf

#endif // SERVER_SERVERMODULE_HH
