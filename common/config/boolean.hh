#ifndef COMMON_CONFIG_BOOLEAN_HH
#define COMMON_CONFIG_BOOLEAN_HH

#include "common/config/value.hh"

namespace config
{
class Boolean final : public IConfigValue {
public:
    constexpr static const char* VALUE_TRUE = "TRUE";
    constexpr static const char* VALUE_FALSE = "FALSE";

    explicit Boolean(bool default_value);
    virtual ~Boolean(void) override = default;
    virtual const char* rawGet(void) const override;
    virtual void rawSet(const char* value) override;

    virtual Boolean& operator=(bool value);
    virtual operator bool(void) const;

private:
    bool m_value;
};
} // namespace config

#endif // COMMON_CONFIG_BOOLEAN_HH
