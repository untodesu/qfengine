#ifndef COMMON_CONFIG_NUMBER_HH
#define COMMON_CONFIG_NUMBER_HH
#pragma once

#include "common/config/value.hh"

namespace config
{
template<typename T> concept NumberType = std::integral<T> || std::floating_point<T>;
} // namespace config

namespace config
{
template<NumberType T>
class Number final : public IConfigValue {
public:
    constexpr static T LIMIT_MIN = std::numeric_limits<T>::min();
    constexpr static T LIMIT_MAX = std::numeric_limits<T>::max();

    explicit Number(T default_value, T min_value = LIMIT_MIN, T max_value = LIMIT_MAX);
    virtual ~Number(void) override = default;

    virtual const char* rawGet(void) const override;
    virtual void rawSet(const char* value) override;

    virtual Number& operator=(T value);
    virtual operator T(void) const;

private:
    std::string m_string;
    T m_value;
    T m_min;
    T m_max;
};

using Integer = Number<int>;
using Unsigned = Number<unsigned int>;
using Floating = Number<float>;
} // namespace config

template<config::NumberType T>
config::Number<T>::Number(T default_value, T min_value, T max_value) : m_min(min_value), m_max(max_value)
{
    m_value = std::clamp(default_value, m_min, m_max);
    m_string = std::to_string(m_value);
}

template<config::NumberType T>
const char* config::Number<T>::rawGet(void) const
{
    return m_string.c_str();
}

template<config::NumberType T>
void config::Number<T>::rawSet(const char* value)
{
    std::istringstream stream(value);

    stream >> m_value;
    m_value = std::clamp(m_value, m_min, m_max);
    m_string = std::to_string(m_value);
}

template<config::NumberType T>
config::Number<T>& config::Number<T>::operator=(T value)
{
    m_value = std::clamp(value, m_min, m_max);
    m_string = std::to_string(m_value);
    return *this;
}

template<config::NumberType T>
config::Number<T>::operator T(void) const
{
    return m_value;
}

#endif // COMMON_CONFIG_NUMBER_HH
