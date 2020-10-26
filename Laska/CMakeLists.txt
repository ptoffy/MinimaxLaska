cmake_minimum_required(VERSION 3.17)
project(Laska C)

set(CMAKE_C_STANDARD 90)

include_directories(Laska)

add_executable(Laska
        Campo.c
        Campo.h
        Cella.c
        Cella.h
        main.c
        Pedina.c
        Pedina.h)
