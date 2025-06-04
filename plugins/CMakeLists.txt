## Helper function to make a static library that is
## then linked into a game executable as a plugin
function(qf_add_plugin_base target_name)
endfunction()

set_property(GLOBAL PROPERTY QF_CLIENT_PLUGINS_DECL)
set_property(GLOBAL PROPERTY QF_CLIENT_PLUGINS_INVOKE)

set_property(GLOBAL PROPERTY QF_SERVER_PLUGINS_DECL)
set_property(GLOBAL PROPERTY QF_SERVER_PLUGINS_INVOKE)

set_property(GLOBAL PROPERTY QF_SHARED_PLUGINS_DECL)
set_property(GLOBAL PROPERTY QF_SHARED_PLUGINS_INVOKE)

function(qf_add_plugin target_name)
    qf_add_static_library(${target_name} ${ARGN})
    target_compile_definitions(${target_name} PRIVATE QF_PLUGIN)
    target_compile_definitions(${target_name} PRIVATE ${QF_PLUGIN_DEFINE})
    target_include_directories(${target_name} PRIVATE "${PROJECT_SOURCE_DIR}/game")
    target_include_directories(${target_name} PRIVATE "${PROJECT_SOURCE_DIR}/plugins")

    ## Link the plugin library up with the dependent game library
    target_link_libraries(${target_name} PUBLIC ${QF_PLUGIN_LIBDEPEND})
    target_link_libraries(${QF_PLUGIN_LIBDEPEND} PUBLIC ${target_name})

    ## Add definitions for generated C++ sources
    set_property(GLOBAL APPEND PROPERTY ${QF_PLUGIN_DECL_LIST} "extern qf::Plugin ${target_name}")
    set_property(GLOBAL APPEND PROPERTY ${QF_PLUGIN_INVOKE_LIST} "${target_name}.invoke(callback)")
endfunction()

set(QF_PLUGIN_DEFINE "QF_CLIENT_PLUGIN")
set(QF_PLUGIN_DECL_LIST "QF_CLIENT_PLUGINS_DECL")
set(QF_PLUGIN_INVOKE_LIST "QF_CLIENT_PLUGINS_INVOKE")
set(QF_PLUGIN_LIBDEPEND "client_game")
add_subdirectory(client)

set(QF_PLUGIN_DEFINE "QF_SERVER_PLUGIN")
set(QF_PLUGIN_DECL_LIST "QF_SERVER_PLUGINS_DECL")
set(QF_PLUGIN_INVOKE_LIST "QF_SERVER_PLUGINS_INVOKE")
set(QF_PLUGIN_LIBDEPEND "server_game")
add_subdirectory(server)

set(QF_PLUGIN_DEFINE "QF_SHARED_PLUGIN")
set(QF_PLUGIN_DECL_LIST "QF_SHARED_PLUGINS_DECL")
set(QF_PLUGIN_INVOKE_LIST "QF_SHARED_PLUGINS_INVOKE")
set(QF_PLUGIN_LIBDEPEND "shared_game")
add_subdirectory(shared)

get_property(QF_CLIENT_PLUGINS_DECL GLOBAL PROPERTY QF_CLIENT_PLUGINS_DECL)
get_property(QF_CLIENT_PLUGINS_INVOKE GLOBAL PROPERTY QF_CLIENT_PLUGINS_INVOKE)

get_property(QF_SERVER_PLUGINS_DECL GLOBAL PROPERTY QF_SERVER_PLUGINS_DECL)
get_property(QF_SERVER_PLUGINS_INVOKE GLOBAL PROPERTY QF_SERVER_PLUGINS_INVOKE)

get_property(QF_SHARED_PLUGINS_DECL GLOBAL PROPERTY QF_SHARED_PLUGINS_DECL)
get_property(QF_SHARED_PLUGINS_INVOKE GLOBAL PROPERTY QF_SHARED_PLUGINS_INVOKE)

configure_file("${CMAKE_CURRENT_LIST_DIR}/templates/client_plugins.cc.in" "${PROJECT_BINARY_DIR}/generated_client_plugins.cc")
configure_file("${CMAKE_CURRENT_LIST_DIR}/templates/server_plugins.cc.in" "${PROJECT_BINARY_DIR}/generated_server_plugins.cc")
configure_file("${CMAKE_CURRENT_LIST_DIR}/templates/shared_plugins.cc.in" "${PROJECT_BINARY_DIR}/generated_shared_plugins.cc")
