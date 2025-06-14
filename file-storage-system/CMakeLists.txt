cmake_minimum_required(VERSION 3.10)
project(FileStorage)

set(CMAKE_CXX_STANDARD 17)

# Include header files
include_directories(include)

# Source files
set(SOURCES
    src/fileSystem.cpp
    src/main.cpp
)

add_executable(FileStorage ${SOURCES})
