cmake_minimum_required(VERSION 3.5.0)
project(Test VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(binops binops.cpp)
add_executable(binopsANS binops_ans_key.cpp)