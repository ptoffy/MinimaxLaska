/**
 * @file Piece.c
 * @author Paul Toffoloni
 * @date October 26, 2020
 * @brief File containing the source code for Lasca:
 * Piece represents the pieces that the players play with.
 */
#include "Piece.h"

void set_height(Piece *piece, int height) {
    piece->height = height;
}

void increase_height(Piece *piece) {
    piece->height += 1;

}

void lower_height(Piece *piece) {
    piece->height -= 1;
}
