#ifndef COMMON_PLUGIN_HH
#define COMMON_PLUGIN_HH
#pragma once

namespace qf
{
/// Each engine plugin registers a bunch of these callbacks
/// and they are statically linked into the produced binaries
extern "C" using PluginCallbackFn = void(void);

enum class PluginCallback : unsigned int {
    InitializeEarly = 0,
    Initialize,
    ShutdownEarly,
    Shutdown,
    FixedUpdate,
    FixedUpdateLate,
    Update,
    UpdateLate,
    Render,
    Layout,
    COUNT
};

constexpr static std::size_t PLUGIN_CALLBACK_COUNT = static_cast<std::size_t>(PluginCallback::COUNT);

class Plugin final {
public:
    explicit Plugin(const std::unordered_map<PluginCallback, PluginCallbackFn*>& callbacks);
    virtual ~Plugin(void) = default;

    void invoke(PluginCallback callback) const;

private:
    std::array<PluginCallbackFn*, PLUGIN_CALLBACK_COUNT> m_callbacks;
};
} // namespace qf

#endif // COMMON_PLUGIN_HH
