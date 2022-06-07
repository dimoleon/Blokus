#ifndef SMARTPLAYER_H
#define SMARTPLAYER_H

#include "player.h"
#include <vector> 


struct Node {
    Node* parent; 
    Move* contract; 
    int visits; 
    double winscore; 
    Board* board; 
    Player* player; 
    Player* opponent;

    vector<Node*> children; 
    vector<Move*> untriedMoves; 

public: 
    Node(Board *board, Player* player, Player* opponent, Node* daddy = nullptr, Move* contract = nullptr); 
    ~Node(); 

    void generateUntriedMoves();  
    void clearUntriedMoves(); 
    void shuffleUntriedMoves(); 

    int getVisits();
    double getWinscore(); 
    Node* getParent(); 
    Player* getPlayer(); 
    Player* getOpponent();
    Board* getBoard(); 
    Move* getContract(); 

    int getChildrenSize();
    int getUntriedSize(); 

    bool isLeaf();
    bool isFullyExpanded();
    bool isTerminal();

    double uctValue(); 
    Node* uctSelect(); 
    Node* visitsSelect(); 

    Node* addChild();
    // Node* addChild(Move* move, Player* opponent);

    void simulateMove(); 
    double playoutResult(); 
    void update(double &result); 

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
