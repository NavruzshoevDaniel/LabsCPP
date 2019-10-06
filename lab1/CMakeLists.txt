cmake_minimum_required(VERSION 3.12)
project(lab1)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES main.cpp)

add_executable(Tritset_run ${SOURCE_FILES})

include_directories(Tritset)
add_subdirectory(Tritset)

target_link_libraries(Tritset_run Tritset)

add_subdirectory(Google_tests)