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
        if (is_cell_empty(get_cell(board, x, y)) == 1 ) {
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

    Cell *move1;
    Cell *move2;
    Cell *move3;
    Cell *move4;

    move1 = get_cell(board, cell->x + 1, cell->y - 1);   /* ti metto qua le mosse cosi e` piu` chiaro*/
    move2 = get_cell(board, cell->x - 1, cell->y - 1);
    move3 = get_cell(board, cell->x - 1, cell->y + 1);
    move4 = get_cell(board, cell->x + 1, cell->y + 1);


    if (cell->piece->type == soldier) {
        if (is_cell_empty(move1) == 0) {
            return 0;
        } else {
            if (is_cell_empty(move2) == 0) {
                return 0;
            } else { return 1;}
        }
    }

    if (cell->piece->type == column) {
        if (is_cell_empty(move1) == 1) {
            return 0;
        } else if (is_cell_empty(move2) == 0) {
            return 0;
        } else if (is_cell_empty(move3) == 0) {
            return 0;
        } else if (is_cell_empty(move4) == 0) {
            return 0;
        } else { return 1; }
    }









int you_can_eat(Cell* cell, Board* board) {
    Cell *eat1;
    Cell *eat2;
    Cell *eat3;
    Cell *eat4;
    Cell *move1;
    Cell *move2;
    Cell *move3;
    Cell *move4;

    move1 = get_cell(board, cell->x + 1, cell->y - 1);
    move2 = get_cell(board, cell->x - 1, cell->y - 1);
    move3 = get_cell(board, cell->x - 1, cell->y + 1);
    move4 = get_cell(board, cell->x + 1, cell->y + 1);
    eat1 = get_cell(board, cell->x + 1, cell->y - 1);
    eat2 = get_cell(board, cell->x - 1, cell->y - 1);
    eat3 = get_cell(board, cell->x - 1, cell->y + 1);
    eat4 = get_cell(board, cell->x + 1, cell->y + 1);





    /* TODO: check if the player can move in an empty cell over opponent piece */
    if (is_cell_empty(move1) == 1) {
        if (is_cell_empty(eat1) == 0) {
            printf("%d %d"), eat1[cell->x, cell->y]; /* come richiamare x, y dei vari eat, utilizzo il printf per far vedere le possibile mosse che si possono fare*/
        }
        return 0;

    } else if (is_cell_empty(move2) == 1) {
        if (is_cell_empty(eat2) == 0) {
            printf("%d %d"), eat2[cell->x], eat2[cell->y]; /*questo mi sembra il modo corretto*/
            return 0;
        }
    } else if (is_cell_empty(move3) == 1 && cell->piece->type == column) {  /*mosse possibili con una column*/
        if (is_cell_empty(eat3) == 0) {
            printf("%d %d"), eat3->x, eat3->y;
            return 0;
        }
    } else if (is_cell_empty(move4) == 1 && cell->piece->type == column) {
        if (is_cell_empty(eat4) == 0) {
            printf("%d");
        }
        return 0;

    } else { return 1; }

}

    void move_piece(Cell *cell, Board *board )














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
