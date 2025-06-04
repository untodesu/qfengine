#ifndef COMMON_DEBUG_ASSERT_HH
#define COMMON_DEBUG_ASSERT_HH
#pragma once

#define QF_FORCE_ASSERT(condition, message)                                                                                    \
    do {                                                                                                                       \
        if(!(condition)) {                                                                                                     \
            auto error_message = std::format("Assertion failed: [{}] at {}:{} - {}", #condition, __FILE__, __LINE__, message); \
            spdlog::critical(error_message);                                                                                   \
            throw std::runtime_error(error_message);                                                                           \
        }                                                                                                                      \
    } while(false)

#if defined(QF_NO_ASSERT) || defined(NDEBUG)
#define qf_assert(condition)               static_cast<void>(condition)
#define qf_assert_msg(condition, message)  static_cast<void>(condition)
#define qf_assert_fmt(condition, fmt, ...) static_cast<void>(condition)
#else
#define qf_assert(condition)               QF_FORCE_ASSERT(condition, std::string())
#define qf_assert_msg(condition, message)  QF_FORCE_ASSERT(condition, std::string(message))
#define qf_assert_fmt(condition, fmt, ...) QF_FORCE_ASSERT(condition, std::format(fmt, __VA_ARGS__))
#endif // QF_NO_ASSERT

#endif // COMMON_DEBUG_ASSERT_HH
