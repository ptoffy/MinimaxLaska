#include <stdlib.h>
#include "include/Board.h"
#include "include/Cell.h"
#include "include/Piece.h"

/**
 * Assigns memory to a board pointer and assigns rows and columns to it.
 * Creates then a matrix of cells and assigns coordinates to each one of them.
 * Finally assigns NULL to the piece pointer in every cell, so that the board is empty.
 */
Board* createBoard(int rows, int columns) {
    int i, f;
    Board *board = malloc(sizeof(Board));
    board->rows = rows;
    board->columns = columns;
    board->cells = malloc(sizeof(Cell) * rows * columns);
    for (i = 0; i < rows; i++) {
        for (f = 0; f < columns; f++) {
            board->cells[i * columns + f].x = f;
            board->cells[i * columns + f].y = i;
            setPieceToNull(&board->cells[i * columns + f]);
        }
    }
    return board;
}

/**
 * Assigns memory to a pointer piece and assigns that attribute to the chosen cell.
 * Assigns then the initial settings for a piece to that pointer
 */
void initPiece(Cell* cell, int color) {
    Piece* piece = malloc(sizeof(Piece));
    cell->piece = piece;
    piece->height = 1;
    piece->color = color;
    piece->type = soldier;
}

Cell* getCell(Board *board, int x, int y) {
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
 Uses two different loops to initialize the board, first for the red player and then for the yellow one.
 */
void initBoard(Board* board) {
    int i, f;
    /* Initializes the red side of the board */
    for (i = 0; i < board->rows / 2; i++) {
        for (f = 0; f < board->columns; f++) {
            if (i % 2 == 0) {
                if (f % 2 == 0) {
                    initPiece(&board->cells[i * board->columns + f], red);
                }
            } else {
                if (f % 2 != 0) {
                    initPiece(&board->cells[i * board->columns + f], red);
                }
            }
        }
    }
    /* Initializes the yellow side of the board*/
    for (i = board->rows; i > board->rows / 2; i--) {
        for (f = board->columns; f >= 0; f--) {
            if (i % 2 == 0) {
                if (f % 2 == 0) {
                    initPiece(&board->cells[i * board->columns + f], yellow);
                }
            } else {
                if (f % 2 != 0) {
                    initPiece(&board->cells[i * board->columns + f], yellow);
                }
            }
        }
    }
}

void printField(Board* board) {
    int i, f;
    for (i = 0; i < board->rows; i++) {
        printf("%d   ", i + 1);
        for (f = 0; f < board->columns; f++) {
            if (i % 2 == 0) {
                if (f % 2 == 0) {
                    printCellContent(&board->cells[i * board->columns + f]);
                    printf("  ");
                }
            } else if (f % 2 != 0) {
                printf("  ");
                printCellContent(&board->cells[i * board->columns + f]);
            }
        }
        printf("\n");
    }
    printf("\n    ");
    for (f = 0; f < board->columns; f++) {
        printf("%d ", f + 1);
    }
    printf("\n\n");
}

void printBoard() {
    int foo = 0;
    int i, f;
    int MAX_X = 36;
    int MAX_Y = 36;
    /* Ciclo columns */
    for (i = 0; i < MAX_Y; i++) {
        /* Ciclo rows */
        for (f = 0; f < MAX_X; f++) {
            /* Se la riga è un divisore */
            if (i % 5 == 0) {
                if (f % (MAX_X - 1) == 0) {
                    printf("+");
                } else {
                    printf("-");
                }
            } else {
                /* Se la colonna è un margine */
                if (f % 5 == 0) {
                    printf("|");
                } else {
                    if (foo == 0) {
                        printf("#");
                    } else {
                        printf(" ");
                    }
                }
            }
            if (f % 5 == 0) {
                foo = !foo;
            }
        }
        printf("\n");
        if (i % 5 == 0) {
            foo = !foo;
        }
    }
    printf("\n");
}
