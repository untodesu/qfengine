#ifndef COMMON_ENGINEMODULE_HH
#define COMMON_ENGINEMODULE_HH
#pragma once

namespace qf
{
enum class ModuleFunction {
    InitializeEarly,
    Initialize,
    ShutdownEarly,
    Shutdown,
    FixedUpdate,
    FixedUpdateLate,
    Update,
    UpdateLate,
    Render,
    Layout,
};

using ModuleFunctionSignature = void(void);

class EngineModule {
protected:
    explicit EngineModule(const std::unordered_map<ModuleFunction, ModuleFunctionSignature*>& callbacks);
    virtual ~EngineModule(void) = default;

    void invoke(ModuleFunction function) const;

private:
    ModuleFunctionSignature* m_initializeEarly;
    ModuleFunctionSignature* m_initialize;
    ModuleFunctionSignature* m_shutdownEarly;
    ModuleFunctionSignature* m_shutdown;
    ModuleFunctionSignature* m_fixedUpdate;
    ModuleFunctionSignature* m_fixedUpdateLate;
    ModuleFunctionSignature* m_update;
    ModuleFunctionSignature* m_updateLate;
    ModuleFunctionSignature* m_render;
    ModuleFunctionSignature* m_layout;
};
} // namespace qf

#endif // COMMON_ENGINEMODULE_HH
