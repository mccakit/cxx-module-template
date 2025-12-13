cmake_minimum_required(VERSION 4.2)
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")
set(CMAKE_CXX_MODULE_STD ON)
project(
    math
    VERSION 1.0
    DESCRIPTION "Lmao"
    LANGUAGES C CXX
)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
add_library(math STATIC)
target_sources(math PUBLIC FILE_SET CXX_MODULES FILES math.cppm)
install(TARGETS math
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    CXX_MODULES_BMI DESTINATION ${CMAKE_INSTALL_LIBDIR}/cxx/bmi
)
configure_file(mathConfig.cmake.in mathConfig.cmake @ONLY)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/mathConfig.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/math
)
configure_file(math.pc.in math.pc @ONLY)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/math.pc
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig
)
