cmake_minimum_required(VERSION 3.22)
project(Rubik__s_cube)

set(CMAKE_CXX_STANDARD 17)

add_executable(Rubik__s_cube main.cpp CSmallCube.cpp CSmallCube.h AssemblingRubiksCube.cpp AssemblingRubiksCube.h CRubicsCube.cpp CRubicsCube.h)
