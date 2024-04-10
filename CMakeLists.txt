cmake_minimum_required(VERSION 3.27)
project(ProjectMenu C)

set(CMAKE_C_STANDARD 17)

add_executable(ProjectMenu main.c
        libMenu.h
        libMenu.c)
