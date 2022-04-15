#ifndef SQUARE_H
#define SQUARE_H

#include <sstream>

using namespace std;

/**
 * Class that implements a square of the game.
 */
class Square {
private:
    int x; // the row of the square
    int y; // the column of the square
    char player; // char indicating if the square has part of a piece of the first player (#), the second player (O) or none (-)

public:
    /**
     * Initializes a square setting its coordinates to -1 and its player character to '-'
     * as no piece is placed on the square.
     */
    Square();

    /**
     * Sets the coordinates of this square to the ones given.
     *
     * @param newx the row of the square to be set.
     * @param newy the column of the square to be set.
     */
    void setCoordinates(int newx, int newy);

    /**
     * Returns the row of the square.
     *
     * @return the row of the square.
     */
    int getX();

    /**
     * Returns the column of the square.
     *
     * @return the column of the square.
     */
    int getY();

    /**
     * Adds a part of a piece to this square by setting the corresponding player variable to the character given.
     *
     * @param piecePlayer char denoting which player owns the piece placed on the square ('#' for first or 'O' for second player).
     */
    void addPiece(char piecePlayer);

    /**
     * Removes the piece from this square by setting the corresponding variable of the player to the '-' character.
     */
    void removePiece();

    /**
     * Checks if the square is occupied by a piece.
     *
     * @return true if the square is occupied by a piece, or false otherwise.
     */
    bool hasPiece();

    /**
     * Returns the character of the player who owns the piece placed on this square.
     *
     * @return '#' for the first player, 'O' for the second player, or '-' if the square does not have any piece on it.
     */
    char getPlayer();
};

#endif // SQUARE_H
