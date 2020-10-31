#include "include/Piece.h"

void setHeight(Piece *piece, int height) {
    piece->height = height;
}

void increaseHeight(Piece *piece) {
    piece->height += 1;
}

void lowerHeight(Piece *piece) {
    piece->height -= 1;
}
