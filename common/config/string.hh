#ifndef COMMON_CONFIG_STRING_HH
#define COMMON_CONFIG_STRING_HH
#pragma once

#include "common/config/value.hh"

namespace config
{
class String final : public IConfigValue {
public:
    explicit String(std::string_view default_value);
    virtual ~String(void) override = default;

    virtual const char* rawGet(void) const override;
    virtual void rawSet(const char* value) override;

    String& operator=(const char* value);
    operator const std::string&(void) const;
    operator const char*(void) const;

private:
    std::string m_value;
};
} // namespace config

#endif // COMMON_CONFIG_STRING_HH
