qf_add_static_library(render_vk
    "${CMAKE_CURRENT_LIST_DIR}/render_vk.cc"
    "${CMAKE_CURRENT_LIST_DIR}/pch.hh")
target_precompile_headers(render_vk PRIVATE "${CMAKE_CURRENT_LIST_DIR}/pch.hh")
target_include_directories(render_vk PRIVATE "${PROJECT_SOURCE_DIR}/game")
target_link_libraries(render_vk PRIVATE client_game)
add_library(render_impl ALIAS render_vk)
