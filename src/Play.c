#include "Play.h"

Play *new_play(int gain, int risk, int color, int piece_type, Cell *initial_cell, Cell *arrival_cell) {
    Play *play = malloc(sizeof(Play));
    play->gain = gain;
    play->risk = risk;
    play->color = color;
    play->piece_type = piece_type;
    play->initial_cell = initial_cell;
    play->arrival_cell = arrival_cell;
    return play;
}









