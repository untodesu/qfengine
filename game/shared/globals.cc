#include "shared/pch.hh"

#include "shared/globals.hh"

entt::dispatcher globals::dispatcher;
entt::registry globals::registry;

float globals::fixed_frametime;
float globals::fixed_frametime_avg;
std::uint64_t globals::fixed_frametime_us;
std::uint64_t globals::fixed_framecount;

std::uint64_t globals::curtime;
