#include "Board.h"
#include "Game.h"
#include <stdio.h>

Board* init();

int main() {

    Board *board = create_board(7, 7);

    int turn = BLACK;
    int is_match_finished = 0;
    int i = 0, x,  y;
    int end = 1;

    init_board(board);

    while (i < 10) {

        turn = WHITE;
        print_field(board);
        x = get_x_input_coordinate();
        y = get_y_input_coordinate();
        if (get_cell(board, x, y) != NULL) {
            if (check_initial_input(board, x, y) == 1) {
                printf("Inserisci le coordinate di arrivo\n");
            }
        } else {
            printf("La pedina selezionata non fa parte del campo");
        }
    }

}
