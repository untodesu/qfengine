qf_add_static_library(client_game
    "${CMAKE_CURRENT_LIST_DIR}/main.cc"
    "${CMAKE_CURRENT_LIST_DIR}/main.hh"
    "${CMAKE_CURRENT_LIST_DIR}/pch.hh"
    "${PROJECT_BINARY_DIR}/generated_client_modules.cc")
target_include_directories(client_game PRIVATE "${PROJECT_SOURCE_DIR}/game")
target_precompile_headers(client_game PRIVATE "${CMAKE_CURRENT_LIST_DIR}/pch.hh")
target_link_libraries(client_game PUBLIC qfengine_common shared_game)
