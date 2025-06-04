qf_add_module(example_server
    "${CMAKE_CURRENT_LIST_DIR}/example_server.cc"
    "${CMAKE_CURRENT_LIST_DIR}/example_pch.hh")
target_precompile_headers(example_server PRIVATE "${CMAKE_CURRENT_LIST_DIR}/example_pch.hh")
