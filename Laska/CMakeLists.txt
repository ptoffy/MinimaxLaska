cmake_minimum_required(VERSION 3.17)
project(Laska C)

set(CMAKE_C_STANDARD 90)

include_directories(Laska)

add_executable(Laska
        Campo.c
        headers/Campo.h
        Cella.c
        headers/Cella.h
        main.c
        Pedina.c
        headers/Pedina.h)
