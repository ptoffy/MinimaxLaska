/**
 * @file Cell.c
 * @author Paul Toffoloni
 * @date October 26, 2020
 * @brief File containing the source code for Lasca:
 * Clip stores a reference to a video file and its data within an editing sequence
 */
#include <stdbool.h>
#include <stdio.h>
#include "Cell.h"
#include "Piece.h"

#define ANSI_COLOR_RED    "\x1b[31m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_RESET  "\x1b[0m"

void print_cell_content(Cell *cell) {
    if (cell->tower->height != 0) {
        if (cell->tower->pieces[0].color == BLACK) {
            printf("%s%d%s ", ANSI_COLOR_RED, cell->tower->height, ANSI_COLOR_RESET);
        } else {
            printf("%s%d%s ", ANSI_COLOR_YELLOW, cell->tower->height, ANSI_COLOR_RESET);
        }
    } else {
        printf("0 ");
    }
}

void set_cell_empty(Cell* cell) {
    cell->tower->height = 0;
}

int is_cell_empty(Cell *cell) {
    return !cell->tower->height;
}

void set_piece(Cell *cell, Tower* tower) {
    cell->tower = tower;
}

Tower *get_piece(Cell *cell) {
    return cell->tower;
}

/**
 * Assigns memory to a Tower pointer and assigns that attribute to the chosen cell.
 * Assigns then the initial settings for a piece to that pointer.
 */
void init_piece(Cell* cell, int color) {
    Tower *tower = malloc(sizeof(Piece));
    cell->tower = tower;
    tower->height = 1;
    tower->pieces[0].color = color;
    tower->pieces[0].type = SOLDIER;
}

int is_cell_white(Cell *cell) {
    return cell->color == WHITE;
}
