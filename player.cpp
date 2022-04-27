#include <iostream>
#include "player.h"



// TODO: Implement here the methods of Player
Player::Player(int playerId)
{
    id=playerId;
    numPlacedPieces=0;
    createPieces();
}

string Player::getName()
{
   return name;
}

{
    return Piece(index, id, allspieces[index-1]);

}

int Player::getNumberOfAvailablePieces()
{
    return 21-numPlacedPieces;
}
