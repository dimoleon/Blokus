#include <iomanip>
#include <iostream>

#include "player.h"

void Player::createPieces() {
    char o = (id == 0 ? '#' : 'O'), i = '-';

    char allspieces[21][5][5] = {{
                                {o, i, i, i, i}, // Piece 1
                                {i, i, i, i, i},
                                {i, i, i, i, i},
                                {i, i, i, i, i},
                                {i, i, i, i, i}
                                }, {
                                {o, i, i, i, i}, // Piece 2
                                {o, i, i, i, i},
                                {i, i, i, i, i},
                                {i, i, i, i, i},
                                {i, i, i, i, i}
                                }, {
                                {o, i, i, i, i}, // Piece 3
                                {o, i, i, i, i},
                                {o, i, i, i, i},
                                {i, i, i, i, i},
                                {i, i, i, i, i}
                                }, {
                                {o, i, i, i, i}, // Piece 4
                                {o, o, i, i, i},
                                {i, i, i, i, i},
                                {i, i, i, i, i},
                                {i, i, i, i, i}
                                }, {
                                {o, i, i, i, i}, // Piece 5
                                {o, i, i, i, i},
                                {o, i, i, i, i},
                                {o, i, i, i, i},
                                {i, i, i, i, i}
                                }, {
                                {i, o, i, i, i}, // Piece 6
                                {i, o, i, i, i},
                                {o, o, i, i, i},
                                {i, i, i, i, i},
                                {i, i, i, i, i}
                                }, {
                                {o, i, i, i, i}, // Piece 7
                                {o, o, i, i, i},
                                {o, i, i, i, i},
                                {i, i, i, i, i},
                                {i, i, i, i, i}
                                }, {
                                {o, o, i, i, i}, // Piece 8
                                {o, o, i, i, i},
                                {i, i, i, i, i},
                                {i, i, i, i, i},
                                {i, i, i, i, i}
                                }, {
                                {o, o, i, i, i}, // Piece 9
                                {i, o, o, i, i},
                                {i, i, i, i, i},
                                {i, i, i, i, i},
                                {i, i, i, i, i}
                                }, {
                                {o, i, i, i, i}, // Piece 10
                                {o, i, i, i, i},
                                {o, i, i, i, i},
                                {o, i, i, i, i},
                                {o, i, i, i, i}
                                }, {
                                {i, o, i, i, i}, // Piece 11
                                {i, o, i, i, i},
                                {i, o, i, i, i},
                                {o, o, i, i, i},
                                {i, i, i, i, i}
                                }, {
                                {i, o, i, i, i}, // Piece 12
                                {i, o, i, i, i},
                                {o, o, i, i, i},
                                {o, i, i, i, i},
                                {i, i, i, i, i}
                                }, {
                                {i, o, i, i, i}, // Piece 13
                                {o, o, i, i, i},
                                {o, o, i, i, i},
                                {i, i, i, i, i},
                                {i, i, i, i, i}
                                }, {
                                {o, o, i, i, i}, // Piece 14
                                {i, o, i, i, i},
                                {o, o, i, i, i},
                                {i, i, i, i, i},
                                {i, i, i, i, i}
                                }, {
                                {o, i, i, i, i}, // Piece 15
                                {o, o, i, i, i},
                                {o, i, i, i, i},
                                {o, i, i, i, i},
                                {i, i, i, i, i}
                                }, {
                                {i, o, i, i, i}, // Piece 16
                                {i, o, i, i, i},
                                {o, o, o, i, i},
                                {i, i, i, i, i},
                                {i, i, i, i, i}
                                }, {
                                {o, i, i, i, i}, // Piece 17
                                {o, i, i, i, i},
                                {o, o, o, i, i},
                                {i, i, i, i, i},
                                {i, i, i, i, i}
                                }, {
                                {o, o, i, i, i}, // Piece 18
                                {i, o, o, i, i},
                                {i, i, o, i, i},
                                {i, i, i, i, i},
                                {i, i, i, i, i}
                                }, {
                                {o, i, i, i, i}, // Piece 19
                                {o, o, o, i, i},
                                {i, i, o, i, i},
                                {i, i, i, i, i},
                                {i, i, i, i, i}
                                }, {
                                {o, i, i, i, i}, // Piece 20
                                {o, o, o, i, i},
                                {i, o, i, i, i},
                                {i, i, i, i, i},
                                {i, i, i, i, i}
                                }, {
                                {i, o, i, i, i}, // Piece 21
                                {o, o, o, i, i},
                                {i, o, i, i, i},
                                {i, i, i, i, i},
                                {i, i, i, i, i}
                            }};
    for (int i = 0; i < 21; i++)
        pieces[i] = Piece(i + 1, id == 0 ? '#' : 'O', allspieces[i]);
};

void Player::printPiecesSideBySide(Piece pieces[], int pstart, int pend){
    int numPieces = pend - pstart;
    stringstream ss[numPieces];
    cout << "   ";
    for (int i = pstart; i < pend; i++){
        cout << (pieces[i].getId() > 9 ? "" : " ") << pieces[i].getId() << "          ";
        ss[i - pstart] << pieces[i].toString();
    }
    cout << endl;
    string to[numPieces];
    for (int j = 0; j < 5; j++){
        for (int i = pstart; i < pend; i++){
            getline(ss[i - pstart], to[i - pstart], '\n');
            cout << to[i - pstart] << "   ";
        }
        cout << endl;
    }
}

void Player::printAvailablePieces(){
    cout << "\n\nPlayer " << (id + 1) << " available pieces:" << endl;
    int numAvailablePieces = 21 - numPlacedPieces;
    Piece availablePieces[numAvailablePieces];
    int j = 0;
    for (int i = 0; i < 21; i++){
        if (!pieces[i].isPlaced())
            availablePieces[j++] = pieces[i];
    }

    if (numAvailablePieces >= 7){
        printPiecesSideBySide(availablePieces, 0, 7);
        if (numAvailablePieces >= 14){
            printPiecesSideBySide(availablePieces, 7, 14);
            printPiecesSideBySide(availablePieces, 14, numAvailablePieces);
        }
    }
    else{
        printPiecesSideBySide(availablePieces, 0, numAvailablePieces);
    }
}

Move Player::placePiece(Board board){
    int pieceIndex, x, y;
    char orientation, flip;
    cout << "Select piece (1-21), orientation (u, d, l, r), flip (f, r), position (x, y), (e.g. 3 u f 3 4): " << endl;
    if (numPlacedPieces == 0)
        cout << "First piece must touch square " << (id == 0 ? "4, 4" : "9, 9") << endl;;
    cin >> pieceIndex >> orientation >> flip >> x >> y;
    pieces[pieceIndex-1].setPlaced();
    numPlacedPieces++;
    return Move(pieces[pieceIndex-1], x, y, orientation, flip);
}
