/**
 * @file Piece.c
 * @author Paul Toffoloni
 * @date October 26, 2020
 * @brief File containing the source code for Lasca:
 * Piece represents the pieces that the players play with.
 */

#include "Piece.h"

void increase_height(Tower *tower) {
    tower->height += 1;
}

void decrease_height(Tower *tower) {
    tower->height -= 1;
}

void promote(Tower *tower) {
    tower->pieces[0].type = OFFICER;
}
