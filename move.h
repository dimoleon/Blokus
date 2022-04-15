#ifndef MOVE_H
#define MOVE_H

#include "piece.h"

/**
 * Class that implements a move of the game.
 */
class Move
{
private:
    Piece piece; // the piece that is placed as part of the move
    int x; // the row where the upper left square of the piece is placed
    int y; // the column where the upper left square of the piece is placed
    char orientation; // piece rotation as char ('u' for no rotation/0 degrees, 'r' for 90 degrees, 'd' for 180 degrees, 'l' for 270 degrees)
    char flip; // piece flip as char ('f' for no flip, 'r' horizontal flip)

public:
    /**
     * Initializes a move setting its piece to be placed, the coordinates for the upper left square of the piece, the orientation,
     * and the flip of the piece to the values given as parameters.
     *
     * @param movePiece the piece that is placed.
     * @param moveX the row of the upper left square of the move.
     * @param moveY the column of the upper left square of the move.
     * @param moveOrientation the orientation of the piece that is placed.
     * @param moveFlip the flip of the piece that is placed.
     */
    Move(Piece movePiece, int moveX, int moveY, char moveOrientation, char moveFlip);

    /**
     * Returns the piece that is placed by this move.
     *
     * @return the piece that is placed by this move.
     */
    Piece getPiece();

    /**
     * Returns the row of the upper left square of the move.
     *
     * @return the row of the upper left square of the move.
     */
    int getX();

    /**
     * Returns the column of the upper left square of the move.
     *
     * @return the column of the upper left square of the move.
     */
    int getY();

    /**
     * Returns the orientation of the piece of the move.
     *
     * @return the orientation of the piece of the move.
     */
    char getOrientation();

    /**
     * Returns the flip of the piece of the move.
     *
     * @return the flip of the piece of the move.
     */
    char getFlip();
};

#endif // MOVE_H
