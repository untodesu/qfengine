qf_add_module(example_client
    "${CMAKE_CURRENT_LIST_DIR}/example_client.cc"
    "${CMAKE_CURRENT_LIST_DIR}/example_pch.hh")
target_precompile_headers(example_client PRIVATE "${CMAKE_CURRENT_LIST_DIR}/example_pch.hh")
