cmake_minimum_required(VERSION 3.12)
project(Lab2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab2 main.cpp Parser.cpp Parser.h  WorkFlow.h WorkFlow.cpp Commands/Dump.h Commands/Dump.cpp Commands/Grep.h Commands/Grep.cpp Commands/ReadFile.h Commands/ReadFile.cpp Commands/Replace.h Commands/Replace.cpp
        Commands/Sort.h Commands/Sort.cpp Commands/Worker.h Commands/WriteFile.h Commands/WriteFile.cpp Factory/BlockFactory.h Factory/BlockFactory.cpp Factory/Creator.h Factory/Creator.cpp Factory/ICreator.h Factory/SingletonInit.cpp)
