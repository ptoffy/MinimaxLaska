cmake_minimum_required(VERSION 3.17)
project(Lasca C)

set(CMAKE_C_STANDARD 11)

include_directories(headers)

add_executable(Lasca
        headers/Campo.h
        headers/Cella.h
        headers/Pedina.h
        Campo.c
        Cella.c
        main.c
        Pedina.c)
