/**
 * @file Cell.c
 * @author Paul Toffoloni
 * @date October 26, 2020
 * @brief File containing the source code for Lasca:
 * Clip stores a reference to a video file and its data within an editing sequence
 */
#include <stdio.h>
#include "Cell.h"
#include "Piece.h"

#define ANSI_COLOR_RED    "\x1b[31m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_RESET  "\x1b[0m"

void print_cell_content(Cell *cell) {
    if (cell->piece != NULL) {
        if (cell->piece->color == red) {
            printf("%s%d%s ", ANSI_COLOR_RED, cell->piece->height, ANSI_COLOR_RESET);
        } else {
            printf("%s%d%s ", ANSI_COLOR_YELLOW, cell->piece->height, ANSI_COLOR_RESET);
        }
    } else {
        printf("0 ");
    }
}

void set_cell_empty(Cell* cell) {
    cell->piece = NULL;
}

int is_cell_empty(Cell *cell) {
    if (cell->piece == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void set_piece(Cell *cell, Piece* piece) {
    cell->piece = piece;
}

Piece* get_piece(Cell *cell) {
    return cell->piece;
}

/**
 * Assigns memory to a pointer piece and assigns that attribute to the chosen cell.
 * Assigns then the initial settings for a piece to that pointer.
 */
void init_piece(Cell* cell, int color) {
    Piece* piece = malloc(sizeof(Piece));
    cell->piece = piece;
    piece->height = 1;
    piece->color = color;
    piece->type = soldier;
}

int is_cell_white(Cell *cell) {
    if (cell->color == white) {
        return 1;
    }
    return 0;
}
