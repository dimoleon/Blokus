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

