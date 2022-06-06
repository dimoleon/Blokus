#ifndef SMARTPLAYER_H
#define SMARTPLAYER_H

#include "player.h"
#include <vector> 

class Node { 
private: 
    Node* parent; 
    Move* contract; 
    Board* board; 
    Player* player; 
    vector<Node*> children; 
    int visits; 
    double winscore; 

    Move** availableMoves; 
    int aMsize; 

public: 
    Node(Board* board, Player* player, Node* daddy = NULL, Move* contract = NULL); 
    ~Node(); 

    int getVisits(); 
    double getWins(); 
    Node* getParent(); 
    int getChildrenSize(); 

    void giveBirthToChildren(Player* opponent); 
    Move** getAllMoves();

    Node* findPromisingChild(); 
    Node* pickRandomChild();
    
    double uctValue();
    bool isTerminal(); 
};

class Tree {
    Node* root; 

public: 
    Tree(Node* root); 
    ~Tree(); 

    Node* getRoot(); 
    void setRoot(Node* newRoot); 

    bool isLeaf(Node* node); 

    void deleteUnused();
};

/**
 * Class that implements a smart player that plays according to the state of the game.
 */
class SmartPlayer : public Player {
public:
    /**
     * Initializes a smart player calling the constructor of the player.
     *
     * @param id the id of the player.
     */
    SmartPlayer(int id);

    /**
     * Receives the current state of the board and returns a move.
     *
     * @return an object of type Move containing a piece, its position, its orientation, and its flip.
     */
    Move* makeMove(Board* board);
};


#endif // SMARTPLAYER_H
