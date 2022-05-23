# Blokus
Εργασία Αντικειμενοστραφούς Προγραμματισμού ΤΗΜΜΥ 2022 2ο Εξάμηνο 

---

## 1ο Παραδοτέο (έως και Τετάρτη 06/04)
- [x] Διάγραμμα uml (blokus.mdj)

--- 

## 2ο Παραδοτέο (έως και Κυριακή 15/05)
Γράφουμε μόνο στα αρχεία: 
1. move.cpp 
    - [x] `Move()`
    - [x] `getPiece()`
    - [x] `getX()`
    - [x] `getY()`
    - [x] `getOrientation()`
    - [x] `getFlip()`
2. piece.cpp 
    - [x] `Piece()` x 2
    - [x] `getId()`
    - [x] `getPlayer()`
    - [x] `setPlaced()`
    - [x] `isPlaced()`
    - [x] `getSize()`
    - [x] `getSquare()`
    - [x] `squareHasPiece()`
    - [x] `rotatePieceClockwise()`
    - [x] `rotatePiece()`
    - [x] `flipPiece()`
3. player.cpp 
    - [x] `Player()`
    - [x] `getName()`
    - [x] `getPiece()`
    - [x] `getNumberOfAvailablePieces()`
4. square.cpp
    - [x] `Square()`
    - [x] `setCoordinates()`
    - [x] `getX()`
    - [x] `getY()`
    - [x] `addPiece()`
    - [x] `removePiece()`
    - [x] `hasPiece()`
    - [x] `getPlayer()`

---

## 3ο Παραδοτέο (έως και Παρασκευή 27/05)
Γράφουμε μόνο στα αρχεία: 
1. player.cpp 
    * Κλάση Player
        - [x] `Player(int id)`
        - [x] `~Player()`
        - [x] `int getId()`
        - [x] `char getSymbol()`
        - [x] `string getName()`
        - [ ] `Piece* getPiece(int index)`
        - [ ] `int getNumberOfPlacedPieces()`
        - [ ] `int getNumberOfAvailablePieces()`
    * Υποκλάση HumanPlayer
        - [ ] `HumanPlayer(int id)`
        - [ ] `HumanPlayer(int id, string name)`
    * Υποκλάση ComputerPlayer
        - [X] `int getRandomPieceId()`
        - [X] `Orientation getRandomOrientation()`
        - [X] `Flip getRandomFlip()`
        - [X] `ComputerPlayer(int id)`
2. boardrules.cpp 
    - [x] `bool pieceCanBePlaced(Piece* piece, int x, int y)`
    - [x] `int computeScore(Player* player)`


