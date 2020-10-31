#ifndef Piece_h
#define Piece_h

#include <stdio.h>

/**
 * The type of the piece.
 */
enum Type {
    soldier = 0,  /**< Can only move forwards, if it reaches the other sides it becomes an officer. */
    officer = 1,  /**< Can move in every direction, is marked. */
    column = 2,   /**< A stack formed of more than one soldier or officer, is controlled by the commander. */
    commander = 3 /**< Highest piece of the column, controls the column, if it's officer the column can move in every direction. */
};

/**
 * The color that a piece can have.
 */
enum Color {
    red = 0, /**< Red color for player 1. */
    yellow = 1 /**< Yellow color for player 2. */
};

/**
 * The game piece.
 */
typedef struct Piece {
    int color;  /**< The color of the piece, indicates the holder of the piece. */
    int height; /**< The height of the piece. */
    int type;   /**< The type of the piece, indicated by the Type enum. */
} Piece;

void setHeight(Piece *piece, int height);
void increaseHeight(Piece *piece);
void lowerHeight(Piece *piece);

#endif /* Piece_h */
