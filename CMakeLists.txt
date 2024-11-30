cmake_minimum_required(VERSION 3.29)
project(ClimateChangeAnalysis)

set(CMAKE_CXX_STANDARD 20)

add_executable(ClimateChangeAnalysis main.cpp
        Menu.h
        ImportData.cpp
        ImportData.h
        Analysis.cpp
        Analysis.h
        Menu.cpp)
