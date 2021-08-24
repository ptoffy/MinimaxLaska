/**
 * @file Game.c
 * @author Paul Toffoloni
 * @date October 31, 2020
 * @brief Methods to handle a game.
 *
 * This file is in charge of handling the game,
 * calculating all possible moves inside the board
 * and checking if a move can be made.
 */

#include <stdio.h>
#include "Moves.h"
#include "Game.h"
#include "Cell.h"
#include "Board.h"
#include "Bool.h"

void user_move_piece(Moves *moves) {
    int i, selected = 0, input;
    bool moved = false;
    for (i = 0; i < moves_get_size(moves); i++)
        print_move(&moves_get_moves(moves)[i], i + 1);
    while (!moved) {
        printf("Inserisci la tua mossa: ");
        /* Here we save the scanf result into input to check if the input is numeric or not (1 or 0) */
        input = scanf("%d", &selected);
        while (!input || selected >= moves_get_size(moves) + 1 || selected < 1) {
            printf("Inserisci un numero valido: \n");
            for (i = 0; i < moves_get_size(moves); i++)
                print_move(&moves_get_moves(moves)[i], i + 1);
            /* This is needed because without it we end up in an infinite loop, since the scanf statement
             * keeps reading the same input as the one before */
            fflush(stdin);
            input = scanf("%d", &selected);
        }
        make_move(&moves_get_moves(moves)[selected - 1], move_get_conquer(&moves_get_moves(moves)[selected - 1]));
        check_for_promotion(&moves_get_moves(moves)[selected - 1]);
        moved = true;
    }
    free(moves);
}

Moves *calculate_moves(Board *board, Color turn) {
    /* Creates an array of struct Moves, with each struct containing all Moves a piece can make.
     * Only pieces that can move are added to the array. */
    int x, y, i;
    Moves *moves;                                             /* This is a two-dimensional array, each element contains an array of Moves associated to a piece */
    Moves *all_moves = new_moves(44);               /* This is a normal array containing all possible moves */
    Moves *all_conquer_moves = new_moves(44);        /* This array contains all possible conquer moves, if this is not empty, this is returned instead of the normal array of moves*/

    for (x = 1; x <= board_get_rows(board); x++) {
        for (y = 1; y <= board_get_columns(board); y++) {
            if (!can_tower_move(board, x, y, turn))
                continue;
            moves = tower_possible_moves(cell_get_tower(board_get_cell(board, x, y)), board, x, y);
            for (i = 0; i < moves_get_size(moves); i++) {
                if (move_get_conquer(&moves_get_moves(moves)[i])) {
                    all_conquer_moves->moves[moves_get_size(all_conquer_moves)] = *moves_get_move(moves, i);
                    moves_set_size(all_conquer_moves, moves_get_size(all_conquer_moves) + 1);
                } else {
                    all_moves->moves[moves_get_size(all_moves)] = *moves_get_move(moves, i);
                    moves_set_size(all_moves, moves_get_size(all_moves) + 1);
                }
            }
        }
    }
    return moves_get_size(all_conquer_moves) == 0 ? all_moves : all_conquer_moves;
}

bool can_tower_move(Board* board, int x, int y, Color turn) {
    Cell *cell = board_get_cell(board, x, y);
    /* Check if the selected cell is inside the board */
    if (!is_cell_in_board(cell))
        return false;

    /* Check if the selected cell contains something */
    if (is_cell_empty(cell))
        return false;

    /* Check if the piece is of the corresponding color of the player */
    if (tower_get_color(cell_get_tower(cell)) != turn)
        return false;

    /* Check if a piece can actually move from its position */
    return moves_get_size(tower_possible_moves(cell_get_tower(cell), board, x, y)) == 0 ? false : true;
}
