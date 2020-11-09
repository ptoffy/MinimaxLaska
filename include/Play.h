#ifndef LASCA_PLAY_H
#define LASCA_PLAY_H

#include "Cell.h"

typedef enum PlayType {
    movement = 0,
    conquer = 1
} PlayType;

typedef struct Play {
    int type;
    Cell *firstCell;
} Play;

#endif //LASCA_PLAY_H
