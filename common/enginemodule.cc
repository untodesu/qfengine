#include "common/pch.hh"

#include "common/enginemodule.hh"

#include "common/debug/assert.hh"

qf::EngineModule::EngineModule(const std::unordered_map<qf::ModuleFunction, qf::ModuleFunctionSignature*>& functions)
{
    m_initializeEarly = nullptr;
    m_initialize = nullptr;
    m_shutdownEarly = nullptr;
    m_shutdown = nullptr;
    m_fixedUpdate = nullptr;
    m_fixedUpdateLate = nullptr;
    m_update = nullptr;
    m_updateLate = nullptr;
    m_render = nullptr;
    m_layout = nullptr;

    for(const auto& function : functions) {
        switch(function.first) {
            case qf::ModuleFunction::InitializeEarly:
                QF_ASSERT(m_initializeEarly == nullptr);
                m_initializeEarly = function.second;
                break;

            case qf::ModuleFunction::Initialize:
                QF_ASSERT(m_initialize == nullptr);
                m_initialize = function.second;
                break;

            case qf::ModuleFunction::ShutdownEarly:
                QF_ASSERT(m_shutdownEarly == nullptr);
                m_shutdownEarly = function.second;
                break;

            case qf::ModuleFunction::Shutdown:
                QF_ASSERT(m_shutdown == nullptr);
                m_shutdown = function.second;
                break;

            case qf::ModuleFunction::FixedUpdate:
                QF_ASSERT(m_fixedUpdate == nullptr);
                m_fixedUpdate = function.second;
                break;

            case qf::ModuleFunction::FixedUpdateLate:
                QF_ASSERT(m_fixedUpdateLate == nullptr);
                m_fixedUpdateLate = function.second;
                break;

            case qf::ModuleFunction::Update:
                QF_ASSERT(m_update == nullptr);
                m_update = function.second;
                break;

            case qf::ModuleFunction::UpdateLate:
                QF_ASSERT(m_updateLate == nullptr);
                m_updateLate = function.second;
                break;

            case qf::ModuleFunction::Render:
                QF_ASSERT(m_render == nullptr);
                m_render = function.second;
                break;

            case qf::ModuleFunction::Layout:
                QF_ASSERT(m_layout == nullptr);
                m_layout = function.second;
                break;

            default:
                throw std::runtime_error("Unknown module function");
        }
    }
}

void qf::EngineModule::invoke(qf::ModuleFunction function) const
{
    switch(function) {
        case qf::ModuleFunction::InitializeEarly:
            if(m_initializeEarly)
                m_initializeEarly();
            break;

        case qf::ModuleFunction::Initialize:
            if(m_initialize)
                m_initialize();
            break;

        case qf::ModuleFunction::ShutdownEarly:
            if(m_shutdownEarly)
                m_shutdownEarly();
            break;

        case qf::ModuleFunction::Shutdown:
            if(m_shutdown)
                m_shutdown();
            break;

        case qf::ModuleFunction::FixedUpdate:
            if(m_fixedUpdate)
                m_fixedUpdate();
            break;

        case qf::ModuleFunction::FixedUpdateLate:
            if(m_fixedUpdateLate)
                m_fixedUpdateLate();
            break;

        case qf::ModuleFunction::Update:
            if(m_update)
                m_update();
            break;

        case qf::ModuleFunction::UpdateLate:
            if(m_updateLate)
                m_updateLate();
            break;

        case qf::ModuleFunction::Render:
            if(m_render)
                m_render();
            break;

        case qf::ModuleFunction::Layout:
            if(m_layout)
                m_layout();
            break;

        default:
            throw std::runtime_error("Unknown module function");
    }
}
