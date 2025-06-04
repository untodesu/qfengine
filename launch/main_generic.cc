#include "launch/pch.hh"

#include "launch/launch.hh"

#include "common/commandline.hh"

int main(int argc, char** argv)
{
    auto logger = spdlog::default_logger_raw();
    logger->set_level(spdlog::level::trace);
    logger->set_pattern("%v");

    auto& sinks = logger->sinks();

    sinks.clear();
    sinks.push_back(std::make_shared<spdlog::sinks::stderr_color_sink_mt>());

    commandline::parse(argc, argv);

    try {
        launch::start();
        return EXIT_SUCCESS;
    }
    catch(const std::exception& ex) {
        spdlog::critical("Engine error: {}", ex.what());
        return EXIT_FAILURE;
    }
    catch(...) {
        spdlog::critical("Engine error: unknown exception");
        return EXIT_FAILURE;
    }
}
