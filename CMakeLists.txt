cmake_minimum_required(VERSION 3.5)

project ( FieldValue )

set ( CMAKE_C_STANDARD 99 )
set ( CMAKE_CXX_STANDARD 17 )
set ( CMAKE_C_FLAGS "-Wall -Wextra -Werror -g3 -o0" )
set ( CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -g3 -o0" )

include_directories (
     include
     )

set (fieldvalue_libsources
     src/field/threshold.c
     include/field/threshold.h
     src/field/range.c
     include/field/range.h
     )

add_library ( fieldvalue
    ${fieldvalue_libsources}
     )

