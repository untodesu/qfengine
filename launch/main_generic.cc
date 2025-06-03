#include "launch/pch.hh"

#include "launch/launch.hh"

#include "common/commandline.hh"

int main(int argc, char** argv)
{
    commandline::parse(argc, argv);

    auto default_logger = spdlog::default_logger_raw();
    auto& logger_sinks = default_logger->sinks();

    logger_sinks.clear();
    logger_sinks.push_back(std::make_shared<spdlog::sinks::stderr_color_sink_mt>());

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
