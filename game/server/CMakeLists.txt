qf_add_static_library(server_game
    "${CMAKE_CURRENT_LIST_DIR}/pch.hh"
    "${PROJECT_BINARY_DIR}/generated_server_plugins.cc")
target_include_directories(server_game PRIVATE "${PROJECT_SOURCE_DIR}/game")
target_precompile_headers(server_game PRIVATE "${CMAKE_CURRENT_LIST_DIR}/pch.hh")
target_link_libraries(server_game PUBLIC qfengine_common shared_game)
