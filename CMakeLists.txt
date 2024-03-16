cmake_minimum_required(VERSION 3.24)
project(CP)

set(CMAKE_CXX_STANDARD 17)

#add_executable(CP slows/checker_icpc.cpp)
add_executable(CP "F.cpp")

# for stack size
#set(CMAKE_EXE_LINKER_FLAGS "-Wl,-stack_size,0x20000000")