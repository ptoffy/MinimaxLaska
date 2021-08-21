/**
 * @file Piece.h
 * @author Paul Toffoloni
 * @date October 26, 2020
 * @brief File containing the definition and usage for Lasca:
 * Piece represents the pieces that the players play with.
 */
#ifndef Piece_h
#define Piece_h

typedef enum Color {
    WHITE = 0,
    BLACK = 1
} Color;

/**
 * The type of the piece.
 */
typedef enum Type {
    SOLDIER = 0,  /**< Can only move forwards, if it reaches the other sides it becomes an officer. */
    OFFICER = 1   /**< Can move in every direction, is marked. */
} Type;

/**
 * Piece represents the pieces that the players play with.
 */
typedef struct Piece {
    Color color; /**< The color of the piece, indicates the holder of the piece. */
    Type type; /**< The type of the piece, indicated by the Type enum. */
} Piece;

/**
 * Represents a tower, made up of different pieces.
 */
typedef struct Tower {
    int height; /**< The height of the piece. */
    Piece *pieces;
} Tower;


/**
 * Increases the height of the tower by one.
 * @param tower The tower of which the height is getting increased.
 */
void increase_height(Tower *tower);

/**
 * Decreases the height of the tower by one.
 * @param tower The tower of which the height is getting decreased.
 */
void decrease_height(Tower *tower);

/**
 * Promotes a Soldier Tower to an Officer Tower.
 * @param tower The Tower to be promoted.
 */
void promote(Tower *tower);

#endif /* Piece_h */
