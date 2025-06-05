#ifndef COMMON_CONFIG_MAP_HH
#define COMMON_CONFIG_MAP_HH
#pragma once

namespace config
{
class IConfigValue;

class Map final {
public:
    explicit Map(void) = default;
    virtual ~Map(void) = default;

    void add(std::string_view key, IConfigValue& value);
    void set(std::string_view key, const std::string& value);
    void set(const char* key, const std::string& value);
    const char* get(std::string_view key, const char* fallback = nullptr) const;
    const char* get(const char* key, const char* fallback = nullptr) const;

    const IConfigValue* find(std::string_view key) const;
    const IConfigValue* find(const char* key) const;

    void loadFromStream(std::istream& stream, bool append = false);
    void saveToStream(std::ostream& stream) const;

    bool loadFromFile(const std::filesystem::path& path, bool append = false);
    bool saveToFile(const std::filesystem::path& path) const;

    void forEachValue(const std::function<void(const std::string&, const IConfigValue&)>& callback) const;

private:
    IConfigValue* findMutable(std::string_view key);
    IConfigValue* findMutable(const char* key);

    std::unordered_map<std::string, IConfigValue*> m_values;
};
} // namespace config

#endif // COMMON_CONFIG_MAP_HH
