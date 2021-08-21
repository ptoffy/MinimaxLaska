//
// Created by Paul Toffoloni on 19/08/21.
//

#ifndef LASCA_MOVES_H
#define LASCA_MOVES_H

#include "Cell.h"
#include "Bool.h"
#include "Board.h"

/**
 * Represents a possible move for a piece.
 */
typedef struct Move {
    Cell *origin;       /**< The cell where the piece currently is and where it has to be moved from. */
    Cell *destination;  /**< The cell where the piece has to be moved to. */
    Cell *eaten;        /**< The cell where the piece to be conquered is. NULL if it is not a conquer move. */
    bool conquer;       /**< Represents if the move is a conquer move or not. */
} Move;

/**
 * Array of moves that contains all possible moves for a piece to make.
 */
typedef struct Moves {
    Move *moves;    /**< The array of possible moves. */
    size_t size;    /**< The current size of the array. */
} Moves;

/**
 * Creates a new move, leaving the *eaten* cell to NULL since it's not a conquer move.
 * @param origin The cell where the piece currently is and where it has to be moved from.
 * @param destination The cell where the piece has to be moved to.
 * @return The newly created move.
 */
Move new_move(Cell *origin, Cell *destination);

/**
 * Creates a new conquer move.
 * @param origin The cell where the piece currently is and where it has to be moved from.
 * @param destination The cell where the piece has to be moved to.
 * @param eaten The cell where the piece to be conquered is.
 * @return The newly created move.
 */
Move new_conquer_move(Cell *origin, Cell *destination, Cell *eaten);

/**
 * Initializer for a Moves array.
 * @return A new Moves struct with an empty array.
 */
Moves new_moves();

/**
 * Adds a new Move to a Moves array.
 * @param move The Move to be added.
 * @param moves The array to which we add a Move to.
 */
void add_move(Move move, Moves *moves);

/**
 * Moves a piece from its origin to its destination, conquering the eaten piece if necessary.
 * @param move The move to be performed.
 * @param conquer True if it is a conquer move.
 */
void make_move(Move *move, bool conquer);

/**
 * Checks if a piece reached the end of the field and if so promotes it.
 * @param move The Move that contains the piece we are checking promotion for.
 */
void check_for_promotion(Move *move);

/**
 * Conquers a tower from a Move.
 * @param move The Move we are using to conquer the tower.
 */
void conquer_tower(Move *move);

/**
 * Creates a Moves object containing every possible move for the selected soldier,
 * with a boolean value if the move is a conquest move or not.
 * @param tower The tower that has to be moved.
 * @param board The board we are using.
 * @param x The x coordinate of the starter cell.
 * @param y The y coordinate of the starter cell.
 * @return An array containing all the moves a piece can make.
 */
Moves soldier_possible_moves(Tower *tower, Board *board, int x, int y);

/**
 * Creates a Moves object containing every possible move for the selected officer,
 * with a boolean value if the move is a conquest move or not.
 * @param tower The tower that has to be moved.
 * @param board The board we are using.
 * @param x The x coordinate of the starter cell.
 * @param y The y coordinate of the starter cell.
 * @return An array containing all the moves an officer can make.
 */
Moves officer_possible_moves(Tower *tower, Board *board, int x, int y);

/**
 * Creates a new Move from the passed cells and checks if it is a conquer move or not.
 * @param origin_cell The cell where the piece currently is and where it has to be moved from.
 * @param destination_cell The cell where the piece has to be moved to.
 * @param conquer_destination_cell The cell where the piece has to be moved to if the move is a conquer move.
 * @param color The color of the cell to be eatenm if it's a conquer move.
 * @param moves The moves array to be added the created Move to.
 */
void add_to_possible_moves(Cell *origin_cell, Cell *destination_cell, Cell *conquer_destination_cell, Color color, Moves *moves);

void print_move(Move *move, int i);

#endif //LASCA_MOVES_H
