# 'Google_test' is the subproject name
project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib/googletest )
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR};/Users/daniel/CLionProjects/GitHub/LabsCPP/lab1)


# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(Google_Tests_run test1.cpp)
target_link_libraries(Google_Tests_run Tritset)
target_link_libraries(Google_Tests_run gtest gtest_main)




