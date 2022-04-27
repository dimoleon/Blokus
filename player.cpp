#include <iostream>
#include "player.h"

// TODO: Implement here the methods of Player
Player::Player(int playerId)
{
    id=playerId;
    numPlacedPieces=0;
    cout<<"Name of the player: "
    getline(cin, name);
    createPieces();
}

string Player::getName()
{
   return name;
}

Piece Player::Piece getPiece(int index)
{
    return Piece(index, id, allspieces[index-1]);

}

int Player::getNumberOfAvailablePieces()
{
    return 21-numPlacedPieces;
}
