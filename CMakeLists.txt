cmake_minimum_required(VERSION 3.17)
project(Lasca C)

set(CMAKE_C_STANDARD 90)

include_directories(include)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pedantic-errors")

add_executable(Lasca include/Board.h include/Cell.h include/Tower.h src/Board.c src/Cell.c main.c src/Tower.c src/Multiplayer.c
        src/Game.c include/Game.h include/Moves.h include/Bool.h src/Moves.c src/Bool.c include/Multiplayer.h include/SinglePlayer.h
        src/SinglePlayer.c)
