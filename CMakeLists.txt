cmake_minimum_required(VERSION 3.10)
project(hack_assembler)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)

add_executable(hack_assembler
        src/config.hpp
        src/hack_assembler.cpp
        src/instruction.cpp
        src/instruction.hpp
        src/label.cpp
        src/label.hpp)
