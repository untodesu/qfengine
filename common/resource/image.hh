#ifndef COMMON_RESOURCE_IMAGE_HH
#define COMMON_RESOURCE_IMAGE_HH
#pragma once

#include "common/mixin/nocopy.hh"

namespace resource
{
class Image final : public mixin::NoCopy {
public:
    explicit Image(void) = default;
    explicit Image(const std::filesystem::path& path);
    virtual ~Image(void) override;

    bool load(const std::filesystem::path& path);
    bool isValid(void) const;
    void unload(void);

    int getWidth(void) const;
    int getHeight(void) const;

    const std::byte* getPixels(void) const;

private:
    Eigen::Vector2i m_size { 0, 0 };
    std::byte* m_pixels { nullptr };
};
} // namespace resource

#endif // COMMON_RESOURCE_IMAGE_HH
