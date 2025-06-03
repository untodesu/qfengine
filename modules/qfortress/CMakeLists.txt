include(QFengineModules)

qf_add_client_module(qfortress_client
    "${CMAKE_CURRENT_LIST_DIR}/client_module.cc"
    "${CMAKE_CURRENT_LIST_DIR}/client_pch.hh")
target_precompile_headers(qfortress_client PRIVATE "${CMAKE_CURRENT_LIST_DIR}/client_pch.hh")
