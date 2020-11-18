#ifndef LASCA_PLAY_H
#define LASCA_PLAY_H

#include "Cell.h"

/**
 * Play represents a Play that either the person or the computer makes.
 */
typedef struct Play {
    int gain; /**< Represents how many pieces we can eat after the move is complete. */
    int risk; /**< Represents how risky a move is, so how many pieces can eat our piece after the move is complete. */
    int color; /**< Represents who is making the move. */
    int piece_type; /**< Represents the type of piece that is being used. */
    Cell *initial_cell; /**< Represents the cell where there is the first piece, so where the piece is before the move. */
    Cell *arrival_cell; /**< Represents the cell where the piece is going. */
} Play;

/**
 * Creates a new Play based on the parameters.
 * @param gain Represents how many pieces we can eat after the move is complete.
 * @param risk Represents how risky a move is, so how many pieces can eat our piece after the move is complete.
 * @param color Represents who is making the move.
 * @param piece_type Represents the type of piece that is being used.
 * @param initial_cell Represents the cell where there is the first piece, so where the piece is before the move.
 * @param arrival_cell Represents the cell where the piece is going.
 * @return The newly created play.
 */
Play *new_play(int gain, int risk, int color, int piece_type, Cell *initial_cell, Cell *arrival_cell);



#endif //LASCA_PLAY_H
