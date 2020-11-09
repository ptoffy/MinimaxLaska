/**
 * @file Game.c
 * @author Giovanni Frigerio Zen
 * @date October 31, 2020
 * @brief File containing the source code for Lasca:
 * Game controls the whole game, so if a piece is moved or the game has to end,
 * this file is in charge of it.
 */
#include <stdio.h>
#include "Game.h"
#include "Cell.h"
#include "Board.h"

void move_piece(Board *board) {
    int x, y;
    Piece *piece;
    Cell *initialCell;

    /* Gets data from user input */
    x = get_x_input_coordinate();
    y = get_y_input_coordinate();


    /* Checks input data for impossible moves */
    if (check_initial_input(board, x, y) == 0) {
        initialCell = get_cell(board, x - 1, y - 1);
        piece = get_piece(initialCell);

        /* Gets data from user input */
        x = get_x_input_coordinate();
        y = get_y_input_coordinate();


        /* Sets the piece to the new cell and deletes it from the old one */
        set_piece(get_cell(board, x - 1, y - 1), piece);
        set_cell_empty(initialCell);
    }
}

int check_initial_input(Board* board, int x, int y) {
    if (is_cell_white(get_cell(board, x, y)) == 0) {
        if (is_cell_empty(get_cell(board, x, y)) == 1) {
            if (can_piece_move(get_cell(board, x, y), board) == 0) {
                return 0;
            } else {
                printf("Questa pedina non può essere mossa in nessuna cella, riprova.\n");
            }
        } else {
            printf("Qui non c'è nessuna pedina! Riprova.\n");
        }
    } else {
        printf("Quella cella non fa parte del campo, riprova.\n");
    }
    return 1;
}

int check_final_input(Board* board, int x, int y) {
    if (is_cell_white(get_cell(board, x, y)) == 0) {
        if (is_cell_empty(get_cell(board, x, y)) == 0) {
            /* TODO: Add control for if cell is next to first cell or if you can eat */

            return 0;
        } else {
            printf("Qui c'è già una pedina! Riprova.\n");
        }
    } else {
        printf("Quella cella non fa parte del campo, riprova.\n");
    }
    return 1;
}

int can_piece_move(Cell* cell, Board* board) {
    /* TODO: Complete */

    Cell *move;

    if (cell->piece->type == soldier) {
        move = get_cell(board, cell->x + 1, cell->y - 1);
        if (is_cell_empty(move) == 0) {
            return 0;
        } else {
            move = get_cell(board, cell->x - 1, cell->y - 1);
            if (is_cell_empty(move) == 0) {
                return 0;
            } else {
              /*  move = get_cell(board, cell->x - 1, cell->y + 1); una parte di questo codice deve essere
                                                                        * cancellata perche la pedina puo` muoversi
                                                                        * solo in avanti
                if (is_cell_empty(move) == 0) {
                    return 0;
                } else {
                    move = get_cell(board, cell->x + 1, cell->y + 1);
                    if (is_cell_empty(move) == 0) {
                        return 0;
                    } else {
                        return 1;
                    }
                }*/
            }
        }
    }
    if(cell->piece->type == column) {

    }
}

/*int you_can_eat(Cell* cell, Board* board){
    Cell* eat;
    Cell* eat1;
    Cell* eat2;
    Cell* move1;
    Cell* move2;



    eat = get_cell(board, cell->x+1, cell->y+1);

    /* TODO: check if the player can move in an empty cell over opponent piece */
 /*   if(is_cell_empty(move1) == 1) {
        if (is_cell_empty(eat) == 0) {                              CONTROLLA SE è DELL'AVVERSARIO
            eat1 = get_cell(board, cell->x + 1, cell->y - 1);
            return 0;
        } else { return 1;}
    } else if(is_cell_empty(move2) == 1){
        if (is_cell_empty(eat) == 0){
            eat2 = get_cell(board, cell->x-1, cell->y-1);
            return 0;
        } else {return 1;}
    }


} */



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
