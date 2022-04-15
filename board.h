#ifndef BOARD_H
#define BOARD_H

#include <string>
#include "piece.h"

/**
 * Class that implements a board of the game.
 */
class Board {
private:
    int boardSize; // the size dimension of the board, which must always be equal to 14 (the board is a 14 x 14 area)
    Square squares[14][14]; // a 14 x 14 board of squares
public:
    /**
     * Initializes this board, by creating a 14 x 14 array of squares.
     *
     * Hint: we have to use a loop over all squares, and for each individual square we have to set its row and column.
     */
    Board();

    /**
     * Checks if a square placed in (x, y) is occupied by a piece.
     *
     * @param x the row of the square.
     * @param y the column of the square.
     * @return true if the square is occupied by a piece, or false otherwise.
     */
    bool hasPiece(int x, int y);

    /**
     * Checks if a square placed in (x, y) is occupied by a specific player piece.
     *
     * @param x the row of the square.
     * @param y the column of the square.
     * @param player the player of the square.
     * @return true if the square is occupied by a piece of the player, or false otherwise.
     */
    bool hasPlayerPiece(int x, int y, char player);

    /**
     * Places a piece of the player given its position (x, y), its orientation and its flip.
     *
     * @param piece the piece to be placed on the board.
     * @param x the row of the first (upper left) square of the piece.
     * @param y the column of the first (upper left) square of the piece.
     * @param orientation the rotation of the piece as a char ('u', 'd', 'l', 'r').
     * @param flip the flip of the piece as a char ('f', 'r').
     */
    void placePiece(Piece piece, int x, int y, char orientation, char flip);

    /**
     * Returns a string representation of the board. It is a 14 x 14 area of chars, where each char denotes whether
     * the square is unoccupied ('-'), belongs to the first player ('#') or to the second player ('O').
     *
     * @return the board as a string.
     */
    string toString(){
        stringstream sstm;
        sstm << "     ________________________________________________ \n"
             << "    |                                                |\n"
             << "    |      0  1  2  3  4  5  6  7  8  9 10 11 12 13  |\n";
        for(int i = 0; i < boardSize; i++) {
            sstm << "    |  " << i << " "; if (i < 10) sstm << " ";
            for(int j = 0; j < boardSize; j++)
                sstm << " " << (hasPiece(i, j) ? squares[i][j].getPlayer() : '-') << " ";
            sstm << " |\n";
        }
        sstm << "    |________________________________________________|\n";
        return sstm.str();
    };
};

#endif // BOARD_H
