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
#include "Moves.h"


void move_piece(Board *board, int turn) {
    int x, y;
    Piece *piece;
    Cell *initialCell;

    /* Gets data from user input */
    x = get_x_input_coordinate();
    y = get_y_input_coordinate();
}

int check_initial_input(Board* board, int x, int y) {
    if (get_cell(board, x, y)->piece!=NULL) {
        if (can_piece_move(board, x, y) > 0) {
            printf("La pedina selezionata può essere mossa\n");
            return 1;
        }else{
            printf("Questa pedina non può essere mossa, inserisci nuovamente le coordinate\n");
            return 0;
        }
    }else{
        printf("Questa pedina non fa parte del campo\n");
        return 0;
    }
}

int check_final_input(Board* board, int x, int y) {

    return 0;
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
