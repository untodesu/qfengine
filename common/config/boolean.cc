#include "common/pch.hh"

#include "common/config/boolean.hh"

config::Boolean::Boolean(bool default_value) : m_value(default_value)
{
    // empty
}

const char* config::Boolean::rawGet(void) const
{
    return m_value ? VALUE_TRUE : VALUE_FALSE;
}

void config::Boolean::rawSet(const char* value)
{
    if(0 == std::strcmp(value, VALUE_TRUE)) {
        m_value = true;
    }
    else if(0 == std::strcmp(value, VALUE_FALSE)) {
        m_value = false;
    }
    else {
        // Just try to figure out if there is an integer
        // value passed (so 0 is false and everything else is true)
        m_value = static_cast<bool>(std::atoi(value));
    }
}

config::Boolean& config::Boolean::operator=(bool value)
{
    m_value = value;
    return *this;
}

config::Boolean::operator bool(void) const
{
    return m_value;
}
