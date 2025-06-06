#ifndef CLIENT_RENDER_RENDER_HH
#define CLIENT_RENDER_RENDER_HH
#pragma once

namespace render
{
void setupWindowHints(void);
} // namespace render

namespace render
{
void initialize(void);
void initializeLate(void);
void shutdownEarly(void);
void shutdown(void);
} // namespace render

namespace render
{
void prepare(void);
void renderWorld(void);
void renderImGui(void);
void present(void);
} // namespace render

#endif // CLIENT_RENDER_RENDER_HH
