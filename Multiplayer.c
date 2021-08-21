#include <stdio.h>
#include "Board.h"
#include "Game.h"

Board* init();

int main() {

    Board *board = create_board(7, 7);

    int turn = WHITE;
    int is_match_finished = true;
    int i = 0, x,  y;
    int end = 1;
    int move;

    init_board(board);

    while (i < 1000) {
        print_field(board);
        printf("Turno: %s\n", get_color_string(turn));
        move_piece(calculate_moves(board, turn));
        turn = !turn;
        i++;
    }

    //destroy_board(board);

}
