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

/** Red color code used to print red pieces in the terminal */
#define ANSI_COLOR_RED    "\x1b[31m"
/** Yellow color code used to print yellow pieces in the terminal */
#define ANSI_COLOR_YELLOW "\x1b[33m"
/** Reset color code used to reset the color printing in the terminal */
#define ANSI_COLOR_RESET  "\x1b[0m"

const char* get_color_string(Color color) {
    return color == WHITE ? "Bianco" : "Nero";
}

void print_cell_content(Cell *cell) {
    /* The order of the two conditions is important, since if a tower doesn't exist, we can't check for it's height. */
    if (cell_get_tower(cell) != NULL && tower_get_height(cell_get_tower(cell)) != 0) {
        if (tower_get_type(cell->tower) == SOLDIER) {
            if (tower_get_color(cell->tower) == BLACK) {
                printf("%s%d%s  ", ANSI_COLOR_RED, tower_get_height(cell->tower), ANSI_COLOR_RESET);
            } else {
                printf("%s%d%s  ", ANSI_COLOR_YELLOW, tower_get_height(cell->tower), ANSI_COLOR_RESET);
            }
        } else {
            if (tower_get_color(cell->tower) == BLACK) {
                printf("%s%d%s* ", ANSI_COLOR_RED, tower_get_height(cell->tower), ANSI_COLOR_RESET);
            } else {
                printf("%s%d%s* ", ANSI_COLOR_YELLOW, tower_get_height(cell->tower), ANSI_COLOR_RESET);
            }
        }
    } else
        printf("0  ");
}

void set_cell_empty(Cell* cell) {
    cell->tower = NULL;
}

int is_cell_empty(Cell *cell) {
    return cell->tower == NULL || !tower_get_height(cell->tower);
}

int is_cell_in_board(Cell *cell) {
    return cell != NULL && ((cell->x % 2 == 0) && (cell->y % 2 == 0) || (cell->x % 2 == 1) && (cell->y % 2 == 1));
}

void init_cell(Cell* cell, int color) {
    cell->tower = init_tower(color);
}

Tower *cell_get_tower(Cell *cell) {
    return cell->tower;
}

int get_x_coordinate(Cell *cell) {
    return cell->x;
}

int get_y_coordinate(Cell *cell) {
    return cell->y;
}

void cell_set_tower(Cell *cell, Tower *tower) {
    cell->tower = tower;
}
