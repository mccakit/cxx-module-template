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
set(CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../package/install")
set(ENV{PKG_CONFIG_LIBDIR} "${CMAKE_CURRENT_SOURCE_DIR}/../package/install/lib/pkgconfig")

option(package_type "cmake")
add_executable(main main.cpp)
if(package_type STREQUAL "cmake")
    find_package(math)
    target_link_libraries(main PRIVATE math::math)
elseif(package_type STREQUAL "pkgconfig")
    pkg_check_modules(math REQUIRED IMPORTED_TARGET math)
    target_link_libraries(main PRIVATE PkgConfig::math)
else()
    message(FATAL_ERROR "Unsupported package type")
endif()
