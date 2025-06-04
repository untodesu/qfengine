#include "common/pch.hh"

#include "common/plugin.hh"

#include "common/debug/assert.hh"

qf::Plugin::Plugin(const std::unordered_map<PluginCallback, PluginCallbackFn*>& callbacks)
{
    m_callbacks.fill(nullptr);

    for(const auto& callback : callbacks) {
        auto index = static_cast<std::size_t>(callback.first);

        qf_assert(index < PLUGIN_CALLBACK_COUNT);
        qf_assert(callback.second);

        m_callbacks[index] = callback.second;
    }
}

void qf::Plugin::invoke(PluginCallback callback) const
{
    auto index = static_cast<std::size_t>(callback);

    qf_assert(index < PLUGIN_CALLBACK_COUNT);

    if(auto function_ptr = m_callbacks[index]) {
        function_ptr();
    }
}
