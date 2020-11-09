#include "Board.h"
#include "Game.h"

Board* init();

int main(int argc, const char * argv[]) {
    Board *board = create_board(7, 7);
    init_board(board);

    print_field(board);

    move_piece(board);

    print_field(board);

    move_piece(board);

    print_field(board);
//    int i, f;
//    for (i = 0; i < board->rows; i++) {
//        for (f = 0; f < board->columns; f++) {
//                printf("%d,%d ", board->cells[i*column + f].x, board->cells[i*column + f].y);
//           // printf("%p ", (void*) board->cells[i*column + f].piece);
//        }
//        printf("\n");
//    }
}
