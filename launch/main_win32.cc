#include "launch/pch.hh"

#include "launch/launch.hh"

#include "common/commandline.hh"

static void showErrorMessage(const char* message)
{
    MessageBoxA(nullptr, message, "Engine Error", MB_ICONERROR | MB_OK);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    auto logger = spdlog::default_logger_raw();
    logger->set_level(spdlog::level::trace);
    logger->set_pattern("%v");

    commandline::parse(__argc, __argv);

    auto& sinks = logger->sinks();

    sinks.clear();
    sinks.push_back(std::make_shared<spdlog::sinks::msvc_sink_mt>());
    sinks.push_back(std::make_shared<spdlog::sinks::stderr_color_sink_mt>());

#ifdef NDEBUG
    auto use_winconsole = commandline::hasOption("winconsole") && AllocConsole();
#else
    auto use_winconsole = AllocConsole();
#endif

    if(use_winconsole) {
        sinks.push_back(std::make_shared<spdlog::sinks::wincolor_stdout_sink_mt>());
    }

    try {
        launch::start();
        return EXIT_SUCCESS;
    }
    catch(const std::exception& ex) {
        spdlog::critical("Engine error: {}", ex.what());
        showErrorMessage(ex.what());
        return EXIT_FAILURE;
    }
    catch(...) {
        spdlog::critical("Engine error: unknown exception");
        showErrorMessage("Non-std::exception throw in the engine");
        return EXIT_FAILURE;
    }
}
