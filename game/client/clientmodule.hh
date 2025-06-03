#ifndef CLIENT_CLIENTMODULE_HH
#define CLIENT_CLIENTMODULE_HH
#pragma once

#include "common/enginemodule.hh"

namespace qf
{
class ClientModule final : public EngineModule {
public:
    static void invokeAll(ModuleFunction function);

    explicit ClientModule(const std::unordered_map<ModuleFunction, ModuleFunctionSignature*>& functions);
    virtual ~ClientModule() override = default;

private:
    static ClientModule* s_instances;
    ClientModule* m_next_instance;
};
} // namespace qf

#endif // CLIENT_CLIENTMODULE_HH
