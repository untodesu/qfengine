qf_add_plugin(example_shared
    "${CMAKE_CURRENT_LIST_DIR}/example_shared.cc"
    "${CMAKE_CURRENT_LIST_DIR}/example_pch.hh")
target_precompile_headers(example_shared PRIVATE "${CMAKE_CURRENT_LIST_DIR}/example_pch.hh")
