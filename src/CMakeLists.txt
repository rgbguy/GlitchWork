cmake_minimum_required(VERSION 2.8)
set (CMAKE_CXX_STANDARD 11)

project(GlitchWork)

include_directories(public)


add_executable(${PROJECT_NAME} private/main.cpp)

find_package(OpenGL REQUIRED)

target_include_directories(${PROJECT_NAME} PUBLIC public)