set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
cmake_minimum_required(VERSION 4.2)
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")
set(CMAKE_CXX_MODULE_STD ON)
project(
    consumes_math
    VERSION 1.0
    DESCRIPTION "Lmao"
    LANGUAGES C CXX
)
find_package(PkgConfig REQUIRED)
list(APPEND CMAKE_PREFIX_PATH
    "${CMAKE_CURRENT_SOURCE_DIR}/../package1/install"
    "${CMAKE_CURRENT_SOURCE_DIR}/../package2/install"
)
set(PKGCONF_PREFIX_PATH
    "${CMAKE_CURRENT_SOURCE_DIR}/../package1/install/lib/pkgconfig"
    "${CMAKE_CURRENT_SOURCE_DIR}/../package2/install/lib/pkgconfig"
)
set(ENV{PKG_CONFIG_LIBDIR} "${PKGCONF_PREFIX_PATH}:ENV{PKG_CONFIG_LIBDIR}")
option(package_type "cmake")
add_executable(main main.cpp)
if(package_type STREQUAL "cmake")
    find_package(math)
    find_package(copy)
    target_link_libraries(main PRIVATE math::math math::math2 copy::copy)
elseif(package_type STREQUAL "pkgconfig" OR package_type STREQUAL "pkgconf")
    pkg_check_modules(math REQUIRED IMPORTED_TARGET math)
    pkg_check_modules(copy REQUIRED IMPORTED_TARGET copy)
    target_link_libraries(main PRIVATE PkgConfig::math PkgConfig::copy)
else()
    message(FATAL_ERROR "Unsupported package type")
endif()
