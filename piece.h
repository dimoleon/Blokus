#ifndef PIECE_H
#define PIECE_H

#include "square.h"

/**
 * Class that implements a piece of the game.
 */
class Piece {
private:
    int id;
    bool placed; // boolean denoting if this piece has been placed on the board (true) or not (false)
    char player; // char denoting the player that owns this pieces, '#' for the first player, 'O' for the second player, '-' for none
    int pieceSize; // the size dimension of the piece, which must always be equal to 5 (pieces are stored in a 5 x 5 area)
    Square squares[5][5]; // the squares of the piece

public:
    /**
     * Initializes a piece setting its id to -1, its size to 5 and its player to '-'.
     * The piece is initially is not placed.
     */
    Piece();

    /**
     * Initializes a piece given its id, setting its size to 5 and initializing its squares.
     * For each square one must set the coordinates (x, y) and the char of the player.
     * We must also set that the piece is initially is not placed.
     *
     * Hint: we have to use a loop over all squares, and for each individual square we have to set its x and its y, and call
     * its addPiece method if the square is occupied by the piece (i.e. if the corresponding boolean of pieceSquares is true).
     *
     * @param pieceId the id of the piece.
     * @param piecePlayer char of the player who owns the piece.
     * @param pieceSquares array of chars indicating whether each square is occupied by a piece (with char piecePlayer) or not.
     */
    Piece(int pieceId, char piecePlayer, char pieceSquares[5][5]);

    /**
     * Returns the id of the piece.
     *
     * @return the id of the piece.
     */
    int getId();

    /**
     * Returns the player that owns the piece.
     *
     * @return char of the player who owns the piece.
     */
    char getPlayer();

    /**
     * Sets the placed variable of the piece to true.
     */
    void setPlaced();

    /**
     * Checks whether the piece has been placed on the board.
     *
     * @return true if the piece has been placed on the board, or false otherwise.
     */
    bool isPlaced();

    /**
     * Returns the size dimension of the piece.
     *
     * @return the size dimension of the piece.
     */
    int getSize();

    /**
     * Returns a specific square of the piece given its coordinates.
     *
     * @param x the row of the square to be returned.
     * @param y the column of the square to be returned.
     * @return the square of the piece at row x and column y.
     */
    Square getSquare(int x, int y);

    /**
     * Checks whether a specific square has part of the piece given its coordinates.
     *
     * @param x the row of the square to be checked.
     * @param y the column of the square to be checked.
     * @return true if the square has part of the piece on it, or false otherwise.
     */
    bool squareHasPiece(int x, int y);

    /**
     * Rotates the piece clockwise. An example clockwise rotation is the following:
     *
     *       Initial state              Rotated
     *         - # - - -               - - # - -
     *         - # - - -               - - # # #
     *         # # - - -      ---->    - - - - -
     *         - - - - -               - - - - -
     *         - - - - -               - - - - -
     *
     * Warning: Each square has three variables, two for its coordinates (integers x and y) and one for its ownership (char player).
     *          The resulting piece squares must keep the correct coordinates, only the ownership of each square should change!
     * Hint: The rotation can be done in various ways. What is important is that the final result is placed in array squares of this class.
     */
    void rotatePieceClockwise();

    /**
     * Rotates the piece according to the orientation received as input. Orientation 'u' means that the piece should not be
     * rotated at all, 'r' means that the piece must be rotated clockwise one time, 'd' means that it must be rotated clockwise
     * two times, and 'l' means that it must be rotated clockwise three times.
     *
     * Hint: We can call the rotatePieceClockwise method here.
     *
     * @param x the row of the square to be returned.
     */
    void rotatePiece(char orientation);

    /**
     * Flips the piece horizontally. An example horizontal flip is the following:
     *
     *       Initial state              Flipped
     *         - # - - -               - - - # -
     *         - # - - -               - - - # -
     *         # # - - -      ---->    - - - # #
     *         - - - - -               - - - - -
     *         - - - - -               - - - - -
     *
     * Warning: Each square has three variables, two for its coordinates (integers x and y) and one for its ownership (char player).
     *          The resulting piece squares must keep the correct coordinates, only the ownership of each square should change!
     * Hint: The flip can be done in various ways. What is important is that the final result is placed in array squares of this class.
     */
    void flipPiece();

    /**
     * Returns a string representation of this piece. It is a 5 x 5 area of chars, where each char denotes whether
     * the square is unoccupied ('-'), belongs to the first player ('#') or to the second player ('O').
     *
     * @return the piece as a string.
     */
    string toString() {
        stringstream sstm;
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 4; j++)
                sstm << squares[i][j].getPlayer() << " ";
            sstm << squares[i][4].getPlayer() << "\n";
        }
        string result = sstm.str();
        return result;
    };
};

#endif // PIECE_H
