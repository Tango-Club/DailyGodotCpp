cmake_minimum_required(VERSION 3.17)

set(CMAKE_OSX_ARCHITECTURES x86_64)
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    "${CMAKE_CURRENT_SOURCE_DIR}/output/${CMAKE_BUILD_TYPE}/${ARCHITECTURE}")
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(godot-cpp)
add_subdirectory(core)

project(DailyGodotCpp)
