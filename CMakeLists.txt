cmake_minimum_required(VERSION 3.6)
project(esp)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES assa.c)
add_executable(esp ${SOURCE_FILES})