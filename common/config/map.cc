#include "common/pch.hh"

#include "common/config/map.hh"

#include "common/config/value.hh"
#include "common/debug/assert.hh"
#include "common/utils/physfs.hh"
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
    qf_assert(key);

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
    qf_assert(key);

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
    qf_assert(key);

    auto it = m_values.find(key);

    if(it != m_values.end())
        return it->second;
    return nullptr;
}

void config::Map::loadFromStream(std::istream& stream, bool append)
{
    qf_assert(stream.good());

    if(!append) {
        m_values.clear();
    }

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
            spdlog::warn("config: malformed line: '{}'", kv_string);
            continue;
        }

        auto kv_name = utils::trimWhitespace(kv_string.substr(0, separator));
        auto kv_value = utils::trimWhitespace(kv_string.substr(separator + 1));

        if(auto configValue = findMutable(kv_name)) {
            configValue->rawSet(kv_value.c_str());
        }
        else {
            spdlog::warn("config: unknown key '{}', ignoring", kv_name);
            continue;
        }
    }
}

void config::Map::saveToStream(std::ostream& stream) const
{
    qf_assert(stream.good());

    auto curtime = std::time(nullptr);

    stream << "# QFengine configuration file" << std::endl;
    stream << "# Generated at: " << std::put_time(std::gmtime(&curtime), "%Y-%m-%d %H:%M:%S") << std::endl;
    stream << "# WARNING: changes will be overwritten" << std::endl << std::endl;

    for(const auto& [key, value] : m_values) {
        stream << key << " = " << value->rawGet() << std::endl;
    }
}

bool config::Map::loadFromFile(const std::filesystem::path& path, bool append)
{
    std::istringstream stream;

    if(utils::readFileStream(path, stream)) {
        loadFromStream(stream, append);
        return true;
    }

    return false;
}

bool config::Map::saveToFile(const std::filesystem::path& path) const
{
    std::ostringstream stream;

    saveToStream(stream);

    return utils::writeFileStream(path, stream);
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
