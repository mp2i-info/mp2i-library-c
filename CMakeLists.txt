cmake_minimum_required(VERSION 3.15)

set(CMAKE_BUILD_TYPE Debug)

project(mp2i-library VERSION 1.0)

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

add_library(deque src/ds/deque/deque.c)
include_directories(src/ds/deque)

include(CTest)
enable_testing()
file(
	GLOB 
	tests
	tests/**/*.c
)

foreach(f ${tests})
  get_filename_component(exampleName ${f} NAME_WE) 
  add_executable (${exampleName} ${f}) 
  target_link_libraries(${exampleName} deque)
  add_test(NAME ${exampleName} COMMAND ${exampleName})
endforeach(f)
