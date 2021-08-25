/**
 * @file MinimaxAI.h
 * @author Paul Toffoloni
 * @date August 25, 2021
 * @brief Minimax algorithm.
 *
 * This file contains to choose a Move for the CPU using
 * the Minimax algorithm.
 */

#ifndef LASCA_MINIMAXAI_H
#define LASCA_MINIMAXAI_H

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include "SinglePlayer.h"
#include "Board.h"
#include "Bool.h"
#include "Game.h"

/**
 * @brief Evaluates a Move using the Board.
 *
 * Using the number of current pieces and current kings,
 * calculates how good the situation for a player after performing a Move.
 * The formula that is being used: (white_pieces - black_pieces) * (white_kings * 0.5 + black_kings * 0.5)
 * indicates how the evaluation is calibrated. The best thing that can happen in a Move is conquering a piece,
 * if no conquest is possible than we'll check if we can promote a Soldier to an Officer. These parameters can
 * be adjusted as pleased.
 * @param board The board to be evaluated.
 * @return A number indicating the evaluation
 */
int evaluate(Board *board);

/**
 * @brief Chooses a Move to be played using the Minimax algorithm.
 *
 * @b Minimax @b Algorithm: the Minimax algorithm creates a game tree
 * based on all of the possible moves a player can make. Every level of the tree,
 * indicated by the @p depth, contains the children of the @p depth + 1, meaning
 * every Move the opposite user can make after the user has chosen one of the moves.
 * Once the tree has been generated, it recursively traverses the tree adding a value
 * to every move, this value depends on how useful the Move is for a user, for example if
 * it can conquer a piece or make a piece become officer. The higher the value, the
 * better it is for the @p maximizing_player. Then, it chooses between Moves
 * of the same level comparing these values, if the turn that is being checked is the @p maximizing_player's
 * one, chooses the highest value, if not it chooses the lowest, since it is the worst decision to make
 * for the opponent. Finally, it copies the best Move into the @move so that we can use it to perform that move.
 * @param move The Move that is being checked.
 * @param depth How many turns the AI is checking to choose the Move, the higher this number is, the higher
 * the computing power is needed to search the Move. The computational complexity is @b O(b^m),
 * where b is the number of legal moves at each point and m is the maximum depth of the tree.
 * @param maximizing_player The player who is playing and who has to get the best Move.
 * @param board The board which we are the moves simulating on.
 * @return The best Move the AI can make.
 */
int
minimax(Move *move, int depth, Color maximizing_player, Board *board);

#endif //LASCA_MINIMAXAI_H
