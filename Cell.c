#include <stdio.h>
#include "include/Cell.h"
#include "include/Piece.h"

#define ANSI_COLOR_RED    "\x1b[31m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_RESET  "\x1b[0m"

/**
 * If the piece is NULL, prints 0.
 * If the piece is other than NULL, prints a number indicating the height of the piece,
 * of the color of the piece.
 */
void printCellContent(Cell *cell) {
    if (cell->piece != NULL) {
        if (cell->piece->color == 0) {
            printf("%s%d%s ", ANSI_COLOR_RED, cell->piece->height, ANSI_COLOR_RESET);
        } else {
            printf("%s%d%s ", ANSI_COLOR_YELLOW, cell->piece->height, ANSI_COLOR_RESET);
        }
    } else {
        printf("0 ");
    }
}

void setPieceToNull(Cell* cell) {
    cell->piece = NULL;
}

Piece* getPiece(Cell *cell) {
    return cell->piece;
}
