#ifndef COMMON_CONFIG_VALUE_HH
#define COMMON_CONFIG_VALUE_HH
#pragma once

namespace config
{
class IConfigValue {
public:
    virtual ~IConfigValue(void) = default;
    virtual const char* rawGet(void) const = 0;
    virtual void rawSet(const char* value) = 0;
};
} // namespace config

#endif // COMMON_CONFIG_VALUE_HH
