/**
 * @file Board.h
 * @author Paul Toffoloni
 * @date October 26, 2020
 * @brief Board struct and methods to handle the board.
 *
 * This contains the play board, made up of every cell and every piece that make up the game,
 * and all the methods used to manage the board: memory allocation and destruction of all cells
 * and console handling of the board: showing the board.
 */

#ifndef Campo_h
#define Campo_h

#include "Cell.h"

/**
 * @brief Game field.
 *
 * Board is the game field that contains every Cell and every Tower that make up the game.
 * The cells pointer is an array that contains all the Cell of the board,
 * with the size of rows * columns, in classic Lasca it is 7 * 7,
 * meaning there are 49 cells. Lasca is played only on white cells,
 * in fact the actually used cells are just 25.
 */
typedef struct Board {
    int rows;           /**< The number of rows. */
    int columns;        /**< The number of columns. */
    Cell* cells;        /**< A matrix of cells. */
} Board;

/**
 * @brief Creates the board.
 *
 * Assigns memory to a board pointer and assigns rows and columns to it.
 * Creates then a matrix of Cell and assigns coordinates to each one of them.
 * Since here we are just creating the board,
 * it assigns NULL to the piece pointer in every cell, so that the board is empty,
 * although the cells are created
 *
 * @param rows The number of rows that the field has to have.
 * @param columns The number of columns that the field has to have.
 * @return A new play board with empty cells.
 */
Board *
create_board(int rows, int columns);

/**
 * @brief Initializes the board and assigns pieces to their initial position.
 *
 * This method is used before the start of the game after having created a board.
 * It assigns memory to every tower pointer inside the cells of the newly created board,
 * so that towers are created, and placed in their starting positions.
 *
 * @param board The board to initialize.
 */
void
init_board(Board* board);

/**
 * @brief Destroys the board.
 *
 * Frees the memory of everything that is used by the board:
 * pieces, cells and the board itself.
 *
 * @param board The board that gets destroyed.
 */
void
destroy_board(Board* board);

/**
 * @brief Prints the board with its pieces.
 * @param board The board to print.
 */
void
print_board(Board* board);

/**
 * @brief Returns the cell that has the indicated coordinates.
 *
 * Searches for a cell inside of the indicated board that has x and y coordinates
 * corresponding to the argument ones and returns a pointer to it.
 *
 * @param board The board in which to search the cell for.
 * @param x The x coordinate of the cell.
 * @param y The y coordinate of the cell.
 * @return A pointer to the cell if it exists, NULL if it doesn't.
 */
Cell *
get_cell(Board *board, int x, int y);

/**
 * @brief Getter for the boards columns number.
 *
 * Returns the columns number for the given board.
 * @param board The given board.
 * @return The columns number.
 */
int
board_get_columns(Board *board);

/**
 * @brief Getter for the boards rows number.
 *
 * Returns the rows number for the given board.
 * @param board The given board.
 * @return The rows number.
 */
int
board_get_rows(Board *board);

#endif /* Campo_h */

