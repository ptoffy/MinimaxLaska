/**
 * @file Multiplayer.h
 * @author Paul Toffoloni
 * @date August 19, 2021
 * @brief File containing the definition and usage for Lasca:
 * Multiplayer contains all methods needed to play a player vs player game.
 */

#include <stdio.h>
#include "Board.h"
#include "Game.h"

void move_piece(Moves *moves) {
    int i, selected = 0;
    bool moved = false;
    for (i = 0; i < moves->size; i++)
        print_move(&moves->moves[i], i + 1);

    while (!moved) {
        printf("Inserisci la tua mossa: ");
        scanf("%d", &selected);
        while (selected >= moves->size + 1 || selected < 1) {
            printf("Inserisci un numero valido: \n");
            for (i = 0; i < moves->size; i++)
                print_move(&moves->moves[i], i + 1);
            scanf("%d", &selected);
        }
        make_move(&moves->moves[selected - 1], moves->moves[selected - 1].conquer);
        check_for_promotion(&moves->moves[selected - 1]);
        moved = true;
    }
}

void run_multiplayer() {
    Board *board = create_board(7, 7);
    Moves *possible_moves;

    Color turn = WHITE;
    int i = 0;

    init_board(board);

    printf("Bianco inizia!");

    while (true) {
        print_field(board);
        printf("Turno: %s\n", get_color_string(turn));
        possible_moves = calculate_moves(board, turn);
        if (possible_moves->size == 0) {
            printf("Partita finita, %s vince!", get_color_string(!turn));
            break;
        }
        move_piece(calculate_moves(board, turn));
        turn = !turn;
        i++;
    }
    destroy_board(board);
}
