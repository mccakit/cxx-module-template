cmake_minimum_required(VERSION 4.2)
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")
set(CMAKE_CXX_MODULE_STD ON)
project(
    copy
    VERSION 1.0
    DESCRIPTION "Lmao"
    LANGUAGES C CXX
)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
add_library(copy STATIC)
target_sources(copy PUBLIC FILE_SET CXX_MODULES FILES copy.cppm)
install(TARGETS copy
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    CXX_MODULES_BMI DESTINATION ${CMAKE_INSTALL_LIBDIR}/cxx/bmi
)
configure_file(copyConfig.cmake.in copyConfig.cmake @ONLY)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/copyConfig.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/copy
)
configure_file(copy.pc.in copy.pc @ONLY)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/copy.pc
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig
)
