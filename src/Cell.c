/**
 * @file Cell.c
 * @author Paul Toffoloni
 * @date October 26, 2020
 * @brief Cell struct and methods to handle cells and their towers.
 *
 * This file contains a struct for a cell, the single cell of the board
 * which contains a tower and all methods to handle cells, for example
 * checking if a cell is empty so that we can move a tower there.
 *
 */

#include <stdio.h>
#include "Cell.h"
#include "Tower.h"

#define ANSI_COLOR_RED    "\x1b[31m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_RESET  "\x1b[0m"

const char* get_color_string(Color color) {
    return color == WHITE ? "Bianco" : "Nero";
}

void print_cell_content(Cell *cell) {
    /* The order of the two conditions is important, since if a tower doesn't exist, we can't check for it's height. */
    if (get_tower(cell) != NULL && get_tower(cell)->height != 0) {
        if (get_tower(cell)->pieces[0].type == SOLDIER) {
            if (cell->tower->pieces[0].color == BLACK) {
                printf("%s%d%s  ", ANSI_COLOR_RED, cell->tower->height, ANSI_COLOR_RESET);
            } else {
                printf("%s%d%s  ", ANSI_COLOR_YELLOW, cell->tower->height, ANSI_COLOR_RESET);
            }
        } else {
            if (cell->tower->pieces[0].color == BLACK) {
                printf("%s%d%s* ", ANSI_COLOR_RED, cell->tower->height, ANSI_COLOR_RESET);
            } else {
                printf("%s%d%s* ", ANSI_COLOR_YELLOW, cell->tower->height, ANSI_COLOR_RESET);
            }
        }
    } else {
        printf("0  ");
    }
}

void set_cell_empty(Cell* cell) {
    cell->tower = NULL;
}

int is_cell_empty(Cell *cell) {
    return get_tower(cell) == NULL || !get_tower(cell)->height;
}

int is_cell_in_board(Cell *cell) {
    return cell != NULL && ((cell->x % 2 == 0) && (cell->y % 2 == 0) || (cell->x % 2 == 1) && (cell->y % 2 == 1));
}

/**
 * Assigns memory to a Tower pointer and assigns that attribute to the chosen Cell.
 * Assigns then the initial settings for a piece to that pointer.
 */
void init_tower(Cell* cell, int color) {
    Tower *tower = malloc(sizeof(Tower));
    tower->pieces = malloc(sizeof(Piece));
    cell->tower = tower;
    tower->height = 1;
    tower->pieces[0].color = color;
    tower->pieces[0].type = SOLDIER;
}

Tower *get_tower(Cell *cell) {
    return cell->tower;
}
