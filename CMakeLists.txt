cmake_minimum_required (VERSION 3.9)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)
option(COVERAGE "Compile for coveralls.io" OFF)

add_subdirectory(src)

include(CTest)
add_subdirectory(googletest-download)
add_subdirectory(tests)