#include <iostream>
#include "player.h"

using namespace std;

int main() {
    // Initialize the game objects
    Board board;
    Player players[2] = {Player(0), Player(1)};

    int playerTurn = 0;
    do {
        cout << endl << "Board:" << endl << board.toString();
        players[playerTurn].printAvailablePieces();

        // Determine and play the next move
        Move pieceMove = players[playerTurn].placePiece(board);
        board.placePiece(pieceMove.getPiece(), pieceMove.getX(), pieceMove.getY(), pieceMove.getOrientation(), pieceMove.getFlip());

        playerTurn = 1 - playerTurn;
    } while(players[0].getNumberOfAvailablePieces() > 0 && players[1].getNumberOfAvailablePieces() > 0);

    return 0;
}

