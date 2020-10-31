/**
 * @file Cell.h
 * @author Paul Toffoloni
 * @date October 26, 2020
 * @brief File containing the definition and usage for Lasca:
 * Cell represents one of the single cells that make up the board.
 */
#ifndef Cell_h
#define Cell_h

#include <stdio.h>
#include "Piece.h"

/**
 * Cell represents one of the single cells that make up the board.
 * It contains its coordinates and the piece on it, this way we can access
 * every piece by having the cell.
 */
typedef struct Cell {
    int x, y;     /**< The x and y coordinates of the cell in the board. */
    Piece *piece; /**< Pointer that represents the piece in the cell. */
} Cell;

/**
 * Prints the content of a cell.
 * @param cell The pointer of the cell of which the content has to be printed.
 */
void print_cell_content(Cell *cell);

/**
 * Sets the pointer of the piece of a cell to NULL.
 * @param cell The cell of which the pointer has to be set to NULL.
 */
void set_piece_null(Cell *cell);

/**
 * Returns the piece of a cell.
 * @param cell The cell of which the piece has to be printed.
 * @return     The piece of the indicated cell.
 */
Piece* get_piece(Cell *cell);

#endif /* Cell_h */
