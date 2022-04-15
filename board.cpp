#include <iostream>
#include <cstdlib>
#include "board.h"

using namespace std;

Board::Board() {
    boardSize = 14;
    for (int i = 0; i < boardSize; i++){
        for (int j = 0; j < boardSize; j++){
            squares[i][j].setCoordinates(i, j);
        }
    }
}

bool Board::hasPiece(int x, int y){
    return squares[x][y].hasPiece();
}

bool Board::hasPlayerPiece(int x, int y, char player){
    return squares[x][y].getPlayer() == player;
}

void Board::placePiece(Piece piece, int x, int y, char orientation, char flip){
    piece.rotatePiece(orientation);
    if (flip == 'r')
        piece.flipPiece();
    for(int i = 0; i < piece.getSize(); i++){
        for(int j = 0; j < piece.getSize(); j++){
            if (piece.squareHasPiece(i, j))
                squares[x + i][y + j].addPiece(piece.getPlayer());
        }
    }
}
