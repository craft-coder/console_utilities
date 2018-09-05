cmake_minimum_required (VERSION 3.9)
project(example VERSION 0.1 LANGUAGES CXX)

file(GLOB SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(example ${SOURCE_FILES})

target_link_libraries(example console_progress_bar )

