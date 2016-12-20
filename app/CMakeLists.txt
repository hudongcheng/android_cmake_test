# Sets the minimum version of CMake required to build the native
# library. You should either keep the default value or only pass a
# value of 3.4.0 or lower.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds it for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             # Associated headers in the same location as their source
             # file are automatically included.
             src/main/cpp/native-lib.cpp )

add_library(my-add
    SHARED
    src/main/cpp/my-add/my-add.cpp)

include_directories(src/main/cpp/my-add/)


#add_library(imported-lib
#    SHARED
#    imported-lib/import-lib.c )

add_library(imported-lib
    SHARED
    IMPORTED GLOBAL)

set_target_properties( imported-lib
                       PROPERTIES IMPORTED_LOCATION
                       ${CMAKE_CURRENT_LIST_DIR}/imported-lib/libimported-lib.so )

include_directories(imported-lib/)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because system libraries are included in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( log-lib
              log )

find_library( graphics-lib
              jnigraphics )

add_subdirectory( sublibs )
include_directories( sublibs )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in the
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       native-lib

                       # Links the target library to the log library
                       # included in the NDK.
                       #my-add
                       #imported-lib
                       add1
                       add2
                       #${graphics-lib}
                       ${log-lib} )
