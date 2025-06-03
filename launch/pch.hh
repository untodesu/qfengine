#ifndef LAUNCH_PCH_HH
#define LAUNCH_PCH_HH

#include <common/pch.hh>

#include <spdlog/sinks/stdout_color_sinks.h>

#ifdef _WIN32
#include <spdlog/sinks/msvc_sink.h>
#include <spdlog/sinks/wincolor_sink.h>
#include <windows.h>
#endif // _WIN32

#endif // LAUNCH_PCH_HH
