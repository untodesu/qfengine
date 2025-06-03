#ifndef COMMON_UTILS_CRC64_HH
#define COMMON_UTILS_CRC64_HH
#pragma once

namespace utils
{
std::uint64_t CRC64(const void* buffer, std::size_t size, std::uint64_t start = UINT64_C(0));
std::uint64_t CRC64(const std::vector<std::byte>& buffer, std::uint64_t start = UINT64_C(0));
std::uint64_t CRC64(const std::string& buffer, std::uint64_t start = UINT64_C(0));
} // namespace utils

#endif // COMMON_UTILS_CRC64_HH
