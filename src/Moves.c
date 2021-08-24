/**
 * @file Moves.c
 * @author Paul Toffoloni
 * @date August 19, 2021
 * @brief Moves contains all the data types and methods used to handle moves.
 *
 * Move is a move available to a Tower, it contains an origin cell, a destination cell, and,
 * if the move is a conquer move, an "eaten" cell, which is the cell that gets conquered.
 * Moves is an array containing a list of moves.
 */

#include <stdio.h>
#include <string.h>
#include "Moves.h"


Moves *new_moves(size_t moves_size) {
    Moves *moves = malloc(sizeof (Moves));
    moves->moves = malloc(sizeof (Move) * moves_size);
    moves->size = 0;
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
    conquer ? conquer_tower(move) : cell_set_tower(move->destination, cell_get_tower(move->origin));
    cell_set_tower(move->origin, NULL);
}

void conquer_tower(Move *move) {
    int i;
    /* Place the controlling piece of the conquered tower on top of the conqueror tower */
    increase_height(cell_get_tower(move->origin));
    cell_set_tower(move->destination, cell_get_tower(move->origin));
    move->destination->tower->pieces[tower_get_height(cell_get_tower(move->destination)) - 1] = tower_get_piece(cell_get_tower(move->eaten), 0);
    /* Remove the controlling piece of the conquered tower and lower the tower's height by one */
    if (tower_get_height(cell_get_tower(move->eaten)) == 1)
        cell_set_tower(move->eaten, NULL);
    else {
        for (i = 1; i < tower_get_height(cell_get_tower(move->eaten)); i++)
            move->eaten->tower->pieces[i - 1] = tower_get_piece(cell_get_tower(move->eaten), i);
        decrease_height(cell_get_tower(move->eaten));
    }
}

void check_for_promotion(Move *move) {
    Tower *tower = cell_get_tower(move->destination);
    if (tower_get_color(tower) == WHITE) {
        if (get_y_coordinate(move->destination) == 1)
            promote(tower);
    } else if (get_y_coordinate(move->destination) == 7)
        promote(tower);
}

void add_to_possible_moves(Cell *origin_cell, Cell *destination_cell, Cell *conquer_destination_cell, Color color, Moves *moves) {
    if (is_cell_in_board(destination_cell)) {
        if (is_cell_empty(destination_cell)) {
            add_move(new_move(origin_cell, destination_cell), moves);
        } else if (is_cell_in_board(conquer_destination_cell) && tower_get_color(cell_get_tower(destination_cell)) == color && is_cell_empty(conquer_destination_cell)) {
            add_move(new_conquer_move(origin_cell, conquer_destination_cell, destination_cell), moves);
        }
    }
}

Moves *tower_possible_moves(Tower *tower, Board *board, int x, int y) {
    return tower_get_type(tower) == SOLDIER ? soldier_possible_moves(tower, board, x, y) : officer_possible_moves(tower, board, x, y);
}

Moves *soldier_possible_moves(Tower *tower, Board *board, int x, int y) {
    Moves *moves = new_moves(16);
    if (tower_get_color(tower) == BLACK) {
        add_to_possible_moves(board_get_cell(board, x, y),
                              board_get_cell(board, x + 1, y + 1),
                              board_get_cell(board, x + 2, y + 2),
                              WHITE, moves);
        add_to_possible_moves(board_get_cell(board, x, y),
                              board_get_cell(board, x - 1, y + 1),
                              board_get_cell(board, x - 2, y + 2),
                              WHITE, moves);
    } else {
        add_to_possible_moves(board_get_cell(board, x, y),
                              board_get_cell(board, x + 1, y - 1),
                              board_get_cell(board, x + 2, y - 2),
                              BLACK, moves);
        add_to_possible_moves(board_get_cell(board, x, y),
                              board_get_cell(board, x - 1, y - 1),
                              board_get_cell(board, x - 2, y - 2),
                              BLACK, moves);
    }
    return moves;
}

Moves *officer_possible_moves(Tower *tower, Board *board, int x, int y) {
    Moves *moves = soldier_possible_moves(tower, board, x, y);
    /* For every cell around the selected cell, check if it exists and if we can move or eventually conquer there */
    if (tower_get_color(tower) == BLACK) {
        add_to_possible_moves(board_get_cell(board, x, y),
                              board_get_cell(board, x + 1, y - 1),
                              board_get_cell(board, x + 2, y - 2),
                              WHITE, moves);
        add_to_possible_moves(board_get_cell(board, x, y),
                              board_get_cell(board, x - 1, y - 1),
                              board_get_cell(board, x - 2, y - 2),
                              WHITE, moves);
    } else {
        add_to_possible_moves(board_get_cell(board, x, y),
                              board_get_cell(board, x + 1, y + 1),
                              board_get_cell(board, x + 2, y + 2),
                              BLACK, moves);
        add_to_possible_moves(board_get_cell(board, x, y),
                              board_get_cell(board, x - 1, y + 1),
                              board_get_cell(board, x - 2, y + 2),
                              BLACK, moves);
    }
    return moves;
}

void print_move(Move *move, int i) {
    if (move_get_conquer(move))
        printf("%d) %c%d - %c%d - %c%d\n", i,
               get_x_coordinate(move_get_origin_cell(move)) + 'a' - 1, get_y_coordinate(move_get_origin_cell(move)),
               get_x_coordinate(move_get_eaten_cell(move)) + 'a' - 1, get_y_coordinate(move_get_eaten_cell(move)),
               get_x_coordinate(move_get_destination_cell(move)) + 'a' - 1,  get_y_coordinate(move_get_destination_cell(move)));
    else
        printf("%d) %c%d - %c%d\n", i,
               get_x_coordinate(move_get_origin_cell(move))+ 'a' - 1, get_y_coordinate(move_get_origin_cell(move)),
               get_x_coordinate(move_get_destination_cell(move)) + 'a' - 1, get_y_coordinate(move_get_destination_cell(move)));
}

size_t moves_get_size(Moves *moves) {
    return moves->size;
}

void moves_set_size(Moves *moves, size_t size) {
    moves->size = size;
}

Move *moves_get_move(Moves *moves, int i) {
    return &moves->moves[i];
}

Move *moves_get_moves(Moves *moves) {
    return moves->moves;
}

Cell *move_get_origin_cell(Move *move) {
    return move->origin;
}

Cell *move_get_destination_cell(Move *move) {
    return move->destination;
}

Cell *move_get_eaten_cell(Move *move) {
    return move->eaten;
}

bool move_get_conquer(Move *move) {
    return move->conquer;
}
