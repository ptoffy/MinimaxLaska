/**
 * @file Multiplayer.h
 * @author Paul Toffoloni
 * @date August 19, 2021
 * @brief File containing the definition and usage for Lasca:
 * Multiplayer contains all methods needed to play a player vs player game.
 */

#ifndef LASCA_MULTIPLAYER_H
#define LASCA_MULTIPLAYER_H

#include "Moves.h"

/**
 * Moves a piece selected by the user to another cell.
 * @param moves The moves array from which the user select a move.
 */
void move_piece(Moves *moves);

/**
 * Start a new Multiplayer game.
 */
void run_multiplayer();

#endif /* LASCA_MULTIPLAYER_H */
