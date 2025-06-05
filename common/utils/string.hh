#ifndef COMMON_UTILS_STRING_HH
#define COMMON_UTILS_STRING_HH
#pragma once

namespace utils
{
bool isWhitespace(const std::string& string);
std::string join(const std::vector<std::string>& strings, const std::string& separator);
std::vector<std::string> split(const std::string& string, const std::string& separator);
std::string replaceAll(const std::string& string, const std::string& pattern, const std::string& with);
std::string replaceMap(const std::string& string, const std::unordered_map<std::string, std::string>& lut);
std::string trimWhitespace(const std::string& string);
} // namespace utils

#endif // COMMON_UTILS_STRING_HH
