//
// Created by Giovanni Zeno on 15/12/2020.
//

#ifndef LASCA_MOVES_H
#define LASCA_MOVES_H

#include <stdlib.h>
#include "Cell.h"

#include "Board.h"

typedef struct Moves{
    Cell Move_UR;
    Cell *move_ul;
    int bailamorena;
}Moves;



Cell Move_UR(Cell *cell , Board *board);

Cell Move_UL(Cell *cell, Board *board);

Cell Move_DL(Cell *cell, Board *board);

Cell Move_DR(Cell *cell, Board *board);

Cell Eat_UR(Cell *cell, Board *board);

Cell Eat_UL(Cell *cell, Board *board);

Cell Eat_DL(Cell *cell, Board *board);


#endif //LASCA_MOVES_H

