cmake_minimum_required (VERSION 3.9)
project(console_progress_bar VERSION 0.1 LANGUAGES CXX)

set(HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/ArchitectureAnalyzer.h)

add_library(console_progress_bar INTERFACE)


target_include_directories(console_progress_bar INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
                                                     
