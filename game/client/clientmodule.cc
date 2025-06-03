#include "client/pch.hh"

#include "client/clientmodule.hh"

qf::ClientModule* qf::ClientModule::s_instances = nullptr;

void qf::ClientModule::invokeAll(qf::ModuleFunction function)
{
    for(auto instance = s_instances; instance; instance = instance->m_next_instance) {
        instance->invoke(function);
    }
}

qf::ClientModule::ClientModule(const std::unordered_map<ModuleFunction, ModuleFunctionSignature*>& functions) : EngineModule(functions)
{
    spdlog::info("CONSTRUCTOR CALLED");

    m_next_instance = s_instances;
    s_instances = this;
}
