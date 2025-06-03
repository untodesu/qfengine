#include "common/pch.hh"

#include "common/config/string.hh"

config::String::String(std::string_view default_value) : m_value(default_value)
{
    // empty
}

const char* config::String::rawGet(void) const
{
    return m_value.c_str();
}

void config::String::rawSet(const char* value)
{
    m_value = value;
}

config::String& config::String::operator=(const char* value)
{
    m_value = value;
    return *this;
}

config::String::operator const std::string&(void) const
{
    return m_value;
}

config::String::operator const char*(void) const
{
    return m_value.c_str();
}
