cmake_minimum_required(VERSION 3.5.0)
project(Test VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)

add_executable(Test main.cpp Item.cpp Grocery.cpp Electronics.cpp)


include(CTest)
enable_testing()