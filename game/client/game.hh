#ifndef CLIENT_GAME_HH
#define CLIENT_GAME_HH
#pragma once

namespace client_game
{
void initializeEarly(void);
void initialize(void);
void shutdownEarly(void);
void shutdown(void);
void fixedUpdate(void);
void fixedUpdateLate(void);
void update(void);
void updateLate(void);
void render(void);
void layout(void);
} // namespace client_game

namespace client_game
{
bool isRunning(void);
} // namespace client_game

#endif // CLIENT_GAME_HH
