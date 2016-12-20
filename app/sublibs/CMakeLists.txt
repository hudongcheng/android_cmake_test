# Sets the minimum version of CMake required to build the native
# library. You should either keep the default value or only pass a
# value of 3.4.0 or lower.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds it for you.
# Gradle automatically packages shared libraries with your APK.


#add_library( add1
#    STATIC
#    ${CMAKE_CURRENT_LIST_DIR}/add1.c )

#add_library( add2
#    STATIC
#    ${CMAKE_CURRENT_LIST_DIR}/add2.c)

include_directories(./)


add_library(add1
    STATIC
    IMPORTED GLOBAL)
set_target_properties( add1
                       PROPERTIES IMPORTED_LOCATION
                       ${CMAKE_CURRENT_LIST_DIR}/libadd1.a )

add_library(add2
    STATIC
    IMPORTED GLOBAL)
set_target_properties( add2
                       PROPERTIES IMPORTED_LOCATION
                       ${CMAKE_CURRENT_LIST_DIR}/libadd2.a )
