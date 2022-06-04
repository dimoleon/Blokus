#include "smartplayer.h"
#include "algorithms.h"
#include "game.h"
#include <vector>

SmartPlayer::SmartPlayer(int id) : Player(id) {
    // team name
    name = "Team 029"; 
}

class Node {
    Node* parent; 
    vector<Node*> children;
    Game* game; 
    int visits; 
    double winScore; 

public: 
    Node(); 
    ~Node(); 


    Game** getPossibleStates(); 
    Node* selectPromisingNode(Node* root); 

    double uctValue(); 

};


// monte carlo tree search let's do it baby 

Move* SmartPlayer::makeMove(Board* board) {
    // TODO: Implement this function to return a move. You must not make the move on the board
    // (or change the board, the piece and the opponent in any other way). You can use the
    // deepCopy functions of the board, the pieces and the opponent if you plan to try some moves
    
    // create testing pointers 
    // Board* testBoard = board->deepCopy();
    // Player* testPlayer = this->deepCopy(),
    //     * testOpponent = this->opponent->deepCopy(); 
    //
    // // get array of available moves 
    // int numPossibleMoves; 
    // Move** possibleMoves = testPlayer->getPossibleMoves(testBoard, numPossibleMoves);
    
    // free memory 
    // delete testBoard; 
    // delete testPlayer; 
    // delete testOpponent; 


    return NULL;
}