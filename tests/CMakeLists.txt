cmake_minimum_required (VERSION 3.9)
project(console_utilities_tests VERSION 0.1 LANGUAGES CXX)

file(GLOB SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

get_target_property(project_sources_dir console_utilities INTERFACE_INCLUDE_DIRECTORIES)
file(GLOB project_sources ${project_sources_dir}/*.h)
message(STATUS "${project_sources}")

add_executable(console_utilities_tests ${SOURCE_FILES} ${project_sources})

if (COVERAGE)
    target_compile_options(console_utilities_tests PRIVATE --coverage -g -O0) # debug, no optimisation
    set(coverage_linker_flag --coverage)
endif()

target_include_directories(console_utilities_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(console_utilities_tests   console_utilities 
                                                gtest_main
                                                ${coverage_linker_flag})

enable_testing()
add_test(console_utilities_tests console_utilities_tests)
                                                     
