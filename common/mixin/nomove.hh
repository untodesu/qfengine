#ifndef COMMON_MIXIN_NOMOVE_HH
#define COMMON_MIXIN_NOMOVE_HH
#pragma once

namespace mixin
{
class NoMove {
public:
    NoMove(void) = default;
    NoMove(NoMove&&) = delete;
    virtual ~NoMove(void) = default;
    NoMove& operator=(NoMove&&) = delete;
};
} // namespace mixin

#endif // COMMON_MIXIN_NOMOVE_HH
