cmake_minimum_required(VERSION 3.26)
project(familyTree C)

set(CMAKE_C_STANDARD 11)

add_executable(familyTree main.c
        familyList.c)
