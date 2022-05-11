#include "piece.h"

// first constructor
Piece::Piece() {
    id = -1;
    placed = false;
    player = '-';
    pieceSize = 5;
}

// second constructor 
Piece::Piece(int pieceId, char piecePlayer, char pieceSquares[5][5]) {
    id = pieceId;
    player = piecePlayer;
    placed = false;
    pieceSize = 5;

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            squares[i][j].setCoordinates(i, j);
            // Square constructor defaults to '-'
            if(pieceSquares[i][j] != '-') {
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

Square Piece::getSquare(int x, int y){
    return squares[x][y];
}

bool Piece::squareHasPiece(int x, int y){
    return squares[x][y].hasPiece(); 
}

//rotates the piece grid by splitting the grid into 
//independent cycles of length 4.
//(Each one of them visually forms a square)
//and rotating them one by one going from the outter to the inner ones. 
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

void Piece::rotatePiece(char orientation){
    switch(orientation)
    {
        case 'u':
            break;
        case 'r':
            rotatePieceClockwise();
            break;
        case 'd':
            rotatePieceClockwise();
            rotatePieceClockwise();
            break;
        case 'l':
            rotatePieceClockwise();
            rotatePieceClockwise();
            rotatePieceClockwise();
            break;
    }
}

//performs the flip by 
//swapping the ownership of symmetric vertices 
//with respect to the middle column of the grid consequtively
//going from the outter to the inner ones
void Piece::flipPiece(){
    for(int i=0; i<=4; i++)
    {
        for(int j=0; j<2; j++)
        {
            bool help = squareHasPiece(i, 4 - j);
            squares[i][4 - j].removePiece(); 
            if(squareHasPiece(i,j)){
                squares[i][4 - j].addPiece(player);
            }
            squares[i][j].removePiece();
            if(help) {
                squares[i][j].addPiece(player);
            }
        }
    }
}

