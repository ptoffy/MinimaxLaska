#include <stdio.h>
#include <stdlib.h>
#include "include/Cell.h"
#include "include/Piece.h"
#include "include/Board.h"

void movePiece(Board *board);
int checkInput(int x, int y);

int main(int argc, const char * argv[]) {
    Board *board = createBoard(7, 7);
    initBoard(board);
    printField(board);
}

void movePiece(Board *board) {
    int x, y;
    scanf("", &x);
    scanf("", &y);
    /*
     * Quando va tutto a buon fine, muovi la piece
     * Piece *piece = getPiece(getCell(board, x, y));
     */
}

int checkInput(int x, int y) {
    /* Gli input sono validi?
     * Se giusto, return 0;
     * Se sbagliato, return 1;
     */
}
