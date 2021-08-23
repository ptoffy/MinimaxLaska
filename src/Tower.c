/**
 * @file Tower.c
 * @author Paul Toffoloni
 * @date October 26, 2020
 * @brief Data types and methods used to handle a Tower.
 *
 * A tower is what the game is played with and is made up of an array of pieces.
 * This file is in charge of handling everything regarding towers,
 * like increasing or decreasing its height or promoting a soldier.
 */

#include "Tower.h"

void increase_height(Tower *tower) {
    tower->height += 1;
}

void decrease_height(Tower *tower) {
    tower->height -= 1;
}

void promote(Tower *tower) {
    tower->pieces[0].type = OFFICER;
}

Color get_tower_color(Tower *tower) {
    return tower->pieces[0].color;
}

Type get_tower_type(Tower *tower) {
    return tower->pieces[0].type;
}

Piece *get_tower_pieces(Tower *tower) {
    return tower->pieces;
}
