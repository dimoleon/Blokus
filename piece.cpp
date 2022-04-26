#include "piece.h"

// TODO: Implement here the methods of Piece

Piece::Piece() {
    id = -1; 
    placed = false; 
    player = '-'; 
    pieceSize = 5; 
}

// Piece::Piece(int pieceId, char piecePlayer, char pieceSquares[5][5]) {
//
// }

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

