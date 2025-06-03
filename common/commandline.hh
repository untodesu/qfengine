#ifndef COMMON_COMMANDLINE_HH
#define COMMON_COMMANDLINE_HH
#pragma once

namespace commandline
{
void parse(int argc, char** argv);
void addOption(std::string_view name);
void addOption(std::string_view name, std::string_view value);
const char* getOption(std::string_view name, const char* fallback = nullptr);
bool hasOption(std::string_view name);
} // namespace commandline

#endif // COMMON_COMMANDLINE_HH
