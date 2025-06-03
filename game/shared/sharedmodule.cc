#include "shared/pch.hh"

#include "shared/sharedmodule.hh"

qf::SharedModule* qf::SharedModule::s_instances = nullptr;

void qf::SharedModule::invokeAll(qf::ModuleFunction function)
{
    for(auto instance = s_instances; instance; instance = instance->m_next_instance) {
        instance->invoke(function);
    }
}

qf::SharedModule::SharedModule(const std::unordered_map<ModuleFunction, ModuleFunctionSignature*>& functions) : EngineModule(functions)
{
    m_next_instance = s_instances;
    s_instances = this;
}
