qf_add_module(example_shared
    "${CMAKE_CURRENT_LIST_DIR}/example_shared.cc"
    "${CMAKE_CURRENT_LIST_DIR}/example_pch.hh")
target_precompile_headers(example_shared PRIVATE "${CMAKE_CURRENT_LIST_DIR}/example_pch.hh")
