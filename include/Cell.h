#ifndef Cell_h
#define Cell_h

#include <stdio.h>
#include "Piece.h"

/**
 * A single cell of the board.
 */
typedef struct Cell {
    int x, y; /**< The x and y coordinates of the cell in the board. */
    Piece *piece; /**< Pointer that represents the piece in the cell. */
} Cell;

/**
 * Prints the content of a cell.
 * @param cell The pointer of the cell of which the content has to be printed.
 */
void printCellContent(Cell *cell);

/**
 * Sets the pointer of the piece of a cell to NULL.
 * @param cell The cell of which the pointer has to be set to NULL.
 */
void setPieceToNull(Cell *cell);

/**
 * Returns the piece of a cell.
 * @param cell The cell of which the piece has to be printed.
 * @return The piece of the indicated cell.
 */
Piece* getPiece(Cell *cell);

#endif /* Cell_h */
