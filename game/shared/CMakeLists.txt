qf_add_static_library(shared_game
    "${CMAKE_CURRENT_LIST_DIR}/game.cc"
    "${CMAKE_CURRENT_LIST_DIR}/game.hh"
    "${CMAKE_CURRENT_LIST_DIR}/gameinfo.cc"
    "${CMAKE_CURRENT_LIST_DIR}/gameinfo.hh"
    "${CMAKE_CURRENT_LIST_DIR}/globals.cc"
    "${CMAKE_CURRENT_LIST_DIR}/globals.hh"
    "${CMAKE_CURRENT_LIST_DIR}/pch.hh")
target_precompile_headers(shared_game PRIVATE "${CMAKE_CURRENT_LIST_DIR}/pch.hh")
target_sources(shared_game PRIVATE "${PROJECT_BINARY_DIR}/generated_shared_modules.cc")
target_include_directories(shared_game PRIVATE "${PROJECT_SOURCE_DIR}/game")
target_link_libraries(shared_game PUBLIC qfengine_common)
target_link_libraries(shared_game PUBLIC entt)
