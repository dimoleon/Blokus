#include <iostream>
#include "square.h"

// TODO: Implement here the methods of Square

Square::Square( ){
   x = -1;
   y = -1;
   player = '-';

}

void Square::setCoordinates(int newX,int newY){
   x= newX;
   y= newY;
}

int Square::getX(){
    return x;
}

int Square::getY(){
    return y;
}

char Square::getPlayer(){
     return player;
}

bool Square::hasPiece(){
    if(player=='#' || player=='O'){
        return true;
    }
    return false;
}

void Square::addPiece(char piecePlayer){
   player = piecePlayer;
}

void Square::removePiece(){
   player = '-';
}
