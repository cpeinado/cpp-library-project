cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(CppLibraryProject VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Add the library
add_library(cpp_library src/library.cpp)

# Add the executable for tests
add_executable(test_library tests/test_library.cpp)

# Link the library to the test executable
target_link_libraries(test_library cpp_library)