cmake_minimum_required(VERSION 3.5.0)
project(StudentProgram)
set(CMAKE_CXX_STANDARD 20)
set(SOURCE_FILES1 main.cpp student.cpp)
add_executable(studentsapp ${SOURCE_FILES1})

set(SOURCE_FILES2 references.cpp)
add_executable(references ${SOURCE_FILES2})

set(SOURCE_FILES3 references2.cpp)
add_executable(references2 ${SOURCE_FILES3})