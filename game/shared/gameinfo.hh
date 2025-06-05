#ifndef SHARED_GAMEINFO_HH
#define SHARED_GAMEINFO_HH
#pragma once

namespace gameinfo
{
extern std::filesystem::path directory;
extern std::string game_name;
extern std::string game_author;
} // namespace gameinfo

namespace gameinfo
{
void initializeEarly(void);
} // namespace gameinfo

#endif // SHARED_GAMEINFO_HH
