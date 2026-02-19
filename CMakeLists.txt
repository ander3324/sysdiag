cmake_minimum_required(VERSION 3.10)

project(SysDiag VERSION 0.1 LANGUAGES C)

# Version info config
configure_file(
    ${CMAKE_SOURCE_DIR}/include/version.h.in
    ${CMAKE_BINARY_DIR}/generated/version.h
)
include_directories(${CMAKE_BINARY_DIR}/generated)

# C standard config
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Recommended flags
if(NOT_CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_C_FLAGS "-Wall -Wextra -Wpedantic")

# Include headers
include_directories(include)

# Find all .c files within src/
file(GLOB_RECURSE SOURCES "src/*.c")

# Create executable
add_executable(sysdiag ${SOURCES})

# Optional installation (for future use)
install (TARGETS sysdiag DESTINATION bin)
