#include "launch/pch.hh"

#include "launch/launch.hh"

#include "common/commandline.hh"
#include "common/threading.hh"
#include "common/utils/physfs.hh"

#include "game/client/main.hh"

static spdlog::level::level_enum getLogLevel(void)
{
    if(commandline::hasOption("quiet"))
        return spdlog::level::warn;
    if(commandline::hasOption("verbose"))
        return spdlog::level::trace;
    return spdlog::level::info;
}

void launch::start(int argc, char** argv)
{
    auto logger = spdlog::default_logger_raw();
    logger->set_pattern("%H:%M:%S.%e %^[%L]%$ %v");
    logger->set_level(getLogLevel());
    logger->flush();

    if(!PHYSFS_init(argv[0])) {
        throw std::runtime_error(std::format("PhysFS: init failed: {}", utils::getPhysfsError()));
    }

    threading::initialize();

#if defined(QF_CLIENT)
    client::main();
#elif defined(QF_SERVER)
    // TODO: run server
#else
#error Have you heard of a hit game Among Us? It's a multiplayer game
#error where players work together on a spaceship, but some are impostors
#error trying to sabotage the mission. The game is known for its social
#error deduction gameplay, where players must figure out who the impostors
#error are while completing tasks. It's a fun and engaging game that has
#error gained immense popularity.
#endif

    threading::shutdown();

    if(!PHYSFS_deinit()) {
        throw std::runtime_error(std::format("PhysFS: deinit failed: {}", utils::getPhysfsError()));
    }
}
