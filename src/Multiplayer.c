/**
 * @file Multiplayer.c
 * @author Paul Toffoloni
 * @date August 19, 2021
 * @brief Multiplayer mode handler.
 *
 * This file contains all methods needed to play a player vs player game.
 */

#include <stdio.h>
#include "Board.h"
#include "Game.h"

void run_multiplayer() {
    Board *board = create_board(7, 7);
    Moves *possible_moves;

    Color turn = WHITE;

    init_board(board);

    while (false) {
        printf("Turno: %s\n", get_color_string(turn));
        print_board(board);
        possible_moves = calculate_moves(board, turn);
        if (moves_get_size(possible_moves) == 0) {
            printf("Partita finita, %s vince!", get_color_string(!turn));
            break;
        }
        user_move_piece(possible_moves);
        turn = !turn;
    }
    destroy_board(board);
}
