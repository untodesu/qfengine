cmake_minimum_required(VERSION 3.19 FATAL_ERROR)
project(QFengine LANGUAGES C CXX VERSION 0.0.1)

set(QF_RENDERER_VARIANTS GL VK)
set(QF_RENDERER GL CACHE STRING "QFengine rendering implementation")
set_property(CACHE QF_RENDERER PROPERTY STRINGS ${QF_RENDERER_VARIANTS})

## Add cmake include directories
list(APPEND CMAKE_MODULE_PATH "cmake")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## If possible, enable solution directories; this allows
## built-in pseudotargets like ALL_BUILD and ZERO_CHECK to
## be moved out of sight into a separate directory
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

## Ensure we are never building dependencies as dynamic
## libraries; we only use dynamic libraries for non-compiled
## third-party dependencies (such as SDL3 and maybe Discord-RPC);
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build shared libraries" FORCE)

## Microsoft-vendored STL has been permissively licensed for quite
## a while, so it makes all the sense to statically link with it to
## avoid pulling redistributable installers alongside the game package
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

## Output binaries into build root
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

## Helper function to figure out common things across
## all the targets in the entire engine's infrastructure
function(qf_setup_target target_name)
    target_compile_features(${target_name} PUBLIC cxx_std_20)
    target_include_directories(${target_name} PUBLIC "${PROJECT_SOURCE_DIR}")
    
    if(WIN32)
        target_compile_definitions(${target_name} PUBLIC _CRT_SECURE_NO_WARNINGS)
        target_compile_definitions(${target_name} PUBLIC _USE_MATH_DEFINES)
        target_compile_definitions(${target_name} PUBLIC NOMINMAX)
    endif()
endfunction()

## Helper function to make executables
function(qf_add_executable target_name)
    add_executable(${target_name} ${ARGN})
    qf_setup_target(${target_name})
endfunction()

## Helper function to make shared libraries
function(qf_add_shared_library target_name)
    add_library(${target_name} SHARED ${ARGN})
    target_compile_definitions(${target_name} PRIVATE QF_BUILD_DLL)
    qf_setup_target(${target_name})
endfunction()

## Helper function to make static libraries
function(qf_add_static_library target_name)
    add_library(${target_name} STATIC ${ARGN})
    target_compile_definitions(${target_name} PRIVATE QF_BUILD_LIB)
    qf_setup_target(${target_name})
endfunction()

## Add dependencies
add_subdirectory(external)

## Add common engine sources
add_subdirectory(common)

## Add game sources
add_subdirectory(game/client)
add_subdirectory(game/server)
add_subdirectory(game/shared)

if(QF_RENDERER STREQUAL GL)
    ## Add OpenGL rendering implementation
    add_subdirectory(render_gl)
elseif(QF_RENDERER STREQUAL VK)
    ## Add Vulkan rendering implementation
    add_subdirectory(render_vk)
else()
    ## Whoops, it wasn't configured correctly!
    message(FATAL_ERROR "Unknown rendering implementation: ${QF_RENDERER}")
endif()

## Add engine modules
add_subdirectory(modules)

## Add launcher sources
add_subdirectory(launch)

install(DIRECTORY "${PROJECT_SOURCE_DIR}/baseqf" DESTINATION ".")
install(FILES "${PROJECT_SOURCE_DIR}/gameinfo.yml" DESTINATION ".")

set(CPACK_PACKAGE_NAME "qfengine")
set(CPACK_PACKAGE_VENDOR "untodesu")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Engine for a class-based first-person shooter")
set(CPACK_PACKAGE_CONTACT "https://github.com/untodesu/qfengine/issues")

set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
set(CPACK_PACKAGE_VERSION_TWEAK ${PROJECT_VERSION_TWEAK})

set(CPACK_PACKAGE_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "${CPACK_PACKAGE_NAME}")

include(CPack)
