cmake_minimum_required(VERSION 3.21)
project(Yadro_test_task)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib)

add_executable(Yadro_test_task main.cpp)

target_link_libraries(Yadro_test_task PRIVATE lib)
target_include_directories(Yadro_test_task PRIVATE lib)
