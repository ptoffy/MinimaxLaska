/**
 * @file MinimaxAI.c
 * @author Paul Toffoloni
 * @date August 25, 2021
 * @brief Minimax algorithm.
 *
 * This file contains to choose a Move for the CPU using
 * the Minimax algorithm.
 */

#include "MinimaxAI.h"

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
    return (int) round(white_left - black_left + (white_officers * 0.5 - black_officers * 0.5));
}

int minimax(Move *move, int depth, Color maximizing_player, Board *board) {
    int max_eval, min_eval, i, eval;
    Moves *moves;
    if (depth == 0)
        return evaluate(board);
    moves = calculate_moves(board, maximizing_player);
    if (maximizing_player == WHITE) {
        max_eval = (int) roundf(-INFINITY);
        for (i = 0; i < moves_get_size(moves); i++) {
            eval = minimax(move, depth - 1, BLACK, board);
            if (max_eval < eval) {
                max_eval = eval;
                move_set_move(move, moves_get_move(moves, i));
            }
        }
        return max_eval;
    } else {
        min_eval = (int) roundf(INFINITY);;
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
