#include "common/pch.hh"

#include "common/resource/image.hh"

#include "common/debug/assert.hh"
#include "common/utils/physfs.hh"

resource::Image::Image(const std::filesystem::path& path)
{
    qf_force_assert(load(path));
}

resource::Image::~Image(void)
{
    unload();
}

bool resource::Image::load(const std::filesystem::path& path)
{
    unload();

    std::vector<std::byte> buffer;

    if(utils::readFileBytes(path, buffer)) {
        auto buffer_ptr = reinterpret_cast<const stbi_uc*>(buffer.data());
        auto pixels_ptr = stbi_load_from_memory(buffer_ptr, static_cast<int>(buffer.size()), &m_size.x(), &m_size.y(), nullptr, STBI_rgb_alpha);

        if(pixels_ptr == nullptr) {
            spdlog::warn("Image: {}: {}", path.string(), stbi_failure_reason());
            m_pixels = nullptr;
            m_size.setZero();
            return false;
        }

        m_pixels = reinterpret_cast<std::byte*>(pixels_ptr);

        return true;
    }

    spdlog::warn("Image: {}: {}", path.string(), utils::getPhysfsError());
    m_pixels = nullptr;
    m_size.setZero();
    return false;
}

bool resource::Image::isValid(void) const
{
    return m_pixels != nullptr;
}

void resource::Image::unload(void)
{
    if(m_pixels != nullptr) {
        stbi_image_free(m_pixels);
        m_pixels = nullptr;
    }

    m_size.setZero();
}

int resource::Image::getWidth(void) const
{
    return m_size.x();
}

int resource::Image::getHeight(void) const
{
    return m_size.y();
}

const std::byte* resource::Image::getPixels(void) const
{
    return m_pixels;
}
