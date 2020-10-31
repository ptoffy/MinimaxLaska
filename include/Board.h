#ifndef Campo_h
#define Campo_h

#include <stdio.h>
#include "Cell.h"

/**
 * The game field, contains the number of rows and columns and a matrix of cells.
 */
typedef struct Board {
    int rows, columns; /**< The number of rows and columns */
    Cell* cells; /**< A matrix of cells. */
} Board;

/**
 * Creates the field.
 * @param rows The number of rows that the field has to have.
 * @param columns The number of columns that the field has to have.
 * @return A new field with NULL cells.
 */
Board* createBoard(int rows, int columns);

/**
 * Prints the board with its pieces.
 * @param board The board to print.
 */
void printField(Board* board);

/**
 * Prints the chess field.
 */
void printBoard(void);

/**
 * Returns the cell that has the indicated coordinates.
 * @param board The board in which to search the cell for.
 * @param x The x coordinate of the cell.
 * @param y The y coordinate of the cell.
 * @return The cell if it exists, NULL if it doesn't.
 */
Cell* getCell(Board *board, int x, int y);

/**
 * Initializes the board and assigns pieces to their initial position.
 * @param board The board to initialize.
 */
void initBoard(Board* board);

/**
 * Creates a piece assigning memory and attributes.
 * @param cell The cell that gets is piece initialized.
 * @param color The color of which the initialized piece has to be.
 */
void initPiece(Cell* cell, int color);

#endif /* Campo_h */
