/**
 * @file Board.c
 * @author Paul Toffoloni
 * @date October 26, 2020
 * @brief File containing the source code for Lasca:
 * Board is the game field that contains every cell and every piece that make up the game.
 */
#include <stdlib.h>
#include <stdio.h>

#include "Board.h"
#include "Cell.h"
#include "Piece.h"

/**
 * Assigns memory to a board pointer and assigns rows and columns to it.
 * Creates then a matrix of cells and assigns coordinates to each one of them.
 * Finally assigns NULL to the piece pointer in every cell, so that the board is empty.
 */
Board* create_board(int rows, int columns) {
    int i, f;
    Board *board = malloc(sizeof(Board));
    board->rows = rows;
    board->columns = columns;
    board->cells = malloc(sizeof(Cell) * rows * columns);
    for (i = 0; i < rows; i++) {
        for (f = 0; f < columns; f++) {
            board->cells[i * columns + f].x = f + 1;
            board->cells[i * columns + f].y = i + 1;
            set_cell_empty(&board->cells[i * columns + f]);

            if ((i * columns + f) % 2 == 0) {
                board->cells[i * columns + f].color = WHITE;
            } else {
                board->cells[i * columns + f].color = BLACK;
            }
        }
    }
    return board;
}

void destroy_board(Board *board) {
    int i, f;
    for (i = 0; i < board->rows; i++) {
        for (f = 0; f < board->columns; f++) {
            free(&board->cells[i*board->columns + f].tower);
            free(&board->cells[i*board->columns + f]);
        }
    }
    free(board);
}

Cell* get_cell(Board *board, int x, int y) {
    int i, f;
    for (i = 0; i < board->rows; i++) {
        for (f = 0; f < board->columns; f++) {
            if (board->cells[i * board->columns + f].x == x && board->cells[i * board->columns + f].y == y) {
                return &board->cells[i * board->columns + f];
            }
        }
    }
    return NULL;
}

/**
 * Uses two different loops to initialize the board,
 * first for the red player and then for the yellow one.
 */
void init_board(Board* board) {
    int i, f;
    /* Initializes the red side of the board */
    for (i = 0; i < board->rows / 2; i++) {
        for (f = 0; f < board->columns; f++) {
            if (i % 2 == 0) {
                if (f % 2 == 0) {
                    init_piece(&board->cells[i * board->columns + f], BLACK);
                }
            } else if (f % 2 != 0) {
                init_piece(&board->cells[i * board->columns + f], BLACK);
            }
        }
    }
    /* Initializes the yellow side of the board*/
    for (i = board->rows; i > board->rows / 2; i--) {
        for (f = board->columns; f >= 0; f--) {
            if (i % 2 == 0) {
                if (f % 2 == 0) {
                    init_piece(&board->cells[i * board->columns + f], WHITE);
                }
            } else if (f % 2 != 0) {
                init_piece(&board->cells[i * board->columns + f], WHITE);
            }
        }
    }
}

void print_field(Board* board) {
    int i, f;
    printf("\n");
    for (i = 0; i < board->rows; i++) {
        printf("%d     ", i + 1);
        for (f = 0; f < board->columns; f++) {
            if (i % 2 == 0) {
                if (f % 2 == 0) {
                    print_cell_content(&board->cells[i * board->columns + f]);
                    printf("   ");
                }
            } else if (f % 2 != 0) {
                printf("   ");
                print_cell_content(&board->cells[i * board->columns + f]);
            }
        }
        printf("\n");
    }
    printf("\n      ");
    for (f = 0; f < board->columns; f++) {
        printf("%c  ", f + 'a');
    }
    printf("\n\n");
}
