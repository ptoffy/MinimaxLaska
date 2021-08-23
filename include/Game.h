/**
 * @file Game.h
 * @author Paul Toffoloni
 * @date October 31, 2020
 * @brief Methods to handle a game.
 *
 * This file is in charge of handling the game,
 * calculating all possible moves inside the board
 * and checking if a move can be made.
 */

#ifndef LASCA_GAME_H
#define LASCA_GAME_H

#include "Board.h"
#include "Moves.h"

/**
 * @brief Checks if any moves can be performed on a determined cell.
 *
 * Called when the input for the initial cell during a move has to be checked and checks if:
 * the cell is white, meaning if it's part of the board,
 * the cell is empty, so there is a piece in that cell,
 * the piece in the selected cell can move somewhere.
 * If the move is not possible, prints the reason.
 *
 * @param board The board on which the move is being made on.
 * @param x The x coordinate of the selected cell.
 * @param y The y coordinate of the selected cell.
 * @param turn The turn that is being played.
 * @return 0 if the move is possible, 1 if not.
 */
bool
can_tower_move(Board* board, int x, int y, Color turn);

/**
 * @brief Calculates all moves that can be made during a turn.
 * @param board The board that is being played on.
 * @param turn Color indicating who is playing.
 * @return An array containing all possible moves.
 */
Moves *
calculate_moves(Board *board, Color turn);

/**
 * @brief Moves a Tower selected by the user to another Cell.
 *
 * Lets the user select a Move from an array of Moves
 * and then performs that move.
 *
 * @param moves The Moves array from which the user select a Move.
 */
void
user_move_piece(Moves *moves);


#endif /* LASCA_GAME_H */
