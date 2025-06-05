qf_add_static_library(render_gl
    "${CMAKE_CURRENT_LIST_DIR}/render_gl.cc"
    "${CMAKE_CURRENT_LIST_DIR}/pch.hh")
target_precompile_headers(render_gl PRIVATE "${CMAKE_CURRENT_LIST_DIR}/pch.hh")
target_include_directories(render_gl PRIVATE "${PROJECT_SOURCE_DIR}/game")
target_link_libraries(render_gl PRIVATE client_game)
add_library(render_impl ALIAS render_gl)
