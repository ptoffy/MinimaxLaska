//
// Created by Giovanni Zeno on 15/12/2020.
//

#include "Cell.h"
#include "Board.h"
#include <stdlib.h>
#include <stdio.h>


/* check if the piece can move TODO: implement check eat */
int can_piece_move(Board *board, int x, int y){
    int check=0;
    if(get_cell(board,x+1,y+1)==NULL){
        check+=0;
    }else{
        if(get_cell(board,x+1,y+1)->piece==NULL){
            check+=1;
        }
    }
    if(get_cell(board,x+1,y-1)==NULL){
        check+=0;
    }else{
        if(get_cell(board,x+1,y-1)->piece==NULL){
            check+=1;
        }
    }
    if(get_cell(board,x-1,y+1)==NULL){
        check+=0;
    }else{
        if(get_cell(board,x-1,y+1)->piece==NULL){
            check+=1;
        }
    }
    if(get_cell(board,x-1,y-1)==NULL){
        check+=0;
    }else{
        if(get_cell(board,x-1,y-1)->piece==NULL){
            check+=1;
        }
    }

    return check;
}
