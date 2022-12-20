cmake_minimum_required(VERSION 3.0)
project(Aalborg-University-Projects C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(Project_P1/Prototypes)
add_subdirectory(Project_P1/Solution)

enable_testing()
add_subdirectory(Project_P1/Test)