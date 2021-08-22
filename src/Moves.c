/**
 * @file Moves.h
 * @author Paul Toffoloni
 * @date August 19, 2021
 * @brief File containing the definition and usage for Lasca:
 * Move is a move available to a Tower, it contains an origin cell, a destination cell, and,
 * if the move is a conquer move, an "eaten" cell, which is the cell that gets conquered.
 * Moves is an array containing a list of moves.
 */

#include "Moves.h"
#include <stdio.h>
#include <string.h>

Moves new_moves() {
    Moves moves;
    moves.moves = malloc(sizeof(Move) * 16);
    moves.size = 0;
    return moves;
}

Move new_move(Cell *origin, Cell *destination) {
    Move move;
    move.destination = destination;
    move.origin = origin;
    move.conquer = false;
    move.eaten = NULL;
    return move;
}

Move new_conquer_move(Cell *origin, Cell *destination, Cell *eaten) {
    Move move;
    move.destination = destination;
    move.origin = origin;
    move.conquer = true;
    move.eaten = eaten;
    return move;
}

void add_move(Move move, Moves *moves) {
    moves->moves[moves->size] = move;
    moves->size++;
}

void make_move(Move *move, bool conquer) {
    if (conquer) {
        conquer_tower(move);
        move->origin->tower = NULL;
    } else {
        move->destination->tower = move->origin->tower;
        move->origin->tower = NULL;
    }
}

void conquer_tower(Move *move) {
    int i;
    /* Place the controlling piece of the conquered tower on top of the conqueror tower */
    increase_height(move->origin->tower);
    move->destination->tower = move->origin->tower;
    move->destination->tower->pieces[move->destination->tower->height - 1] = move->eaten->tower->pieces[0];
    /* Remove the controlling piece of the conquered tower and lower the tower's height by one */
    if (move->eaten->tower->height == 1)
        move->eaten->tower = NULL;
    else {
        for (i = 1; i < move->eaten->tower->height; i++) {
            move->eaten->tower->pieces[i-1] = move->eaten->tower->pieces[i];
        }
        decrease_height(move->eaten->tower);
    }
}

void check_for_promotion(Move *move) {
    if (move->destination->tower->pieces[0].color == WHITE) {
        if (move->destination->y == 1)
            promote(move->destination->tower);
    } else if (move->destination->y == 7)
        promote(move->destination->tower);
}

void add_to_possible_moves(Cell *origin_cell, Cell *destination_cell, Cell *conquer_destination_cell, Color color, Moves *moves) {
    if (is_cell_in_board(destination_cell)) {
        if (is_cell_empty(destination_cell)) {
            add_move(new_move(origin_cell, destination_cell), moves);
        } else {
            if (is_cell_in_board(conquer_destination_cell) && destination_cell->tower->pieces[0].color == color && is_cell_empty(conquer_destination_cell)) {
                add_move(new_conquer_move(origin_cell, conquer_destination_cell, destination_cell), moves);
            }
        }
    }
}

Moves soldier_possible_moves(Tower *tower, Board *board, int x, int y) {
    Moves moves = new_moves();
    if (tower->pieces[0].color == BLACK) {
        add_to_possible_moves(get_cell(board, x, y),
                              get_cell(board, x + 1, y + 1),
                              get_cell(board, x + 2, y + 2),
                              WHITE, &moves);
        add_to_possible_moves(get_cell(board, x, y),
                              get_cell(board, x - 1, y + 1),
                              get_cell(board, x - 2, y + 2),
                              WHITE, &moves);
    } else {
        add_to_possible_moves(get_cell(board, x, y),
                              get_cell(board, x + 1, y - 1),
                              get_cell(board, x + 2, y - 2),
                              BLACK, &moves);
        add_to_possible_moves(get_cell(board, x, y),
                              get_cell(board, x - 1, y - 1),
                              get_cell(board, x - 2, y - 2),
                              BLACK, &moves);
    }
    return moves;
}

Moves officer_possible_moves(Tower *tower, Board *board, int x, int y) {
    Moves moves = soldier_possible_moves(tower, board, x, y);
    Cell *cell;
    /* For every cell around the selected cell, check if it exists and if we can move or eventually conquer there */
    if (tower->pieces[0].color == BLACK) {
        add_to_possible_moves(get_cell(board, x, y),
                              get_cell(board, x + 1, y - 1),
                              get_cell(board, x + 2, y - 2),
                              WHITE, &moves);
        add_to_possible_moves(get_cell(board, x, y),
                              get_cell(board, x - 1, y - 1),
                              get_cell(board, x - 2, y - 2),
                              WHITE, &moves);
    } else {
        add_to_possible_moves(get_cell(board, x, y),
                              get_cell(board, x + 1, y + 1),
                              get_cell(board, x + 2, y + 2),
                              BLACK, &moves);
        add_to_possible_moves(get_cell(board, x, y),
                              get_cell(board, x - 1, y + 1),
                              get_cell(board, x - 2, y + 2),
                              BLACK, &moves);
    }
    return moves;
}

void print_move(Move *move, int i) {
    if (move->conquer)
        printf("%d) %c%d - %c%d - %c%d\n", i, move->origin->x + 'a' - 1, move->origin->y,
               move->eaten->x + 'a' - 1, move->eaten->y,
               move->destination->x + 'a' - 1, move->destination->y);
    else
        printf("%d) %c%d - %c%d\n", i, move->origin->x + 'a' - 1, move->origin->y,
               move->destination->x + 'a' - 1, move->destination->y);
}
