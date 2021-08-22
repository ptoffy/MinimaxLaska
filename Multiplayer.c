#include <stdio.h>
#include "Board.h"
#include "Game.h"

Board* init();

int main() {

    Board *board = create_board(7, 7);
    Moves *possible_moves;

    Color turn = WHITE;
    int is_match_finished = true;
    int i = 0, x,  y, end = 1, move;

    init_board(board);

    while (i < 1000) {
        print_field(board);
        printf("Turno: %s\n", get_color_string(turn));
        possible_moves = calculate_moves(board, turn);
        if (possible_moves->size == 0) {
            printf("Partita finita, %s vince!", get_color_string(!turn));
            return 0;
        }
        move_piece(calculate_moves(board, turn));
        turn = !turn;
        i++;
    }

    //destroy_board(board);

}
