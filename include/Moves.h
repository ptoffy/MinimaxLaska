/**
 * @file Moves.h
 * @author Paul Toffoloni
 * @date August 19, 2021
 * @brief Moves contains all the data types and methods used to handle moves.
 *
 * Move is a move available to a Tower, it contains an origin Cell, a destination Cell, and,
 * if the move is a conquer move, an "eaten" Cell, which is the cell that gets conquered.
 * Moves is an array containing a list of moves.
 */

#ifndef LASCA_MOVES_H
#define LASCA_MOVES_H

#include "Cell.h"
#include "Bool.h"
#include "Board.h"

/**
 * @brief Represents a possible move for a Tower.
 *
 * A user can perform a move, depending on the @p conquer variable,
 * either only moves the tower in the origin cell to the destination,
 * or also conquers the tower in the eaten cell.
 */
typedef struct Move {
    Cell *origin;       /**< The cell where the piece currently is and where it has to be moved from. */
    Cell *destination;  /**< The cell where the piece has to be moved to. */
    Cell *eaten;        /**< The cell where the piece to be conquered is. NULL if it is not a conquer move. */
    bool conquer;       /**< Represents if the move is a conquer move or not. */
} Move;

/**
 * @brief Array of Move.
 *
 * This struct is used to find all possible moves,
 * either for a single tower or for the whole board.
 */
typedef struct Moves {
    Move *moves;    /**< The array of possible moves. */
    size_t size;    /**< The current size of the array. */
} Moves;

/**
 * @brief Creates a new move.
 *
 * Returns a new normal move containing the origin cell and the destination cell
 * of the tower to be moved.
 *
 * @param origin The cell where the piece currently is and where it has to be moved from.
 * @param destination The cell where the piece has to be moved to.
 * @return The newly created move.
 */
Move
new_move(Cell *origin, Cell *destination);

/**
 * @brief Creates a new conquer move.
 *
 * Returns a new conquer move containing the origin cell, the destination cell
 * and the eaten cell of the pieces to be moved and conquered.
 *
 * @param origin Cell pointer where the tower currently is and where it has to be moved from.
 * @param destination Cell pointer where the piece has to be moved to.
 * @param eaten Cell pointer where the piece to be conquered is.
 * @return The newly created move.
 */
Move
new_conquer_move(Cell *origin, Cell *destination, Cell *eaten);

/**
 * @brief Initializes a new Moves array.
 *
 * Constructor for the Moves struct that creates a new moves array
 * assigning memory to it and returns it, empty.
 *
 * @return A new Moves struct with an empty array.
 */
Moves*
new_moves(size_t moves_size);

/**
 * @brief Adds a new Move to a Moves array.
 * @param move The Move to be added.
 * @param moves The array to which we add a Move to.
 */
void
add_move(Move move, Moves *moves);

/**
 * @brief Performs a Move.
 *
 * Assigns the tower pointer of the destination cell contained in the @p move pointer
 * to the origin one, then removes the tower from the origin cell.
 * If the move is a conquer move, also performs the conquest.
 *
 * @see conquer_tower
 *
 * @param move Pointer to the Move to be performed.
 * @param conquer Bool value indicating if the passed move is a conquer move.
 */
void
make_move(Move *move, bool conquer);

/**
 * @brief Promotes a Tower if necessary.
 *
 * Checks if a piece reached the end of the board and if so promotes it.
 *
 * @see Piece::promote
 *
 * @param move The Move that contains the tower we are checking promotion for.
 */
void
check_for_promotion(Move *move);

/**
 * @brief Conquers a Tower from a Move.
 *
 * Called when a conquest has to be performed,
 * removes the first element of the tower to be conquered
 * and places it on the top of the conqueror tower,
 * then rearranges the pieces of the remaining conquered tower,
 * if there are any left, otherwise, removes it from the cell
 * setting its pointer to NULL.
 *
 * @param move The Move we are using to conquer the tower.
 */
void
conquer_tower(Move *move);

/**
 * @brief Returns all possible moves for the indicated @p tower.
 *
 * Creates a Moves object containing every possible move for the selected tower,
 * using the soldier_possible_moves and officer_possible_moves methods.
 *
 * @param tower The tower that has to be moved.
 * @param board The board we are using.
 * @param x The x coordinate of the starter cell.
 * @param y The y coordinate of the starter cell.
 * @return An array containing all the moves a piece can make.
 */
