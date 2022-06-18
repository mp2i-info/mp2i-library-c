cmake_minimum_required(VERSION 3.15)

set(CMAKE_BUILD_TYPE Release)

project(mp2i-library VERSION 1.0)

add_subdirectory(src)

add_executable(Main src/main.c)
target_link_libraries(Main PUBLIC deque)
target_include_directories(Main PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/src/ds"
                          )
