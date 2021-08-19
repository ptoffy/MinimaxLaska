/**
 * @file Piece.c
 * @author Paul Toffoloni
 * @date October 26, 2020
 * @brief File containing the source code for Lasca:
 * Piece represents the pieces that the players play with.
 */
#include "Piece.h"

void set_height(Tower *tower, int height) {
    tower->height = height;
}

void increase_height(Tower *tower) {
    tower->height += 1;
}

void lower_height(Tower *tower) {
    tower->height -= 1;
}
