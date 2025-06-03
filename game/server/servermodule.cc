#include "server/pch.hh"

#include "server/servermodule.hh"

qf::ServerModule* qf::ServerModule::s_instances = nullptr;

void qf::ServerModule::invokeAll(qf::ModuleFunction function)
{
    for(auto instance = s_instances; instance; instance = instance->m_next_instance) {
        instance->invoke(function);
    }
}

qf::ServerModule::ServerModule(const std::unordered_map<ModuleFunction, ModuleFunctionSignature*>& functions) : EngineModule(functions)
{
    m_next_instance = s_instances;
    s_instances = this;
}
