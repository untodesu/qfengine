#ifndef CLIENT_GLOBALS_HH
#define CLIENT_GLOBALS_HH
#pragma once

#include "shared/globals.hh"

namespace config
{
class Map;
} // namespace config

namespace globals
{
extern float frametime;
extern float frametime_avg;
extern std::uint64_t frametime_us;
extern std::uint64_t framecount;
} // namespace globals

namespace globals
{
extern GLFWwindow* window;
extern int window_width;
extern int window_height;
extern float window_aspect;
} // namespace globals

namespace globals
{
extern std::size_t num_drawcalls;
extern std::size_t num_triangles;
} // namespace globals

namespace globals
{
extern config::Map client_config;
} // namespace globals

#endif // CLIENT_GLOBALS_HH
