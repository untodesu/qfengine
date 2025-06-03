#include "launch/pch.hh"

#include "launch/launch.hh"

void launch::start(void)
{
    spdlog::info("ADASDASDASDADSDAS");

#if defined(QF_CLIENT)
    // TODO: run client
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
}
