#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "unofficial::argon2::libargon2" for configuration "Debug"
set_property(TARGET unofficial::argon2::libargon2 APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(unofficial::argon2::libargon2 PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/debug/lib/argon2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/debug/bin/argon2.dll"
  )

list(APPEND _cmake_import_check_targets unofficial::argon2::libargon2 )
list(APPEND _cmake_import_check_files_for_unofficial::argon2::libargon2 "${_IMPORT_PREFIX}/debug/lib/argon2.lib" "${_IMPORT_PREFIX}/debug/bin/argon2.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
