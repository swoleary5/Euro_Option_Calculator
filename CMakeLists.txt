# CMakeLists.txt
cmake_minimum_required(VERSION 3.10) # specify the minimum version of CMake that is required

# Set the project name and version
project(OptionPricing)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(OptionPricing main.cpp OptionCalculator.cpp Node.h ConstructTree.cpp)