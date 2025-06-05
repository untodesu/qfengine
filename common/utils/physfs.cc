#include "common/pch.hh"

#include "common/utils/physfs.hh"

const char* utils::getPhysfsError(void)
{
    return PHYSFS_getErrorByCode(PHYSFS_getLastErrorCode());
}

bool utils::readFileString(const std::filesystem::path& path, std::string& buffer)
{
    if(auto file = PHYSFS_openRead(path.string().c_str())) {
        buffer.resize(PHYSFS_fileLength(file));
        PHYSFS_readBytes(file, buffer.data(), buffer.size());
        PHYSFS_close(file);
        return true;
    }

    return false;
}

bool utils::writeFileString(const std::filesystem::path& path, const std::string& buffer)
{
    if(auto file = PHYSFS_openWrite(path.string().c_str())) {
        PHYSFS_writeBytes(file, buffer.data(), buffer.size());
        PHYSFS_close(file);
        return true;
    }

    return false;
}

bool utils::writeFileStringAppend(const std::filesystem::path& path, const std::string& buffer)
{
    if(auto file = PHYSFS_openAppend(path.string().c_str())) {
        PHYSFS_writeBytes(file, buffer.data(), buffer.size());
        PHYSFS_close(file);
        return true;
    }

    return false;
}

bool utils::readFileBytes(const std::filesystem::path& path, std::vector<std::byte>& buffer)
{
    if(auto file = PHYSFS_openRead(path.string().c_str())) {
        buffer.resize(PHYSFS_fileLength(file));
        PHYSFS_readBytes(file, buffer.data(), buffer.size());
        PHYSFS_close(file);
        return true;
    }

    return false;
}

bool utils::writeFileBytes(const std::filesystem::path& path, const std::vector<std::byte>& buffer)
{
    if(auto file = PHYSFS_openWrite(path.string().c_str())) {
        PHYSFS_writeBytes(file, buffer.data(), buffer.size());
        PHYSFS_close(file);
        return true;
    }

    return false;
}

bool utils::writeFileBytesAppend(const std::filesystem::path& path, const std::vector<std::byte>& buffer)
{
    if(auto file = PHYSFS_openAppend(path.string().c_str())) {
        PHYSFS_writeBytes(file, buffer.data(), buffer.size());
        PHYSFS_close(file);
        return true;
    }

    return false;
}

bool utils::readFileStream(const std::filesystem::path& path, std::istringstream& stream)
{
    std::string source;

    if(utils::readFileString(path, source)) {
        stream.str(source);
        return true;
    }

    return false;
}

bool utils::writeFileStream(const std::filesystem::path& path, const std::ostringstream& stream)
{
    return utils::writeFileString(path, stream.str());
}

bool utils::writeFileStreamAppend(const std::filesystem::path& path, const std::ostringstream& stream)
{
    return utils::writeFileStringAppend(path, stream.str());
}
