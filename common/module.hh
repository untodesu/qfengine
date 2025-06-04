#ifndef COMMON_MODULE_HH
#define COMMON_MODULE_HH
#pragma once

namespace qf
{
/// Each engine module registers a bunch of these callbacks
/// and they are statically linked into the produced binaries
extern "C" using ModuleCallbackFn = void(void);

enum class ModuleCallback : unsigned int {
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

constexpr static std::size_t MODULE_CALLBACK_COUNT = static_cast<std::size_t>(ModuleCallback::COUNT);

class Module final {
public:
    explicit Module(const std::unordered_map<ModuleCallback, ModuleCallbackFn*>& callbacks);
    virtual ~Module(void) = default;

    void invoke(ModuleCallback callback) const;

private:
    std::array<ModuleCallbackFn*, MODULE_CALLBACK_COUNT> m_callbacks;
};
} // namespace qf

#endif // COMMON_MODULE_HH
