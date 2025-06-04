## Helper function to make a static library that is
## then linked into a game executable as a module
function(qf_add_module_base target_name)
endfunction()

set_property(GLOBAL PROPERTY QF_CLIENT_MODULES_DECL)
set_property(GLOBAL PROPERTY QF_CLIENT_MODULES_INVOKE)

set_property(GLOBAL PROPERTY QF_SERVER_MODULES_DECL)
set_property(GLOBAL PROPERTY QF_SERVER_MODULES_INVOKE)

set_property(GLOBAL PROPERTY QF_SHARED_MODULES_DECL)
set_property(GLOBAL PROPERTY QF_SHARED_MODULES_INVOKE)

function(qf_add_module target_name)
    qf_add_static_library(${target_name} ${ARGN})
    target_compile_definitions(${target_name} PRIVATE QF_MODULE)
    target_compile_definitions(${target_name} PRIVATE ${QF_MODULE_DEFINE})
    target_include_directories(${target_name} PRIVATE "${PROJECT_SOURCE_DIR}/game")
    target_include_directories(${target_name} PRIVATE "${PROJECT_SOURCE_DIR}/modules")

    ## Link the module library up with the dependent game library
    target_link_libraries(${target_name} PUBLIC ${QF_MODULE_LIBDEPEND})
    target_link_libraries(${QF_MODULE_LIBDEPEND} PUBLIC ${target_name})

    ## Add definitions for generated C++ sources
    set_property(GLOBAL APPEND PROPERTY ${QF_MODULE_DECL_LIST} "extern qf::Module ${target_name}")
    set_property(GLOBAL APPEND PROPERTY ${QF_MODULE_INVOKE_LIST} "${target_name}.invoke(callback)")
endfunction()

set(QF_MODULE_DEFINE "QF_CLIENT_MODULE")
set(QF_MODULE_DECL_LIST "QF_CLIENT_MODULES_DECL")
set(QF_MODULE_INVOKE_LIST "QF_CLIENT_MODULES_INVOKE")
set(QF_MODULE_LIBDEPEND "client_game")
add_subdirectory(client)

set(QF_MODULE_DEFINE "QF_SERVER_MODULE")
set(QF_MODULE_DECL_LIST "QF_SERVER_MODULES_DECL")
set(QF_MODULE_INVOKE_LIST "QF_SERVER_MODULES_INVOKE")
set(QF_MODULE_LIBDEPEND "server_game")
add_subdirectory(server)

set(QF_MODULE_DEFINE "QF_SHARED_MODULE")
set(QF_MODULE_DECL_LIST "QF_SHARED_MODULES_DECL")
set(QF_MODULE_INVOKE_LIST "QF_SHARED_MODULES_INVOKE")
set(QF_MODULE_LIBDEPEND "shared_game")
add_subdirectory(shared)

get_property(QF_CLIENT_MODULES_DECL GLOBAL PROPERTY QF_CLIENT_MODULES_DECL)
get_property(QF_CLIENT_MODULES_INVOKE GLOBAL PROPERTY QF_CLIENT_MODULES_INVOKE)

get_property(QF_SERVER_MODULES_DECL GLOBAL PROPERTY QF_SERVER_MODULES_DECL)
get_property(QF_SERVER_MODULES_INVOKE GLOBAL PROPERTY QF_SERVER_MODULES_INVOKE)

get_property(QF_SHARED_MODULES_DECL GLOBAL PROPERTY QF_SHARED_MODULES_DECL)
get_property(QF_SHARED_MODULES_INVOKE GLOBAL PROPERTY QF_SHARED_MODULES_INVOKE)

configure_file("${CMAKE_CURRENT_LIST_DIR}/templates/client_modules.cc.in" "${PROJECT_BINARY_DIR}/generated_client_modules.cc")
configure_file("${CMAKE_CURRENT_LIST_DIR}/templates/server_modules.cc.in" "${PROJECT_BINARY_DIR}/generated_server_modules.cc")
configure_file("${CMAKE_CURRENT_LIST_DIR}/templates/shared_modules.cc.in" "${PROJECT_BINARY_DIR}/generated_shared_modules.cc")
