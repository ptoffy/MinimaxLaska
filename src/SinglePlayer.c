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
    Moves *possible_moves;
    Color turn = WHITE;
    int i = 0;
    init_board(board);

    while (true) {
        printf("Turno: %s\n", get_color_string(turn));
        print_board(board);
        possible_moves = calculate_moves(board, turn);
        if (moves_get_size(possible_moves)) {
            printf("Partita finita, %s vince!", get_color_string(!turn));
            break;
        }
        turn == WHITE ? user_move_piece(possible_moves) : random_cpu(possible_moves);
        turn = !turn;
        i++;
    }
    destroy_board(board);
}
