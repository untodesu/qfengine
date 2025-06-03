#include "common/pch.hh"

#include "common/commandline.hh"

constexpr static char OPTION_PREFIX = '-';

static std::unordered_map<std::string, std::string> s_options;

static bool isOptionString(const std::string& string)
{
    if(string.find_last_of(OPTION_PREFIX) >= (string.size() - 1))
        return false;
    return string[0] == OPTION_PREFIX;
}

static inline std::string getOptionString(const std::string& string)
{
    std::size_t i;
    for(i = 0; string[i] == OPTION_PREFIX; ++i)
        ;
    return std::string(string.cbegin() + i, string.cend());
}

void commandline::parse(int argc, char** argv)
{
    for(int i = 1; i < argc; ++i) {
        std::string option_argv(argv[i]);

        if(!isOptionString(option_argv)) {
            spdlog::warn("commandline: unknown option '{}'", option_argv);
            continue;
        }

        auto option_string = getOptionString(option_argv);
        auto next_i = i + 1;

        if(next_i < argc) {
            auto argument_argv = std::string(argv[next_i]);

            if(!isOptionString(argument_argv)) {
                s_options.insert_or_assign(option_string, argument_argv);
                i = next_i; // Skip the argument
                continue;
            }

            s_options.insert_or_assign(option_string, std::string());
        }
    }
}

void commandline::addOption(std::string_view name)
{
    s_options.insert_or_assign(std::string(name), std::string());
}

void commandline::addOption(std::string_view name, std::string_view value)
{
    s_options.insert_or_assign(std::string(name), std::string(value));
}

const char* commandline::getOption(std::string_view name, const char* fallback)
{
    auto it = s_options.find(std::string(name));

    if(it != s_options.end() && !it->second.empty())
        return it->second.c_str();
    return fallback;
}

bool commandline::hasOption(std::string_view name)
{
    return s_options.count(std::string(name)) > 0;
}
