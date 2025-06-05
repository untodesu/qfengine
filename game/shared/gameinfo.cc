#include "shared/pch.hh"

#include "shared/gameinfo.hh"

#include "common/commandline.hh"
#include "common/debug/assert.hh"
#include "common/utils/physfs.hh"
#include "common/utils/string.hh"

std::filesystem::path gameinfo::directory;
std::string gameinfo::game_name;
std::string gameinfo::game_author;

static std::filesystem::path makePath(const std::string& path)
{
    static const std::unordered_map<std::string, std::string> variables = {
        { "${CURRDIR}", std::filesystem::current_path().string() },
        { "${GAMEDIR}", gameinfo::directory.string() },
    };

    return std::filesystem::path(utils::replaceMap(path, variables));
}

void gameinfo::initializeEarly(void)
{
    gameinfo::directory = commandline::getOption("game", std::filesystem::current_path().string().c_str());
    spdlog::info("gameinfo: setting game directory to {}", gameinfo::directory.string());

    std::string toml_source;
    std::filesystem::path toml_path(gameinfo::directory / "gameinfo.toml");

    auto toml_file = std::fopen(toml_path.string().c_str(), "r");
    qf_force_assert_fmt(toml_file, "gameinfo: {}: {}", toml_path.string(), std::strerror(errno));

    char toml_error[4096];
    auto toml = toml_parse_file(toml_file, toml_error, sizeof(toml_error));
    qf_force_assert_fmt(toml, "gameinfo: {}: parse error: {}", toml_path.string(), toml_error);

    std::fclose(toml_file);

    auto toml_game = toml_string_in(toml, "game");
    qf_assert(toml_game.ok);

    auto toml_author = toml_string_in(toml, "author");
    qf_assert(toml_author.ok);

    gameinfo::game_name = toml_game.u.s;
    gameinfo::game_author = toml_author.u.s;

    auto toml_filesystem = toml_table_in(toml, "filesystem");
    qf_assert(toml_filesystem);

    auto toml_write_location = toml_string_in(toml_filesystem, "write_location");
    qf_assert(toml_write_location.ok);

    auto toml_search_paths = toml_array_in(toml_filesystem, "search_paths");
    qf_assert(toml_search_paths);

    auto write_location = makePath(toml_write_location.u.s);
    auto write_location_ok = PHYSFS_setWriteDir(write_location.string().c_str());
    qf_force_assert_fmt(write_location_ok, "gameinfo: cannot set write_dir: {}: {}", write_location.string(), utils::getPhysfsError());

    auto num_search_paths = toml_array_nelem(toml_search_paths);
    qf_assert(num_search_paths >= 0);

    for(std::size_t i = 0; i < num_search_paths; ++i) {
        auto toml_search_path = toml_string_at(toml_search_paths, i);
        qf_assert(toml_search_path.ok);

        auto search_path = makePath(toml_search_path.u.s);
        auto search_path_ok = PHYSFS_mount(search_path.string().c_str(), nullptr, false);

        if(!search_path_ok) {
            // Not a death sentence; the engine might just crash if it fails to locate a resource though
            spdlog::warn("gameinfo: cannot mount: {}: {}", search_path.string(), utils::getPhysfsError());
            continue;
        }
    }

    write_location_ok = PHYSFS_mount(write_location.string().c_str(), nullptr, true);
    qf_force_assert_fmt(write_location_ok, "gameinfo: cannot mount: {}: {}", write_location.string(), utils::getPhysfsError());

    toml_free(toml);
}
