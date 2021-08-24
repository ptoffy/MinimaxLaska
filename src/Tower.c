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

#include <stdlib.h>
#include "Tower.h"

Tower *init_tower(Color color) {
    Tower *tower = malloc(sizeof(Tower));
    tower->pieces = malloc(sizeof(Piece));
    tower->height = 1;
    tower->pieces[0].color = color;
    tower->pieces[0].type = SOLDIER;
    return tower;
}

void increase_height(Tower *tower) {
    tower->height += 1;
}

void decrease_height(Tower *tower) {
    tower->height -= 1;
}

void promote(Tower *tower) {
    tower->pieces[0].type = OFFICER;
}

Color tower_get_color(Tower *tower) {
    return tower->pieces[0].color;
}

Type tower_get_type(Tower *tower) {
    return tower->pieces[0].type;
}

Piece *tower_get_pieces(Tower *tower) {
    return tower->pieces;
}

Piece tower_get_piece(Tower *tower, int i) {
    return tower->pieces[i];
}

int tower_get_height(Tower *tower) {
    return tower->height;
}

void tower_set_type(Tower *tower, Type type) {
    tower->pieces[0].type = type;
}
