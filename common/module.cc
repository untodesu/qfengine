#include "common/pch.hh"

#include "common/module.hh"

#include "common/debug/assert.hh"

qf::Module::Module(const std::unordered_map<ModuleCallback, ModuleCallbackFn*>& callbacks)
{
    m_callbacks.fill(nullptr);

    for(const auto& callback : callbacks) {
        auto index = static_cast<std::size_t>(callback.first);

        qf_assert(index < MODULE_CALLBACK_COUNT);
        qf_assert(callback.second);

        m_callbacks[index] = callback.second;
    }
}

void qf::Module::invoke(ModuleCallback callback) const
{
    auto index = static_cast<std::size_t>(callback);

    qf_assert(index < MODULE_CALLBACK_COUNT);

    if(auto function_ptr = m_callbacks[index]) {
        function_ptr();
    }
}
