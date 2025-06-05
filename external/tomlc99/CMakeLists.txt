add_library(tomlc99 STATIC
    "${CMAKE_CURRENT_LIST_DIR}/include/toml.h"
    "${CMAKE_CURRENT_LIST_DIR}/src/toml.c")
target_compile_features(tomlc99 PUBLIC c_std_99)
target_include_directories(tomlc99 PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include")
