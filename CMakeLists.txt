cmake_minimum_required(VERSION 3.5.0)
project(Test VERSION 0.1.0 LANGUAGES C CXX)

set(SOURCE_FILES1 main.cpp)
add_executable(app ${SOURCE_FILES1})


include(CTest)
enable_testing()

