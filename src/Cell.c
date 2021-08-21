/**
 * @file Cell.c
 * @author Paul Toffoloni
 * @date October 26, 2020
 * @brief File containing the source code for Lasca:
 * Cell contains a single cell of the board.
 */
#include <stdio.h>
#include "Cell.h"
#include "Piece.h"

#define ANSI_COLOR_RED    "\x1b[31m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_RESET  "\x1b[0m"

const char* get_color_string(Color color) {
    return color == WHITE ? "Bianco" : "Nero";
}

void print_cell_content(Cell *cell) {
    /* The order of the two conditions is important, since if a tower doesn't exist, we can't check for it's height. */
    if (cell->tower != NULL && cell->tower->height != 0) {
        if (cell->tower->pieces[0].type == SOLDIER) {
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
    return cell->tower == NULL || !cell->tower->height;
}

void set_piece(Cell *cell, Tower* tower) {
    cell->tower = tower;
}

Tower *get_piece(Cell *cell) {
    return cell->tower;
}

int is_cell_in_board(Cell *cell) {
    return cell != NULL && ((cell->x % 2 == 0) && (cell->y % 2 == 0) || (cell->x % 2 == 1) && (cell->y % 2 == 1));
}

/**
 * Assigns memory to a Tower pointer and assigns that attribute to the chosen cell.
 * Assigns then the initial settings for a piece to that pointer.
 */
void init_piece(Cell* cell, int color) {
    Tower *tower = malloc(sizeof(Tower));
    tower->pieces = malloc(sizeof(Piece));
    cell->tower = tower;
    tower->height = 1;
    tower->pieces[0].color = color;
    tower->pieces[0].type = SOLDIER;
}

int is_cell_white(Cell *cell) {
    return cell->color == WHITE;
}
