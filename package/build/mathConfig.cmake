
add_library(math::math STATIC IMPORTED)
set_target_properties(math::math PROPERTIES
  IMPORTED_LOCATION "/home/mccakit/desktop/cxx20modules_packaging/package/install/lib/libmath.a"
  INTERFACE_COMPILE_OPTIONS "-fprebuilt-module-path=/home/mccakit/desktop/cxx20modules_packaging/package/install/lib/cxx/bmi"
)
