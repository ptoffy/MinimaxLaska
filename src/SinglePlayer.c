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
#include <math.h>
#include "SinglePlayer.h"
#include "Board.h"
#include "Bool.h"
#include "Game.h"

double evaluate(Board *board) {
    int x, y, white_left = 0, black_left = 0, white_officers = 0, black_officers = 0;
    Cell *cell;
    for (x = 1; x <= board_get_rows(board); x++) {
        for (y = 1; y <= board_get_columns(board); y++) {
            cell = board_get_cell(board, x, y);
            if (is_cell_in_board(cell) && !is_cell_empty(cell)) {
                if (tower_get_color(cell_get_tower(board_get_cell(board, x, y))) == WHITE) {
                    white_left++;
                    if (tower_get_type(cell_get_tower(board_get_cell(board, x, y))) == OFFICER)
                        white_officers++;
                } else if (tower_get_type(cell_get_tower(board_get_cell(board, x, y))) == OFFICER) {
                    black_officers++;
                    black_left++;
                }
            }
        }
    }
    return white_left - black_left + (white_officers * 0.5 - black_officers * 0.5);
}

double minimax(Move *move, int depth, Color maximizing_player, Board *board) {
    double max_eval, min_eval, eval;
    int i;
    Moves *moves;
    if (depth == 0)
        return evaluate(board);
    moves = calculate_moves(board, maximizing_player);
    if (maximizing_player == BLACK) {
        max_eval = -INFINITY;
        for (i = 0; i < moves_get_size(moves); i++) {
            eval = minimax(move, depth - 1, BLACK, board);
            if (max_eval < eval) {
                max_eval = eval;
                move_set_move(move, moves_get_move(moves, i));
            }
        }
        return max_eval;
    } else {
        min_eval = WHITE;
        for (i = 0; i < moves_get_size(moves); i++) {
            eval = minimax(move, depth - 1, WHITE, board);
            if (min_eval > eval) {
                min_eval = eval;
                move_set_move(move, moves_get_move(moves, i));
            }
        }
        return min_eval;
    }
}

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
    }
    destroy_board(simulation_board);
    destroy_board(board);
}
