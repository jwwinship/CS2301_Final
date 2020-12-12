cmake_minimum_required(VERSION 3.17)
project(CS2301_Final C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(CS2301_Final
        src/CS2301_Final.c
        src/LinkedList.c
        src/LinkedList.h
        src/production.c
        src/production.h
        src/tests.c
        src/tests.h
        src/TMSName.h src/Course.c src/Course.h src/Schedule.c src/Schedule.h)
