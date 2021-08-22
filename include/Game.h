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
 * Calcualates all moves that can be made during that turn.
 * @param board The board that is being played on.
 * @param turn Color indicating who is playing.
 * @return An array containing all possible moves.
 */
Moves* calculate_moves(Board *board, Color turn);


#endif /* LASCA_GAME_H */
