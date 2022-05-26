#include "board.h"
#include "player.h"


bool Board::pieceCanBePlaced(Piece* piece, int x, int y) {
    int xsize = piece->getSizeX(), 
        ysize = piece->getSizeY();
    char player = piece->getPlayer(); 

    //if first move of the current player 
    if (playerHasPlacedNoPieces(player)) {
        //(4,4) or (9,9) respectively
        //coordinates of (init, init) with respect to the piece grid
        int init = (player == '#') ? 4 : 9,
            dx = init - x,
            dy = init - y; 
        //make sure (init, init) is inside the piece grid
        if (dx < 0 || dy < 0 || x + xsize <= init || y + ysize <= init) 
            return false; 
        //make sure (init, init) is actually covered by the piece
        if (!piece->squareHasPiece(dx, dy))
            return false;
        return true; 
    }

    //check piece is inside the board grid
    if (x + xsize >= 14 || y + ysize >= 14) {
        return false; 
    }
    //iterate through all cells of the piece grid
    bool findcorner = false; 
    for(int i = 0; i < xsize; i++) {
        for(int j = 0; j < ysize; j++) {
            if (piece->squareHasPiece(i, j)) {
                //current coordinates on the board
                int curx = x + i,
                    cury = y + j; 
                //check unoccupied square
                if (hasPiece(curx, cury)) 
                    return false;
                //nested if's below to avoid going out of bounds on conditionals
                //check it doesn't touch neighboring squares of the same color
                if (curx + 1 < 14) 
                    if (squareBelongsToPlayer(curx + 1, cury, player))
                        return false; 
                if (curx - 1 >= 0) 
                    if (squareBelongsToPlayer(curx - 1, cury, player))
                        return false; 
                if (cury + 1 < 14) 
                    if (squareBelongsToPlayer(curx, cury + 1, player))
                        return false; 
                if (cury - 1 >= 0) 
                    if (squareBelongsToPlayer(curx, cury - 1, player))
                        return false; 
                //find corner of the same color
                if (curx + 1 < 14 && cury + 1 < 14) 
                    if (squareBelongsToPlayer(curx + 1, cury + 1, player))
                        findcorner = true;  
                if (curx + 1 < 14 && cury - 1 >= 0) 
                    if (squareBelongsToPlayer(curx + 1, cury - 1, player))
                        findcorner = true;  
                if (curx - 1 >= 0 && cury + 1 < 14) 
                    if (squareBelongsToPlayer(curx - 1, cury + 1, player))
                        findcorner = true;  
                if (curx - 1 >= 0 && cury - 1 >= 0) 
                    if (squareBelongsToPlayer(curx - 1, cury - 1, player))
                        findcorner = true;  
            }
        }
    }
    if (!findcorner)
        return false; 

    return true; 
}

int Board::computeScore(Player* player){
    int score = 0; 
    if (player->getNumberOfAvailablePieces() == 0) {
        score += 15; 
        //pointer equality, probably works
        if (getLastPiecePlayedByPlayer(player) == player->getPiece(0))
            score += 5; 
    }
    for(int i = 0; i < 14; i++)
        for(int j = 0; j < 14; j++) 
            if (squareBelongsToPlayer(i, j, player))
                score++; 
    return score; 
}
