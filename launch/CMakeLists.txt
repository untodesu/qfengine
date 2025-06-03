function(add_launch_executable target_name)
    add_executable(${target_name}
        "${CMAKE_CURRENT_SOURCE_DIR}/launch.cc"
        "${CMAKE_CURRENT_SOURCE_DIR}/launch.hh"
        "${CMAKE_CURRENT_SOURCE_DIR}/main_generic.cc"
        "${CMAKE_CURRENT_SOURCE_DIR}/main_win32.cc"
        "${CMAKE_CURRENT_SOURCE_DIR}/pch.hh")
    target_compile_features(${target_name} PUBLIC cxx_std_20)
    set_target_properties(${TARGET_NAME} PROPERTIES WIN32_EXECUTABLE TRUE)
    target_include_directories(${target_name} PUBLIC "${PROJECT_SOURCE_DIR}")
    target_precompile_headers(${target_name} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/pch.hh")
    target_link_libraries(${target_name} PUBLIC common)
endfunction(add_launch_executable)

add_launch_executable(qf)
target_compile_definitions(qf PRIVATE QF_CLIENT)

add_launch_executable(qf_server)
target_compile_definitions(qf_server PRIVATE QF_SERVER)
