/**
 * @file Game.h
 * @author Paul Toffoloni
 * @date October 31, 2020
 * @brief File containing the definition and usage for Lasca:
 * Game controls the whole game, so if a piece is moved or the game has to end,
 * this file is in charge of it.
 */
#ifndef LASCA_GAME_H
#define LASCA_GAME_H

#include "Board.h"
#include "Moves.h"

/**
 * Called when the input for the initial cell during a move has to be checked and checks if:
 * the cell is white, meaning if it's part of the board,
 * the cell is empty, so there is a piece in that cell,
 * the piece in the selected cell can move somewhere.
 * If the move is not possible, prints the reason.
 * @param board The board on which the move is being made on.
 * @param x The x coordinate of the selected cell.
 * @param y The y coordinate of the selected cell.
 * @return 0 if the move is possible, 1 if not.
 */
bool check_initial_input(Board* board, int x, int y, Color turn, Moves *moves);

/**
 * Called when the input for the arriving cell during a move has to be checked and checks if:
 * the cell is white, meaning if it's part of the board,
 * the cell is empty, so there is no piece in that cell.
 * If the move is not possible, prints the reason.
 * @param board The board on which the move is being made on.
 * @param x The x coordinate of the selected cell.
 * @param y The y coordinate of the selected cell.
 * @return 0 if the move is possible, 1 if not.
 */
int check_final_input(Board* board, int x, int y);

/**
 * Moves a piece selected by the user to another cell.
 * @param board The board in which the piece is moved.
 * @param turn The turn indicating which player is playing.
 */

/*void move_piece(Board *board, int turn);*/

/**
 * Moves a piece selected by the user to another cell.
 * @param moves The moves array from which the user select a move.
 */
void move_piece(Moves *moves);

/**
 * Reads and returns x coordinate from user input.
 * @return The read x coordinate.
 */
int get_x_input_coordinate();

/**
 * Reads and returns y coordinate from user input.
 * @return The read y coordinate.
 */
int get_y_input_coordinate();

Moves* calculate_moves(Board *board, Color turn);


#endif //LASCA_GAME_H
