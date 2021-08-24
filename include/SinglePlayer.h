/**
 * @file SinglePlayer.h
 * @author Paul Toffoloni
 * @date August 19, 2021
 * @brief SinglePlayer mode handler.
 *
 * This file contains all methods needed to play a player vs CPU game.
 */

#ifndef LASCA_SINGLEPLAYER_H
#define LASCA_SINGLEPLAYER_H

#include "Moves.h"

/**
 * Starts a new SinglePlayer game.
 */
void
run_single_player();

/**
 * @brief Random CPU player.
 *
 * Lets the CPU choose a Move randomly to make against the opponent.
 * @param moves The Moves array from which the CPU chooses a Move from.
 */
void
random_cpu(Moves *moves);

#endif /* LASCA_SINGLEPLAYER_H */
