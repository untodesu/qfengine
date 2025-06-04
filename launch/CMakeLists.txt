function(qf_add_launch_executable target_name)
    qf_add_executable(${target_name}
        "${CMAKE_CURRENT_SOURCE_DIR}/launch.cc"
        "${CMAKE_CURRENT_SOURCE_DIR}/launch.hh"
        "${CMAKE_CURRENT_SOURCE_DIR}/main_generic.cc"
        "${CMAKE_CURRENT_SOURCE_DIR}/main_win32.cc"
        "${CMAKE_CURRENT_SOURCE_DIR}/pch.hh")
    target_precompile_headers(${target_name} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/pch.hh")
    target_link_libraries(${target_name} PUBLIC qfengine_common)
endfunction()

qf_add_launch_executable(qf)
target_compile_definitions(qf PRIVATE QF_CLIENT)
target_link_libraries(qf PUBLIC client_game)

qf_add_launch_executable(qfds)
target_compile_definitions(qfds PRIVATE QF_SERVER)
target_link_libraries(qfds PUBLIC server_game)
