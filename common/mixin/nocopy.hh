#ifndef COMMON_MIXIN_NOCOPY_HH
#define COMMON_MIXIN_NOCOPY_HH
#pragma once

namespace mixin
{
class NoCopy {
public:
    NoCopy(void) = default;
    NoCopy(const NoCopy&) = delete;
    virtual ~NoCopy(void) = default;
    NoCopy& operator=(const NoCopy&) = delete;
};
} // namespace mixin

#endif // COMMON_MIXIN_NOCOPY_HH
