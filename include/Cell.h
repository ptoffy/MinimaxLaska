/**
 * @file Cell.h
 * @author Paul Toffoloni
 * @date October 26, 2020
 * @brief Cell struct and methods to handle cells and their towers.
 *
 * This file contains a struct for a cell, the single cell of the board
 * which contains a tower and all methods to handle cells, for example
 * checking if a cell is empty so that we can move a tower there.
 *
 */

#ifndef CELL_H
#define CELL_H

#include "Tower.h"
#include <stdlib.h>

/**
 * @brief Single cell of the play board.
 *
 * Cell represents one of the single cells that make up the board.
 * It contains its coordinates and the piece on it, this way we can access
 * every piece by having the cell.
 */
typedef struct Cell {
    int x;                   /**< The x coordinates of the cell in the board. */
    int y;                   /**< The y coordinates of the cell in the board. */
    Tower *tower;            /**< Pointer that represents the piece in the cell. */
} Cell;

/**
 * @brief Prints the piece of a cell.
 *
 * If the piece is NULL, prints 0.
 * If the piece is other than NULL, prints a number indicating the height of the piece,
 * of the color of the piece.
 * @param cell The pointer of the cell of which the content has to be printed.
 */
void
print_cell_content(Cell *cell);

/**
 * Sets the pointer of the piece of a cell to NULL.
 * @param cell The cell of which the pointer has to be set to NULL.
 */
void
set_cell_empty(Cell *cell);

/**
 * Checks if the piece in the cell is empty or not.
 * @param cell The cell that has to be checked.
 * @return 0 if the cell is empty.
 */
int
is_cell_empty(Cell *cell);

/**
 * Checks if a cell is inside the playboard.
 * @param cell The cell to be checked.
 * @return true if the cell is inside the board.
 */
int
is_cell_in_board(Cell *cell);

/**
 * Creates a Tower assigning memory and attributes.
 * @param cell The Cell that gets is piece initialized.
 * @param color The Color of which the initialized piece has to be.
 */
void
init_tower(Cell* cell, int color);

/**
 * Returns the tower contained by the cell.
 * @param cell The selected cell.
 * @return The tower contained by the cell.
 */
Tower *
get_tower(Cell *cell);

#endif /* CELL_H */
