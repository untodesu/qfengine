#ifndef CLIENT_RENDER_HH
#define CLIENT_RENDER_HH
#pragma once

namespace render_impl
{
void setupWindowing(void);
} // namespace render_impl

namespace render_impl
{
void initialize(void);
void initializeLate(void);
void shutdown(void);
} // namespace render_impl

namespace render_impl
{
void prepare(void);
void present(void);
} // namespace render_impl

namespace render_impl
{
void renderWorld(void);
void renderImGui(void);
} // namespace render_impl

#endif // CLIENT_RENDER_HH
