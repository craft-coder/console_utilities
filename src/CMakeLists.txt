cmake_minimum_required (VERSION 3.9)
project(console_utilities VERSION 0.1 LANGUAGES CXX)

set(HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

add_library(console_utilities INTERFACE)


target_include_directories(console_utilities INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
                                                     
