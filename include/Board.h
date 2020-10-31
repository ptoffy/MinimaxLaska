/**
 * @file Board.h
 * @author Paul Toffoloni
 * @date October 26, 2020
 * @brief File containing the definition and usage for Lasca:
 * Board is the game field that contains every cell and every piece that make up the game.
 */
#ifndef Campo_h
#define Campo_h

#include <stdio.h>
#include "Cell.h"

/**
 * Board is the game field that contains every cell and every piece that make up the game.
 */
typedef struct Board {
    int rows, columns; /**< The number of rows and columns */
    Cell* cells;       /**< A matrix of cells. */
} Board;

/**
 * Creates the board.
 * @param  rows    The number of rows that the field has to have.
 * @param  columns The number of columns that the field has to have.
 * @return         A new field with NULL cells.
 */
Board* create_board(int rows, int columns);

/**
 * Destroys the board.
 * @param board The board that gets destroyed.
 */
void destroy_board(Board* board);

/**
 * Prints the board with its pieces.
 * @param board The board to print.
 */
void print_field(Board* board);

/**
 * Prints the chess field.
 */
void print_board(void);

/**
 * Returns the cell that has the indicated coordinates.
 * @param  board The board in which to search the cell for.
 * @param  x     The x coordinate of the cell.
 * @param  y     The y coordinate of the cell.
 * @return       The cell if it exists, NULL if it doesn't.
 */
Cell* get_cell(Board *board, int x, int y);

/**
 * Initializes the board and assigns pieces to their initial position.
 * @param board The board to initialize.
 */
void init_board(Board* board);

/**
 * Creates a piece assigning memory and attributes.
 * @param cell  The cell that gets is piece initialized.
 * @param color The color of which the initialized piece has to be.
 */
void init_piece(Cell* cell, int color);

#endif /* Campo_h */
