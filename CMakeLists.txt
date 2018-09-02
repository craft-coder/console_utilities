cmake_minimum_required (VERSION 3.9)

add_subdirectory(src)

include(CTest)
add_subdirectory(googletest-download)
add_subdirectory(tests)