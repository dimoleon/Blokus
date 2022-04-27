#include <iostream>
#include "player.h"



// TODO: Implement here the methods of Player
Player::Player(int playerId)
{
    id=playerId;
    numPlacedPieces=0;
    if(playerId==0)
        name="Player 1";
    else if(playerId==1)
        name="Player 2";
    createPieces();
}

string Player::getName()
{
   return name;
}

Piece Player::getPiece(int index)
{
    return pieces[index-1];

}

int Player::getNumberOfAvailablePieces()
{
    return 21-numPlacedPieces;
}
