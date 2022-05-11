#include "move.h"

// constructor
Move::Move(Piece movePiece, int moveX, int moveY, char moveOrientation, char moveFlip)
{
    piece=movePiece;
    x=moveX;
    y=moveY;
    orientation=moveOrientation;
    flip=moveFlip;
}

// getters
Piece Move::getPiece()
{
    return piece;
}

int Move::getX()
{
    return x;
}

int Move::getY()
{
    return y;
}

char Move::getOrientation()
{
    return orientation;
}

char Move::getFlip()
{
    return flip;
}