Moves *
tower_possible_moves(Tower *tower, Board *board, int x, int y);

/**
 * @brief Returns all possible moves for the indicated soldier @p tower.
 *
 * Creates a Moves object containing every possible move for the selected soldier,
 * with a Bool value if the move is a conquest move or not.
 *
 * @param tower The tower that has to be moved.
 * @param board The board we are using.
 * @param x The x coordinate of the starter cell.
 * @param y The y coordinate of the starter cell.
 * @return An array containing all the moves a piece can make.
 */
Moves *
soldier_possible_moves(Tower *tower, Board *board, int x, int y);

/**
 * @brief Returns all possible moves for the indicated officer @p tower.
 *
 * Creates a Moves object containing every possible move for the selected officer,
 * with a Bool value if the move is a conquest move or not.
 *
 * @param tower The tower that has to be moved.
 * @param board The board we are using.
 * @param x The x coordinate of the starter cell.
 * @param y The y coordinate of the starter cell.
 * @return An array containing all the moves an officer can make.
 * @see soldier_possible_moves
 */
Moves *
officer_possible_moves(Tower *tower, Board *board, int x, int y);

/**
 * @brief Adds a Move to a Moves array depending on its type.
 *
 * Checks if a Move is a conquer move or not inspecting the cells around the @p destination_cell,
 * according to this adds the move either to a normal moves array or a conquer moves array.
 *
 * @param origin_cell The cell where the piece currently is and where it has to be moved from.
 * @param destination_cell The cell where the piece has to be moved to.
 * @param conquer_destination_cell The cell where the piece has to be moved to if the move is a conquer move.
 * @param color The color of the cell to be eatenm if it's a conquer move.
 * @param moves The moves array to be added the created Move to.
 */
void
add_to_possible_moves(Cell *origin_cell, Cell *destination_cell, Cell *conquer_destination_cell, Color color, Moves *moves);

/**
 * @brief Prints a Move.
 *
 * Prints the data from a Move, more precisely the coordinates of it,
 * enabling the user to choose one, indicating an id passed from a loop.
 *
 * @param move The Move to be printed.
 * @param i The id of the move.
 * @see user_move_piece
 */
void
print_move(Move *move, int i);

/**
 * @brief Getter for the Moves size.
 *
 * Returns the size for the selected Moves.
 * @param moves The selected Moves.
 * @return The size for the selected Moves.
 */
size_t
moves_get_size(Moves *moves);

/**
 * @brief Getter for the Move pointer.
 *
 * Returns the Move pointer array for the selected Moves.
 * @param moves The selected Moves.
 * @return The Move pointer for the selected Moves.
 */
Move *
moves_get_moves(Moves *moves);

/**
 * @brief Getter for the origin Cell.
 *
 * Returns the origin Cell pointer for the selected Move.
 * @param move The selected Move.
 * @return The origin Cell for the selected Move.
 */
Cell *
move_get_origin_cell(Move *move);

/**
 * @brief Getter for the destination Cell.
 *
 * Returns the destination Cell pointer for the selected Move.
 * @param move The selected Move.
 * @return The destination Cell for the selected Move.
 */
Cell *
move_get_destination_cell(Move *move);

/**
 * @brief Getter for the eaten Cell.
 *
 * Returns the eaten Cell pointer for the selected Move.
 * @param move The selected Move.
 * @return The eaten Cell for the selected Move.
 */
Cell *
move_get_eaten_cell(Move *move);

/**
 * @brief Getter for the conquer bool.
 *
 * Returns the eaten Cell pointer for the selected Move.
 * @param move The selected Move.
 * @return The eaten Cell for the selected Move.
 */
bool
move_get_conquer(Move *move);

/**
 * @brief Getter for a Move from an array.
 *
 * Returns a Move from a Moves array in the @p i position.
 * @param moves The array from which to take the Move from.
 * @param i The position of the Move.
 * @return The Move in that position.
 */
Move *
moves_get_move(Moves *moves, int i);

/**
 * @brief Setter for the Moves size.
 *
 * Sets the Moves size according to the parameter.
 * @param moves The Moves we set the size of.
 * @param size THe size to be set.
 */
void
moves_set_size(Moves *moves, size_t size);


#endif /* LASCA_MOVES_H */
