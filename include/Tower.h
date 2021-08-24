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
 * @brief Getter for the Tower pieces array.
 *
 * Returns the pieces array for the selected Tower.
 * @param tower The selected Tower.
 * @return The Piece array for the selected Tower
 */
Piece *
tower_get_pieces(Tower *tower);

/**
 * @brief Getter for a Piece of the Tower.
 *
 * Returns the Piece of the selected Tower.
 * @param tower The tower we need a Piece from.
 * @param i The index of the Piece.
 * @return The Piece of the Tower.
 */
Piece
tower_get_piece(Tower *tower, int i);

/**
 * @brief Getter for the Tower Type.
 *
 * Returns the Type for the selected Tower.
 * @param tower The selected Tower.
 * @return The Type for the selected Tower
 */
Type
tower_get_type(Tower *tower);

/**
 * @brief Getter for the Tower Color.
 *
 * Returns the Color for the selected Tower.
 * @param tower The selected Tower.
 * @return The Color for the selected Tower
 */
Color
tower_get_color(Tower *tower);

/**
 * @brief Getter for the Tower height.
 *
 * Returns the Color for the selected Tower.
 * @param tower The selected Tower.
 * @return The Color for the selected Tower
 */
int
tower_get_height(Tower *tower);

/**
 * @brief Setter fot the Tower Type.
 *
 * Sets the Type of the Tower according to the parameter.
 * @param tower The Tower of which the Type has to be set.
 * @param type The Type to be set.
 */
void
tower_set_type(Tower *tower, Type type);

/**
 * @brief Tower constructor.
 *
 * Creates a new Tower pointer.
 * @param color The Color of the new Tower.
 * @return A new Tower.
 */
Tower *
init_tower(Color color);

#endif /* PIECE_H */
