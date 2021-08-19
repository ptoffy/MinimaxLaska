/**
 * @file Game.c
 * @author Giovanni Frigerio Zeno
 * @date October 31, 2020
 * @brief File containing the source code for Lasca:
 * Game controls the whole game, so if a piece is moved or the game has to end,
 * this file is in charge of it.
 */
#include <stdio.h>
#include "Game.h"
#include "Cell.h"
#include "Board.h"
#include "Play.h"


void move_piece(Board *board, int turn) {
    int x, y;
    Piece *piece;
    Cell *initialCell;

    /* Gets data from user input */
    x = get_x_input_coordinate();
    y = get_y_input_coordinate();
}

int check_initial_input(Board* board, int x, int y, Color turn) {
    /* Check if the selected cell is inside the board */
    if (!is_cell_in_board(board, x, y)) {
        printf("Questa cella non fa parte del campo\n");
        return 0;
    }
    /* Check if the selected cell contains something */
    if (is_cell_empty(get_cell(board, x, y))) {
        printf("Questa cella non contiene pedine\n");
        return 0;
    }
    /* Check if the piece is of the corresponding color of the player */
    if (get_cell(board, x, y)->tower->pieces[0].color != turn) {
        printf("Questa pedina non ti appartiene\n");
        return 0;
    }
    /* Check if a piece can actually move from its position */
    if (possible_moves(get_cell(board, x, y)->tower, board, x, y) == 0) {
        printf("Questa pedina non può essere mossa, inserisci nuovamente le coordinate\n");
        return 0;
    }
    /* Finally, if all checks returned true, return true */
    printf("La pedina selezionata può essere mossa\n");
    return 1;
}

int check_final_input(Board* board, int x, int y) {
    return 0;
}

int possible_moves(Tower *tower, Board *board, int x, int y) {
    int moves_number = 0;
    if (tower->pieces[0].type == SOLDIER) {
        if (tower->pieces[0].color == BLACK) {
            if (is_cell_in_board(board, x + 1, y + 1) && is_cell_empty(get_cell(board, x + 1, y + 1))) {
                moves_number += 1;
            }
            if (is_cell_in_board(board, x - 1, y + 1) && is_cell_empty(get_cell(board, x - 1, y + 1))) {
                moves_number += 1;
            }
        } else {
            if (is_cell_in_board(board, x + 1, y - 1) && is_cell_empty(get_cell(board, x + 1, y - 1))) {
                moves_number += 1;
            }
            if (is_cell_in_board(board, x - 1, y - 1) && is_cell_empty(get_cell(board, x - 1, y - 1))) {
                moves_number += 1;
            }
        }
    }
    return moves_number;
}

int get_x_input_coordinate() {
    int x;
    printf("Inserisci la coordinata x della cella:");
    scanf("%d", &x);
    return x;
}

int get_y_input_coordinate() {
    int y;
    printf("Inserisci la coordinata y della cella:");
    scanf("%d", &y);
    return y;
}

int get_x_input_coordinate_final() {
    int x;
    printf("Inserisci la coordinata x della cella:");
    scanf("%d", &x);
    return x;
}

int get_y_input_coordinate_final() {
    int y;
    printf("Inserisci la coordinata y della cella:");
    scanf("%d", &y);
    return y;
}
