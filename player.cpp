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
createPieces();
}

Player::~Player(){
for (int i = 0; i < 21; i++)
    delete [] pieces[i];

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
