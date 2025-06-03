#include "common/pch.hh"

#include "common/config/map.hh"

#include "common/config/value.hh"
#include "common/debug/assert.hh"
#include "common/utils/string.hh"

void config::Map::add(std::string_view key, IConfigValue& value)
{
    m_values.emplace(std::string(key), &value);
}

void config::Map::set(std::string_view key, const std::string& value)
{
    if(auto configValue = findMutable(key)) {
        configValue->rawSet(value.c_str());
    }
}

void config::Map::set(const char* key, const std::string& value)
{
    QF_ASSERT(key);

    if(auto configValue = findMutable(key)) {
        configValue->rawSet(value.c_str());
    }
}

const char* config::Map::get(std::string_view key, const char* fallback) const
{
    if(auto configValue = find(key))
        return configValue->rawGet();
    return fallback;
}

const char* config::Map::get(const char* key, const char* fallback) const
{
    QF_ASSERT(key);

    if(auto configValue = find(key))
        return configValue->rawGet();
    return fallback;
}

const config::IConfigValue* config::Map::find(std::string_view key) const
{
    auto it = m_values.find(std::string(key));

    if(it != m_values.end())
        return it->second;
    return nullptr;
}

const config::IConfigValue* config::Map::find(const char* key) const
{
    QF_ASSERT(key);

    auto it = m_values.find(key);

    if(it != m_values.end())
        return it->second;
    return nullptr;
}

void config::Map::loadFrom(std::istream& stream)
{
    QF_ASSERT(stream.good());

    std::string line;
    std::string kv_string;

    while(std::getline(stream, line)) {
        auto comment = line.find_first_of('#');

        if(comment == std::string::npos) {
            // No comments found in the line
            kv_string = utils::trimWhitespace(line);
        }
        else {
            // Clip out the comment part
            kv_string = utils::trimWhitespace(line.substr(0, comment));
        }

        if(utils::isWhitespace(kv_string)) {
            // Ignore empty or commented out lines
            continue;
        }

        auto separator = kv_string.find('=');

        if(separator == std::string::npos) {
            spdlog::warn("config::Map::loadFrom: malformed line: '{}'", kv_string);
            continue;
        }

        auto kv_name = utils::trimWhitespace(kv_string.substr(0, separator));
        auto kv_value = utils::trimWhitespace(kv_string.substr(separator + 1));

        if(auto configValue = findMutable(kv_name)) {
            configValue->rawSet(kv_value.c_str());
        }
        else {
            spdlog::warn("config::Map::loadFrom: unknown key '{}', ignoring", kv_name);
            continue;
        }
    }
}

void config::Map::saveTo(std::ostream& stream) const
{
    QF_ASSERT(stream.good());

    auto curtime = std::time(nullptr);

    stream << "# QFortress configuration file" << std::endl;
    stream << "# Generated at: " << std::put_time(std::gmtime(&curtime), "%Y-%m-%d %H:%M:%S") << std::endl;
    stream << "# WARNING: changes will be overwritten next time the game is run" << std::endl << std::endl;

    for(const auto& [key, value] : m_values) {
        stream << key << " = " << value->rawGet() << std::endl;
    }
}

config::IConfigValue* config::Map::findMutable(std::string_view key)
{
    // This is horrid but it works and I don't care
    return const_cast<IConfigValue*>(find(key));
}

config::IConfigValue* config::Map::findMutable(const char* key)
{
    // This is horrid but it works and I don't care
    return const_cast<IConfigValue*>(find(key));
}

void config::Map::forEachValue(const std::function<void(const std::string&, const IConfigValue&)>& callback) const
{
    for(const auto& [key, value] : m_values) {
        callback(key, *value);
    }
}
