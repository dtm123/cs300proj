cmake_minimum_required(VERSION 3.29)
project(ClimateChangeAnalysis)

set(CMAKE_CXX_STANDARD 20)

add_executable(ClimateChangeAnalysis main.cpp
        Menu.h
        Analysis.cpp
        Analysis.h
        Menu.cpp)



# Manually set the path to the Python installation if needed
set(Python3_EXECUTABLE "C:/Users/adamr/AppData/Local/Programs/Python/Python312/python.exe")
set(Python3_INCLUDE_DIR "C:/Users/adamr/AppData/Local/Programs/Python/Python312/include")
set(Python3_LIBRARIES "C:/Users/adamr/AppData/Local/Programs/Python/Python312/libs/python312.lib")

# Include Python headers
include_directories(${Python3_INCLUDE_DIR})

# Include NumPy headers
include_directories("C:/Users/adamr/AppData/Local/Programs/Python/Python312/Lib/site-packages/numpy/core/include")



# Link Python libraries
target_link_libraries(ClimateChangeAnalysis ${Python3_LIBRARIES})
