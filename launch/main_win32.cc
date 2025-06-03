#include "launch/pch.hh"

#include "launch/launch.hh"

#include "common/commandline.hh"

static void showErrorMessage(const char* message)
{
    MessageBoxA(nullptr, message, "Engine Error", MB_ICONERROR | MB_OK);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    commandline::parse(__argc, __argv);

    auto default_logger = spdlog::default_logger_raw();
    auto& logger_sinks = default_logger->sinks();

    logger_sinks.clear();
    logger_sinks.push_back(std::make_shared<spdlog::sinks::msvc_sink_mt>());
    logger_sinks.push_back(std::make_shared<spdlog::sinks::stderr_color_sink_mt>());

#ifdef NDEBUG
    auto use_winconsole = commandline::hasOption("winconsole") && AllocConsole();
#else
    auto use_winconsole = AllocConsole();
#endif

    if(use_winconsole) {
        logger_sinks.push_back(std::make_shared<spdlog::sinks::wincolor_stderr_sink_mt>());
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
