#ifndef COMMON_UTILS_EPOCH_HH
#define COMMON_UTILS_EPOCH_HH
#pragma once

namespace utils
{
std::uint64_t unixSeconds(void);
std::uint64_t unixMilliseconds(void);
std::uint64_t unixMicroseconds(void);
} // namespace utils

namespace utils
{
std::int64_t unixSecondsSigned(void);
std::int64_t unixMillisecondsSigned(void);
std::int64_t unixMicrosecondsSigned(void);
} // namespace utils

#endif // COMMON_UTILS_EPOCH_HH
