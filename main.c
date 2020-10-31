#include <stdio.h>
#include <stdlib.h>
#include "include/Cell.h"
#include "include/Piece.h"
#include "include/Board.h"

void move_piece(Board *board);
int check_input(int x, int y);

int main(int argc, const char * argv[]) {
    Board *board = create_board(7, 7);
    init_board(board);
    print_field(board);
}

void move_piece(Board *board) {
    int x, y;
    scanf("", &x);
    scanf("", &y);
    /*
     * Quando va tutto a buon fine, muovi la piece
     * Piece *piece = get_piece(get_cell(board, x, y));
     */
}

int check_input(int x, int y) {
    /* Gli input sono validi?
     * Se giusto, return 0;
     * Se sbagliato, return 1;
     */
}
