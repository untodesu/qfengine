add_library(common STATIC
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
    "${CMAKE_CURRENT_LIST_DIR}/pch.hh")
target_compile_features(common PUBLIC cxx_std_20)
target_include_directories(common PUBLIC "${PROJECT_SOURCE_DIR}")
target_precompile_headers(common PUBLIC "${CMAKE_CURRENT_LIST_DIR}/pch.hh")
target_link_libraries(common PUBLIC eigen spdlog)

if(WIN32)
    target_compile_definitions(common PUBLIC _CRT_SECURE_NO_WARNINGS)
    target_compile_definitions(common PUBLIC _USE_MATH_DEFINES)
    target_compile_definitions(common PUBLIC NOMINMAX)
endif()

if(MSVC)
    target_compile_options(common PUBLIC /utf-8)
endif()
