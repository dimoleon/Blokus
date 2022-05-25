#include <iostream>
#include <cstdlib>
#include "player.h"

// TODO: Implement here the methods of Player and all derived classes
Player::Player(int id){
    this->id = id;

    switch(id)
    {
    case 0:
        name = "Player 1";
        symbol = '#';
        break;
    case 1:
        name = "Player 2";
        symbol = 'O';
        break;
    }

    numPieces = 21;
    pieces = new Piece*[21]; 
    createPieces();
}

Player::~Player(){
    for (int i = 0; i < 21; i++)
        delete pieces[i];

    delete [] pieces;
}

int Player::getId(){
    return id;
}

char Player::getSymbol(){
    return symbol;
}

string Player::getName(){
    return name;
}

int Player::getNumberOfPlacedPieces() {
    return 21-numPieces;
}

int Player::getNumberOfAvailablePieces() {
    return numPieces;
}

Piece* Player::getPiece(int index) {
    return pieces[index - 1]; 
}

HumanPlayer::HumanPlayer(int id):Player(id) {
}

HumanPlayer::HumanPlayer(int id, string name):Player(id) {
    this->name = name; 
}

int ComputerPlayer::getRandomPieceId(){
	int p;
	p=1+rand()%21;
	return p;
}

Orientation ComputerPlayer::getRandomOrientation(){
    int y;
    y=rand()%4;
    return Orientation(y);
}

Flip ComputerPlayer::getRandomFlip(){
    int x;
    x=rand()%2;
    return Flip(x);
}

ComputerPlayer::ComputerPlayer(int id):Player(id){

}
