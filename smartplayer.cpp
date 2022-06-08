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
    visits = 0; 
    winscore = 0.0; 
    generateUntriedMoves(); 
}

Node::~Node() {
    children.clear(); 
    untriedMoves.clear(); 
    // children.shrink_to_fit();
    // untriedMoves.shrink_to_fit();
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

Move* Node::getContract() {
    return contract; 
}

Player* Node::getPlayer() {
    return player; 
}

Player* Node::getOpponent() {
    return opponent;
}

bool Node::isLeaf() {
    return children.empty(); 
}

bool Node::isFullyExpanded() {
    return untriedMoves.empty();
}

bool Node::isTerminal() {
    return isLeaf() && isFullyExpanded(); 
}

Node* Node::addChild() {
    Move* move = untriedMoves[untriedMoves.size() - 1]; 
    Board* boardCopy = board->deepCopy(); 
    Player* playerCopy = player->deepCopy();  
    Player* opponentCopy = opponent->deepCopy();
    Piece* pieceCopy = move->getPiece()->deepCopy(); 
    // Piece* pieceCopy = move->getPiece();

    boardCopy->placePiece(pieceCopy, move->getX(), move->getY(), move->getOrientation(), move->getFlip());     
    Node* newBorn = new Node(boardCopy, opponentCopy, playerCopy, this, move); 
    // untriedMoves.erase(untriedMoves.begin() + index); 
    untriedMoves.pop_back(); 
    children.push_back(newBorn); 
    return newBorn; 
}

void Node::generateUntriedMoves() {
    int size; 
    Move** aMoves = player->getPossibleMoves(board, size); 
    // add implemented shuffle here, std::random_shuffle hates me
    shuffle(aMoves, size);
    // copy(aMoves, aMoves + size, untriedMoves);
    for(int i = 0; i < size; i++) 
        untriedMoves.push_back(aMoves[i]); 
    // for(int i = 0; i < size; i++) {
    //     delete aMoves[i];
    // }
    delete [] aMoves;
}

void Node::clearUntriedMoves() {
    untriedMoves.clear(); 
}

void Node::shuffleUntriedMoves() {
    // random_shuffle(untriedMoves.begin(), untriedMoves.end()); 
}

void Node::simulateMove() {
    Move* move = untriedMoves[untriedMoves.size() - 1]; 
    board->placePiece(move->getPiece(), move->getX(), move->getY(), move->getOrientation(), move->getFlip()); 
    //swap players 
    swap(player, opponent); 
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
    for(auto & child : children) {
        if (child->getVisits() > best) {
            winner = child; 
            best = child->getVisits(); 
        }
    }
    return winner; 
}

SmartPlayer::SmartPlayer(int id) : Player(id) {
    // team name
    name = "Team 029"; 
}

Move* SmartPlayer::makeMove(Board* board) {

    Node* root = new Node(board, this, this->opponent); 
    // return root->untriedMoves[root->getUntriedSize() - 1];
    
    // time keeping 
    auto start = chrono::steady_clock::now(); 
    auto end = start; 
    while (chrono::duration_cast<chrono::milliseconds>(end - start).count() < MAXTIME) {
        Node* node = root;

        // selection 
        while (node->isFullyExpanded() && !node->isLeaf()) {
            node = node->uctSelect(); 
        }

        // expansion
        if (!node->isFullyExpanded()) {
            node->shuffleUntriedMoves(); 
            // Houston, we have a problem
            // make it more efficient
            node = node->addChild();
        }

        // end = chrono::steady_clock::now(); 
        // cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << endl; 
        // playout
        // for(int i = 0; i < 8; i++) {
        int depth = 0; 
        while (true) {
            node->clearUntriedMoves(); 
            // cout << node->getUntriedSize() << endl; 
            node->generateUntriedMoves(); 
            // cout << node->getUntriedSize() << endl << endl;  
            if (node->isTerminal()) 
                break; 
            node->shuffleUntriedMoves(); 
            node->simulateMove(); 
            depth++; 
        }
        cout << "Depth: " << depth << endl; 

        // backpropagate
        double result = node->playoutResult(); 
        while (node != nullptr) {
            node->update(result); 
            // cout << node->getWinscore() << '/' << node->getVisits() << endl;
            node = node->getParent(); 
        }

        end = chrono::steady_clock::now(); 
        // cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << endl; 
    }

    cout << endl << "Children: " << root->getChildrenSize() << " Untried: " << root->getUntriedSize() << endl; 
    Move* winner = root->visitsSelect()->getContract(); 
    int winId = winner->getPiece()->getId() - 1; 
    Move* final = new Move(this->getPiece(winId), winner->getX(), winner->getY(), winner->getOrientation(), winner->getFlip()); 
    delete root;
    // cout << final->getPiece()->getId() << ' ' << final->getX() << ' ' 
        // << final->getY() << ' ' << final->getOrientation() << ' ' << final->getFlip() << endl; 

    return final; 
}

