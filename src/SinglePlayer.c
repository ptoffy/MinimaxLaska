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

/*int cpu(board, moves, limit){
    int i;
    Board temp_board = copyboard();                     *//* make a copy of the actual board to simulate *//*
    for(i = 0;i < nmoves;i++){                          *//* do until all the moves have been seen *//*
        do_move(temp_board, moves[i]);                  *//* do the move on the simulation board *//*
        if (cont != limit)                              *//* control if the limit of control has been reached *//*
            cpu(temp_board, moves, limit++);            *//* do the recursive thing if there is other plans under it *//*
        else {
            int pawns = count_pawns(limit,temp_board);  *//* count how many pawns there are on the board on the right side *//*
            score = confront_pawns(pawns);              *//* set the score for the actual node *//*
            if(score > last_score && limit%2 != 0){     *//* if the score is greater and there is a max or a min *//*
                last_score = score;                     *//* if there is a max and the score is greater go recursive for the *//*
            }
        }
    }
    limit--;
    return last_score;
}*/

int evaluate(Board *board) {
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

int minimax(Move *move, int depth, Color turn, Board *board) {
    int max_eval, min_eval, i, eval;
    Moves *moves;
    if (depth == 0)
        return evaluate(board);
    moves = tower_possible_moves(cell_get_tower(move_get_origin_cell(move)), board, move_get_origin_cell(move)->x, move_get_origin_cell(move)->y);
    if (turn == WHITE) {
        max_eval = -INFINITY;
        for (i = 0; i < moves_get_size(moves); i++) {
            move->destination = move_get_destination_cell(moves_get_move(moves, i));
            eval = minimax(move, depth - 1, BLACK, board);
            if (max_eval < eval) {
                max_eval = eval;
                move->origin = move_get_origin_cell(moves_get_move(moves, i));
            }
        }
        return max_eval;
    } else {
        min_eval = INFINITY;
        for (i = 0; i < moves_get_size(moves); i++) {
            move->destination = move_get_destination_cell(moves_get_move(moves, i));
            eval = minimax(move, depth - 1, WHITE, board);
            if (min_eval > eval) {
                min_eval = eval;
                move->origin = move_get_origin_cell(moves_get_move(moves, i));
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
    check_for_promotion(move);
    free(moves);
}

void run_single_player() {
    Board *board = create_board(7, 7);
    Board *simulation_board = malloc(sizeof (Board));
    Moves *possible_moves;
    Move *move;
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
            free(move);
        }
        turn = !turn;
        i++;
    }
    destroy_board(simulation_board);
    destroy_board(board);
}
