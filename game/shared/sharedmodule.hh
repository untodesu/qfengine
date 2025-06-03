#ifndef SHARED_SHAREDMODULE_HH
#define SHARED_SHAREDMODULE_HH
#pragma once

#include "common/enginemodule.hh"

namespace qf
{
class SharedModule final : public EngineModule {
public:
    static void invokeAll(ModuleFunction function);

    explicit SharedModule(const std::unordered_map<ModuleFunction, ModuleFunctionSignature*>& functions);
    virtual ~SharedModule() override = default;

private:
    static SharedModule* s_instances;
    SharedModule* m_next_instance;
};
} // namespace qf

#endif // SHARED_SHAREDMODULE_HH
