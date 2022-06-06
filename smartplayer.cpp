#include "smartplayer.h"
#include "algorithms.h"
#include <cstdint>
#include <vector>
#include <cmath> 

// square of explore parameter, typically equal to 2
#define EXPLORE 2

Node::Node(Board* board, Player* player, Node* daddy, Move* contract) {
    this->board = board; 
    this->player = player;
    this->parent = daddy; 
    this->contract = contract; 
    visits = 0; 
    winscore = 0; 
    // giveBirthToChildren(); 
    this->availableMoves = player->getPossibleMoves(board, this->aMsize); 
}

Node::~Node() {
    // delete board; 
    // delete player; 

    // children.clear(); 
    // children.shrink_to_fit(); 
}

int Node::getVisits() {
    return visits; 
}

double Node::getWins() {
    return winscore; 
}

Node* Node::getParent() {
    return parent; 
}

void Node::giveBirthToChildren(Player* opponent) {
    for(int i = 0; i < aMsize; i++) {
        Move* move = availableMoves[i]; 
        Board* boardCopy = board->deepCopy(); 
        Piece* pieceCopy = availableMoves[i]->getPiece()->deepCopy(); 
        
        boardCopy->placePiece(pieceCopy, move->getX(), move->getY(), move->getOrientation(), move->getFlip());
        Node* newBorn = new Node(boardCopy, opponent, this, move);
        children.push_back(newBorn); 
    }
}

double Node::uctValue() {
    if (this->getVisits() == 0) 
        return INT16_MAX; 

    return winscore/visits + sqrt(EXPLORE * log(getParent()->getVisits())/visits);
}

int Node::getChildrenSize() {
    return children.size(); 
}

Node* Node::findPromisingChild() {
    Node* promising = children[0]; 
    double best = promising->uctValue();
    for(auto & child : children) {
        if (child->uctValue() > best) {
            promising = child; 
            best = child->uctValue(); 
        }
    }
    return promising; 
}

bool Node::isTerminal() {
    // might need bonus check
    return !aMsize; 
} 

SmartPlayer::SmartPlayer(int id) : Player(id) {
    // team name
    name = "Team 029"; 
}

Tree::Tree(Node* root) {
    this->root = root; 
}
//get Opponent and make our lives easier 
// Player* SmartPlayer::getOpponent() {
//     return opponent; 
// }
// monte carlo tree search let's do it baby 

Move* SmartPlayer::makeMove(Board* board) {
    // TODO: Implement this function to return a move. You must not make the move on the board
    // (or change the board, the piece and the opponent in any other way). You can use the
    // deepCopy functions of the board, the pieces and the opponent if you plan to try some moves
    
    Board* testBoard = board->deepCopy(); 
    Player* testPlayer = this->deepCopy(),
        * testOpponent = this->opponent->deepCopy(); 

    static Node* root = new Node(testBoard, testPlayer); 
    static Tree* tree = new Tree(root); 

    root->giveBirthToChildren(testOpponent); 
    
    while (true) {
        ;
    }// put time constraint


    return NULL;
}
