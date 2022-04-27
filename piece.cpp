#include "piece.h"

// TODO: Implement here the methods of Piece

Piece::Piece() {
    id = -1; 
    placed = false; 
    player = '-'; 
    pieceSize = 5; 
}

Piece::Piece(int pieceId, char piecePlayer, char pieceSquares[5][5]) {
    id = pieceId; 
    player = piecePlayer; 
    placed = false; 
    pieceSize = 5; 

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            squares[i][j].setCoordinates(i, j);
            if(pieceSquares[i][j] == 'o') {
                squares[i][j].addPiece(piecePlayer); 
            }
        }
    }
}

int Piece::getId() {
    return id; 
}

char Piece::getPlayer() {
    return player; 
}

void Piece::setPlaced() {
    placed = true; 
}

bool Piece::isPlaced() {
    return placed; 
}

int Piece::getSize() {
    return pieceSize; 
}

//getSquare
//squareHasPiece

void Piece::rotatePieceClockwise() {
    for(int i = 0; i < 2; i++) {
        for(int j = i; j < 4 - i; j++) {
            bool help = squareHasPiece(i, j);
            squares[i][j].removePiece();
            if(squareHasPiece(4 - j, i)) {
                squares[i][j].addPiece(player); 
            }
            squares[4 - j][i].removePiece(); 
            if(squareHasPiece(4 - i, 4 - j)) {
                squares[4 - j][i].addPiece(player); 
            }
            squares[4 - i][4 - j].removePiece(); 
            if(squareHasPiece(j, 4 - i)) {
                squares[4 - i][4 - j].addPiece(player); 
            }
            squares[j][4 - i].removePiece();
            if(help) {
                squares[j][4 - i].addPiece(player); 
            }
        }
    }
}

//rotatePiece
//flipePiece
