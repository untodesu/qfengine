#ifndef COMMON_DEBUG_ASSERT_HH
#define COMMON_DEBUG_ASSERT_HH
#pragma once

#define qf_assert_base(condition, fmt, ...)                                                                      \
    do {                                                                                                         \
        if(!(condition)) {                                                                                       \
            auto file_name = std::filesystem::path(__FILE__).filename().string();                                \
            auto message = std::format((fmt), __VA_ARGS__);                                                      \
            spdlog::critical("debug: assertion failed: {} [{}:{}]", message, file_name, __LINE__);               \
            throw std::runtime_error(std::format("assertion failed: {} [{}:{}]", message, file_name, __LINE__)); \
        }                                                                                                        \
    } while(false)

#ifdef NDEBUG
#define qf_assert_fmg(x, fmt, ...) static_cast<void>(x)
#define qf_assert_msg(x, msg)      static_cast<void>(x)
#define qf_assert(x)               static_cast<void>(x)
#else
#define qf_assert_fmt(x, fmt, ...) qf_assert_base((x), (fmt), __VA_ARGS__)
#define qf_assert_msg(x, msg)      qf_assert_base((x), "{}", (msg))
#define qf_assert(x)               qf_assert_base((x), "{}", (#x))
#endif

#define qf_force_assert_fmt(x, fmt, ...) qf_assert_base((x), (fmt), __VA_ARGS__)
#define qf_force_assert_msg(x, msg)      qf_assert_base((x), "{}", (msg))
#define qf_force_assert(x)               qf_assert_base((x), "{}", (#x))

#endif // COMMON_DEBUG_ASSERT_HH
