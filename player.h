#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "move.h"
#include "piece.h"
#include "board.h"

/**
 * Class that implements a player of the game.
 */
class Player {
protected:
    int id;
    string name;
    Piece pieces[21]; // the pieces of the player
    int numPlacedPieces; // the number of pieces placed by the player (initialized to 0 and incremented when pieces are placed)

public:
    /**
     * Initializes a player setting the index and the name. The numPlacedPieces variable is also initialized to zero.
     * Finally, the createPieces method must be called to create all the pieces of the player.
     *
     * @param playerId the name of the player.
     */
    Player(int playerId);

    /**
     * Returns the name of the player.
     *
     * @return the name of the player.
     */
    string getName();

    /**
     * Returns a piece of the player given its index.
     *
     * @param index the index of the piece to be returned.
     * @return a piece of the player given its index.
     */
    Piece getPiece(int index);

    /**
     * Returns the number of the available pieces of the player, i.e. the number
     * of pieces that have not been placed yet.
     *
     * @return the number of the available pieces of the player.
     */
    int getNumberOfAvailablePieces();

    /// THE METHODS BELOW THIS POINT ARE IMPLEMENTED IN FILE playerpieces.cpp
    /**
     * Creates the pieces of the player by calling the different constructors.
     */
    void createPieces();

    /**
     * Prints the given pieces from pstart to pend side by side.
     *
     * @param pieces the pieces to be printed.
     * @param pstart the start index of the array of pieces to be printed.
     * @param pend the end index of the array of pieces to be printed.
     */
    void printPiecesSideBySide(Piece pieces[], int pstart, int pend);

    /**
     * Prints the available pieces of the player, This method calls the printPiecesSideBySide method to
     * print the pieces side by side.
     */
    void printAvailablePieces();

    /**
     * Receives the current state of the board and returns a move. A move contains the piece
     * to be placed on the board, its position (x, y), its orientation, and its flip.
     * The information of the move is read by the console. Before returning, this method also
     * sets the piece to be returned as placed, and decreases the numPlacedPieces variable by 1.
     *
     * @return an object of type Move containing a piece, its position, its orientation, and its flip..
     */
    Move placePiece(Board board);
};

#endif // PLAYER_H
