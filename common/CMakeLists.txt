qf_add_static_library(qfengine_common
    "${CMAKE_CURRENT_LIST_DIR}/config/boolean.cc"
    "${CMAKE_CURRENT_LIST_DIR}/config/boolean.hh"
    "${CMAKE_CURRENT_LIST_DIR}/config/map.cc"
    "${CMAKE_CURRENT_LIST_DIR}/config/map.hh"
    "${CMAKE_CURRENT_LIST_DIR}/config/number.hh"
    "${CMAKE_CURRENT_LIST_DIR}/config/string.cc"
    "${CMAKE_CURRENT_LIST_DIR}/config/string.hh"
    "${CMAKE_CURRENT_LIST_DIR}/config/value.hh"
    "${CMAKE_CURRENT_LIST_DIR}/debug/assert.hh"
    "${CMAKE_CURRENT_LIST_DIR}/utils/crc64.cc"
    "${CMAKE_CURRENT_LIST_DIR}/utils/crc64.hh"
    "${CMAKE_CURRENT_LIST_DIR}/utils/epoch.cc"
    "${CMAKE_CURRENT_LIST_DIR}/utils/epoch.hh"
    "${CMAKE_CURRENT_LIST_DIR}/utils/string.cc"
    "${CMAKE_CURRENT_LIST_DIR}/utils/string.hh"
    "${CMAKE_CURRENT_LIST_DIR}/commandline.cc"
    "${CMAKE_CURRENT_LIST_DIR}/commandline.hh"
    "${CMAKE_CURRENT_LIST_DIR}/module.cc"
    "${CMAKE_CURRENT_LIST_DIR}/module.hh"
    "${CMAKE_CURRENT_LIST_DIR}/pch.hh")
target_precompile_headers(qfengine_common PUBLIC "${CMAKE_CURRENT_LIST_DIR}/pch.hh")
target_link_libraries(qfengine_common PUBLIC eigen spdlog)
