#ifndef SHARED_GAME_HH
#define SHARED_GAME_HH
#pragma once

namespace shared_game
{
void initializeEarly(void);
void initialize(void);
void shutdownEarly(void);
void shutdown(void);
void fixedUpdate(void);
void fixedUpdateLate(void);
} // namespace shared_game

#endif // SHARED_GAME_HH
