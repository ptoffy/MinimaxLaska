#include "Board.h"
#include "Game.h"

Board* init();

int main() {

    Board *board = create_board(7, 7);

    int turn = red;
    int is_match_finished = 0;
    int i=0;

    init_board(board);

    while (i<100) {
        print_field(board);
        move_piece(board, turn);
        turn = yellow;

        is_match_finished = 1;

        print_field(board);
        move_piece(board, turn);
        turn = red;
    }

}
