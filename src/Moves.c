//
// Created by Giovanni Zeno on 15/12/2020.
//

#include "Cell.h"
#include "Board.h"
#include <stdlib.h>
#include <stdio.h>


Cell Move_UR(Cell *cell, Board *board){      //'ur' for UP and RIGHT, 'dl' for DOWN and LEFT
    Cell *move_ur;
    move_ur = get_cell(board, cell->x + 1, cell->y - 1);
    return *move_ur;
}

Cell Move_UL(Cell *cell, Board *board){
    Cell *move_ul;
    move_ul = get_cell(board, cell->x - 1, cell->y - 1);
    return *move_ul;
}

Cell Move_DL(Cell *cell, Board *board){
    Cell *move_dl;
    move_dl = get_cell(board, )
}

Cell Move_DR(Cell *cell, Board *board){
    Cell *move_dr;
    move_dr = get_cell(board, cell->x + 1, cell->y + 1);
}

Cell Eat_UR(Cell *cell, Board *board){
    Cell *eat_ur;
    eat_ur = get_cell(board, cell->x + 2, cell->y - 2);
}

Cell Eat_UL(Cell *cell, Board *board){
    Cell *eat_ul;
    eat_ul = get_cell(board, cell->x - 2, cell->y - 2);
}

Cell Eat_DL(Cell *cell, Board *board){
    Cell *eat_dl;
    eat_dl = get_cell(board, cell->x - 2, cell->y + 2);
}

Cell Eat_DR(Cell *cell, Board *board){
    Cell *eat_dr;
    eat_dr = get_cell(board, cell->x + 2, cell->y + 2);
}
