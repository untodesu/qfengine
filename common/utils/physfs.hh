#ifndef COMMON_UTILS_PHYSFS_HH
#define COMMON_UTILS_PHYSFS_HH
#pragma once

namespace utils
{
const char* getPhysfsError(void);
} // namespace utils

namespace utils
{
bool readFileString(const std::filesystem::path& path, std::string& buffer);
bool writeFileString(const std::filesystem::path& path, const std::string& buffer);
bool writeFileStringAppend(const std::filesystem::path& path, const std::string& buffer);
} // namespace utils

namespace utils
{
bool readFileBytes(const std::filesystem::path& path, std::vector<std::byte>& buffer);
bool writeFileBytes(const std::filesystem::path& path, const std::vector<std::byte>& buffer);
bool writeFileBytesAppend(const std::filesystem::path& path, const std::vector<std::byte>& buffer);
} // namespace utils

namespace utils
{
bool readFileStream(const std::filesystem::path& path, std::istringstream& stream);
bool writeFileStream(const std::filesystem::path& path, const std::ostringstream& stream);
bool writeFileStreamAppend(const std::filesystem::path& path, const std::ostringstream& stream);
} // namespace utils

#endif // COMMON_UTILS_PHYSFS_HH
