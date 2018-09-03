cmake_minimum_required (VERSION 3.9)
project(console_progress_bar_tests VERSION 0.1 LANGUAGES CXX)

file(GLOB SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

get_target_property(project_sources_dir console_progress_bar INTERFACE_INCLUDE_DIRECTORIES)
file(GLOB project_sources ${project_sources_dir}/*.h)
message(STATUS "${project_sources}")

add_executable(console_progress_bar_tests ${SOURCE_FILES} ${project_sources})

if (COVERAGE)
    target_compile_options(console_progress_bar_tests PRIVATE --coverage)
    set(coverage_linker_flag --coverage)
endif()

target_include_directories(console_progress_bar_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(console_progress_bar_tests console_progress_bar 
                                                 gtest_main
                                                 ${coverage_linker_flag})

enable_testing()
add_test(console_progress_bar_tests console_progress_bar_tests)
                                                     
