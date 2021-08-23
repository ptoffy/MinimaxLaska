/**
 * @file Tower.h
 * @author Paul Toffoloni
 * @date October 26, 2020
 * @brief Data types and methods used to handle a Tower.
 *
 * A tower is what the game is played with and is made up of an array of pieces.
 * This file is in charge of handling everything regarding towers,
 * like increasing or decreasing its height or promoting a soldier.
 */

#ifndef PIECE_H
#define PIECE_H

/**
 * Color that both indicates the color of a Cell and of a Piece.
 */
typedef enum Color {
    WHITE = 0,
    BLACK = 1
} Color;

/**
 * The type of the piece.
 */
typedef enum Type {
    SOLDIER = 0,          /**< Can only move forwards, if it reaches the other sides it becomes an officer. */
    OFFICER = 1           /**< Can move in every direction, is marked. */
} Type;

/**
 * @brief Single piece of a Tower.
 *
 * Piece represents the pieces that make up a tower,
 * containing a color and a type that can be, respectively,
 * White or Black and Officer or soldier.
 */
typedef struct Piece {
    Color color;         /**< The color of the piece, indicates the holder of the piece. */
    Type type;           /**< The type of the piece, indicated by the Type enum. */
} Piece;

/**
 * @brief Array of Piece.
 *
 * Every piece used in the game is a tower, starting from height = 1,
 * it can grow taller by conquering different pieces.
 * The first element of the tower, placed in position 0, is the one that controls the tower,
 * also indicating it's color.
 * When the tower gets conquered, that is the piece that gets conquered along with its same color pieces,
 * while the rest of the pieces (of the opposite color) are left in position to create a new tower.
 */
typedef struct Tower {
    int height;         /**< The height of the piece. */
    Piece *pieces;      /**< Array containing the pieces the Tower is made up of. */
} Tower;


/**
 * Increases the height of the tower by one.
 * @param tower The Tower of which the height is getting increased.
 */
void increase_height(Tower *tower);

/**
 * Decreases the height of the tower by one.
 * @param tower The Tower of which the height is getting decreased.
 */
void decrease_height(Tower *tower);

/**
 * Promotes a Soldier Tower to an Officer Tower.
 * @param tower The Tower to be promoted.
 */
void promote(Tower *tower);

/**
 * Returns a string representing a Color, in italian.
 * @param color The color to be represented.
 * @return The created string.
 */
const char*
get_color_string(Color color);

/**
 * Returns the pieces array for the selected Tower.
 * @param tower The selected Tower.
 * @return The Piece array for the selected Tower
 */
Piece *
get_tower_pieces(Tower *tower);

/**
 * Returns the Type for the selected Tower.
 * @param tower The selected Tower.
 * @return The Type for the selected Tower
 */
Type
get_tower_type(Tower *tower);

/**
 * Returns the Color for the selected Tower.
 * @param tower The selected Tower.
 * @return The Color for the selected Tower
 */
Color
get_tower_color(Tower *tower);

#endif /* PIECE_H */
