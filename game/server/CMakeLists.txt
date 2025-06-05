qf_add_static_library(server_game
    "${CMAKE_CURRENT_LIST_DIR}/pch.hh")
target_precompile_headers(server_game PRIVATE "${CMAKE_CURRENT_LIST_DIR}/pch.hh")
target_sources(server_game PRIVATE "${PROJECT_BINARY_DIR}/generated_server_modules.cc")
target_include_directories(server_game PRIVATE "${PROJECT_SOURCE_DIR}/game")
target_link_libraries(server_game PUBLIC qfengine_common shared_game)
