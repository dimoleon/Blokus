#include "smartplayer.h"
#include "algorithms.h"
#include <cstdint>
#include <vector>
#include <cmath> 
#include <algorithm>
#include <chrono> 

// square of explore parameter, typically equal to 2
#define EXPLORE 2
// maximum allowed time for makeMove in milliseconds
#define MAXTIME 4000

Node::Node(Board* board, Player* player, Player* opponent, Node* daddy, Move* contract) {
    player->setOpponent(opponent); 
    opponent->setOpponent(player); 
    this->board = board; 
    this->player = player; 
    this->opponent = opponent; 
    this->parent = daddy; 
    this->contract = contract; 
    generateUntriedMoves(); 
}

Node::~Node() {

}

int Node::getVisits() {
    return visits; 
}

double Node::getWinscore() {
    return winscore; 
}

Node* Node::getParent() {
    return parent; 
}

int Node::getChildrenSize() {
    return children.size(); 
}

int Node::getUntriedSize() {
    return untriedMoves.size(); 
}

bool Node::isLeaf() {
    return children.empty(); 
}

bool Node::isExpandable() {
    return untriedMoves.empty();
}

bool Node::isTerminal() {
    return isLeaf() && isExpandable(); 
}

Node* Node::addChild(int index) {
    Move* move = untriedMoves[index]; 
    Board* boardCopy = board->deepCopy(); 
    Player* playerCopy = player->deepCopy();  
    Player* opponentCopy = opponent->deepCopy();
    Piece* pieceCopy = move->getPiece(); 

    boardCopy->placePiece(pieceCopy, move->getX(), move->getY(), move->getOrientation(), move->getFlip());     
    Node* newBorn = new Node(boardCopy, opponentCopy, playerCopy, this, move); 
    untriedMoves.erase(untriedMoves.begin() + index); 
    return newBorn; 
}

void Node::generateUntriedMoves() {
    int size; 
    Move** aMoves = player->getPossibleMoves(board, size); 
    copy(aMoves, aMoves + size, untriedMoves); 
    for (int i = 0; i < size; i++) 
        delete [] aMoves[i]; 
    delete aMoves; 
}

void Node::clearUntriedMoves() {
    untriedMoves.clear(); 
}

void Node::shuffleUntriedMoves() {
    random_shuffle(untriedMoves.begin(), untriedMoves.end()); 
}

void Node::makeMove(int index) {
    Move* move = untriedMoves[index]; 
    board->placePiece(move->getPiece(), move->getX(), move->getY(), move->getOrientation(), move->getFlip()); 
    //swap players 
    Player* temp = player; 
    player = opponent; 
    opponent = temp; 
}

double Node::uctValue() {
    return winscore/visits + sqrt(EXPLORE * log(getParent()->getVisits())/visits);
}

Node* Node::uctSelect() {
    double best = children[0]->uctValue(); 
    Node* promising = children[0]; 
    for(auto & child : children) {
        if (child->uctValue() > best) {
            best = child->uctValue(); 
            promising = child; 
        }
    }
    return promising;
}

void Node::update(double &result) {
    visits++; 
    winscore += result; 
    result = 1 - result; 
}

double Node::playoutResult() {
    int score1 = board->computeScore(getParent()->getOpponent()); 
    int score2 = board->computeScore(getParent()->getPlayer()); 
    double result; 
    if (score1 > score2) 
        result = 1.0; 
    if (score1 < score2)
        result = 0.0; 
    if (score1 == score2) 
        result = 0.5;
    return result; 
}

Node* Node::visitsSelect() {
    int best = -1;     
    Node* winner; 
    for (auto & child : children) {
        best = max(best, child->getVisits()); 
        winner = child; 
    }
    return winner; 
}

SmartPlayer::SmartPlayer(int id) : Player(id) {
    // team name
    name = "Team 029"; 
}

Move* SmartPlayer::makeMove(Board* board) {
    // TODO: Implement this function to return a move. You must not make the move on the board
    // (or change the board, the piece and the opponent in any other way). You can use the
    // deepCopy functions of the board, the pieces and the opponent if you plan to try some moves
    Board* testBoard = board->deepCopy(); 
    Player* testPlayer = this->deepCopy(),
        *testOpponent = this->opponent->deepCopy(); 

    Node* root = new Node(testBoard, testPlayer, testOpponent); 
    

    // time keeping 
    auto start = chrono::steady_clock::now(); 
    auto end = start; 
    while (chrono::duration_cast<chrono::milliseconds>(end - start).count() < MAXTIME) {
        Node* node = root;

        // selection 
        while (node->isExpandable() && !node->isLeaf()) {
            node = node->uctSelect(); 
        }

        // expansion
        if (node->isExpandable()) {
            node->shuffleUntriedMoves(); 
            // Houston, we have a problem
            // make it more efficient
            node = node->addChild(0);
        }

        // playout
        while (!node->isTerminal()) {
            node->clearUntriedMoves(); 
            node->generateUntriedMoves(); 
            node->makeMove(0); 
        }

        // backpropagate
        double result = node->playoutResult(); 
        while (node != nullptr) {
            node->update(result); 
            node = node->getParent(); 
        }

        end = chrono::steady_clock::now(); 
    }

    Node* winner = root->visitsSelect(); 
    Move* final = new Move(winner->getContract()); 
    delete testBoard;
    delete testPlayer; 
    delete testOpponent;  
    delete root; 

    return final; 
}

