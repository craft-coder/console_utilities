cmake_minimum_required (VERSION 3.9)
project(console_progress_bar_tests VERSION 0.1 LANGUAGES CXX)

set(SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/console_progress_bar_tests.cpp)

add_executable(console_progress_bar_tests ${SOURCE_FILES})

target_include_directories(console_progress_bar_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(console_progress_bar_tests console_progress_bar)

enable_testing()
add_test(console_progress_bar_tests console_progress_bar_tests)
                                                     
