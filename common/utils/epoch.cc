#include "common/pch.hh"

#include "common/utils/epoch.hh"

std::uint64_t utils::unixSeconds(void)
{
    auto current = std::chrono::system_clock::now();
    auto time_since_epoch = current.time_since_epoch();
    return static_cast<std::uint64_t>(std::chrono::duration_cast<std::chrono::seconds>(time_since_epoch).count());
}

std::uint64_t utils::unixMilliseconds(void)
{
    auto current = std::chrono::system_clock::now();
    auto time_since_epoch = current.time_since_epoch();
    return static_cast<std::uint64_t>(std::chrono::duration_cast<std::chrono::milliseconds>(time_since_epoch).count());
}

std::uint64_t utils::unixMicroseconds(void)
{
    auto current = std::chrono::system_clock::now();
    auto time_since_epoch = current.time_since_epoch();
    return static_cast<std::uint64_t>(std::chrono::duration_cast<std::chrono::microseconds>(time_since_epoch).count());
}

std::int64_t utils::unixSecondsSigned(void)
{
    auto current = std::chrono::system_clock::now();
    auto time_since_epoch = current.time_since_epoch();
    return static_cast<std::int64_t>(std::chrono::duration_cast<std::chrono::seconds>(time_since_epoch).count());
}

std::int64_t utils::unixMillisecondsSigned(void)
{
    auto current = std::chrono::system_clock::now();
    auto time_since_epoch = current.time_since_epoch();
    return static_cast<std::int64_t>(std::chrono::duration_cast<std::chrono::milliseconds>(time_since_epoch).count());
}

std::int64_t utils::unixMicrosecondsSigned(void)
{
    auto current = std::chrono::system_clock::now();
    auto time_since_epoch = current.time_since_epoch();
    return static_cast<std::int64_t>(std::chrono::duration_cast<std::chrono::microseconds>(time_since_epoch).count());
}
