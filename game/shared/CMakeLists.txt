include(QFengineProjects)

qf_add_static_library(shared_game
    "${CMAKE_CURRENT_LIST_DIR}/sharedmodule.cc"
    "${CMAKE_CURRENT_LIST_DIR}/sharedmodule.hh"
    "${CMAKE_CURRENT_LIST_DIR}/pch.hh")
target_include_directories(shared_game PRIVATE "${PROJECT_SOURCE_DIR}/game")
target_precompile_headers(shared_game PRIVATE "${CMAKE_CURRENT_LIST_DIR}/pch.hh")
target_link_libraries(shared_game PUBLIC qfengine_common)
