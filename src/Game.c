/**
 * @file Game.c
 * @author Paul Toffoloni
 * @date October 31, 2020
 * @brief File containing the source code for Lasca:
 * Game controls the whole game, so if a piece is moved or the game has to end,
 * this file is in charge of it.
 */

#include <Moves.h>
#include "Game.h"
#include "Cell.h"
#include "Board.h"
#include "Bool.h"

Moves *calculate_moves(Board *board, Color turn) {
    /* Creates an array of struct Moves, with each struct containing all Moves a piece can make.
     * Only pieces that can move are added to the array. */
    int x, y, i, f, end = 0;
    Moves *moves = malloc(sizeof(Moves) * 22);     /* This is a bidimensional array, each element contains an array of Moves associated to a piece */
    Moves *all_moves = malloc(sizeof(Moves) * 16);           /* This is a normal array containing all possible moves */
    Moves *all_conquer_moves = malloc(sizeof(Moves));   /* This array contains al possible conquer moves, if this is != NULL, this is returned instead of the normal array of moves*/
    Moves *inital_move = moves;                         /* This is just a placeholder pointer to keep track of the first element of the array, used for iteration. */
    /* Here we create the bidimensional array. */
    for (x = 1; x <= board->rows; x++) {
        for (y = 1; y <= board->columns; y++) {
            if (check_initial_input(board, x, y, turn, moves)) {
                moves++;
                end++;
            }
        }
    }
    /* Here we create the normal array. */
    all_moves->size = 0;
    all_moves->moves = malloc(sizeof(Move) * 44);
    all_conquer_moves->size = 0;
    all_conquer_moves->moves = malloc(sizeof(Move) * 44);
    moves = inital_move;
    for (f = 0; f < end; f++) {
        for (i = 0; i < moves->size; i++) {
            if (moves->moves[i].conquer) {
                all_conquer_moves->moves[all_conquer_moves->size] = moves->moves[i];
                all_conquer_moves->size++;
            } else {
                all_moves->moves[all_moves->size] = moves->moves[i];
                all_moves->size++;
            }
        }
        moves++;
    }
    return all_conquer_moves->size == 0 ? all_moves : all_conquer_moves;
}

bool check_initial_input(Board* board, int x, int y, Color turn, Moves *moves) {
    Cell *cell = get_cell(board, x, y);
    /* Check if the selected cell is inside the board */
    if (!is_cell_in_board(cell))
        return false;

    /* Check if the selected cell contains something */
    if (is_cell_empty(cell))
        return false;

    /* Check if the piece is of the corresponding color of the player */
    if (cell->tower->pieces[0].color != turn)
        return false;

    /* Check if a piece can actually move from its position */
    *moves = (cell->tower->pieces[0].type == OFFICER) ? officer_possible_moves(cell->tower, board, x, y) : soldier_possible_moves(cell->tower, board, x, y);
    if (moves->size == 0)
        return false;
    /* Finally, if all checks returned true, return true */
    return true;
}
