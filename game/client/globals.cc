#include "client/pch.hh"

#include "client/globals.hh"

#include "common/config/map.hh"

float globals::frametime;
float globals::frametime_avg;
std::uint64_t globals::frametime_us;
std::uint64_t globals::framecount;

GLFWwindow* globals::window;
int globals::window_width;
int globals::window_height;
float globals::window_aspect;

std::size_t globals::num_drawcalls;
std::size_t globals::num_triangles;

config::Map globals::client_config;
