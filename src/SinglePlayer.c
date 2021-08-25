/**
 * @file SinglePlayer.c
 * @author Paul Toffoloni
 * @date August 19, 2021
 * @brief SinglePlayer mode handler.
 *
 * This file contains all methods needed to play a player vs CPU game.
 */

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "SinglePlayer.h"
#include "Board.h"
#include "Bool.h"
#include "Game.h"
#include "MinimaxAI.h"

void random_cpu(Moves *moves) {
    int index;
    Move *move;
    time_t t;
    srand((unsigned) time(&t));
    index = rand() % moves_get_size(moves);
    move = moves_get_move(moves, index);
    make_move(move, move_get_conquer(move));
    free(moves);
}

void run_single_player() {
    Board *board = create_board(7, 7);
    Board *simulation_board = malloc(sizeof (Board));
    Moves *possible_moves;
    Move *move = malloc(sizeof (Move));
    Color turn = WHITE;
    int i = 0;
    init_board(board);
    *simulation_board = *board;

    while (true) {
        printf("Turno: %s\n", get_color_string(turn));
        print_board(board);
        possible_moves = calculate_moves(board, turn);
        if (moves_get_size(possible_moves) == 0) {
            printf("Partita finita, %s vince!", get_color_string(!turn));
            break;
        }
        if (turn == WHITE) {
            user_move_piece(possible_moves);
        } else {
            minimax(move, 3, BLACK, simulation_board);
            make_move(move, move_get_conquer(move));
            print_move(move, 0);
        }
        turn = !turn;
        i++;
    }
    destroy_board(simulation_board);
    destroy_board(board);
}
