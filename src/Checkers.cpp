#include "Checkers.h"
#include <iostream>

using namespace std;

namespace minimax {
    int Checkers::main() {
        Checkers board = Checkers();
        board.drawBoard();
        Move move = Move(2, 2, fl);
        board.validMove(move);
    }
    
    Checkers::Checkers() {
        this->board = std::vector<std::vector<char> >(8);
        std::cout << "Initializing Checkerboard" << std::endl;
        for (int x = 0; x < this->board.size(); x++) {
            this->board[x] = std::vector<char>(8);
            for (int y = 0; y < this->board.size(); y++) {
                if (x % 2 == 0) {
                    if (y % 2 == 1) {
                        this->board[x][y] = 'X';
                    } else if (y <= 2) {
                        this->board[x][y] = 'O';
                    } else if (y >= 5) {
                        this->board[x][y] = '0';
                    } else {
                        this->board[x][y] = ' ';
                    }
                } else {
                    if (y % 2 == 0) {
                        this->board[x][y] = 'X';
                    } else if (y >= 5) {
                        this->board[x][y] = '0';
                    } else if (y <= 2) {
                        this->board[x][y] = 'O';
                    } else {
                        this->board[x][y] = ' ';
                    }
                }
            }
        }
    }
    Checkers::~Checkers() {
        
    }
    bool Checkers::move(Move move) {
        bool cap;
        int x = move.x;
        int y = move.y;
        char piece = this->board[x][y]
        if (validMove(move, &cap)) {
            if (cap) {
                this->board[x][y] = " ";
                updateTarget(&x, &y, move.dir, piece);
            }
        }
    }
    std::list<Checkers::Move> Checkers::validMoves() {
        // Lists state
    }

    bool isEnemy(char piece, char target) {
        if ((piece == '0' || piece == 'k') && (target == 'O' || target == 'K')) {
            return true;
        }
        if ((piece == 'O' || piece == 'K') && (target == '0' || target == 'k')) {
            return true;
        }
        return false;
    }
    
    bool updateTarget(int* xptr, int* yptr, Direction dir, char piece) {
        std::cout << "Moving piece " << piece << std::endl;
        if (piece == 'O') { // white std
        std::cout << "Moving: " << dir << " " << fl << std::endl;
            switch (dir) {
                case fl: (*xptr)--;
                    (*yptr)++;
                    std::cout << "Moved fl" << std::endl;
                    break;
                case fr: (*xptr)++;
                    (*yptr)++;
                    break;
                case bl: return false;
                case br: return false;
            }
            std::cout << "returned from move " << (*xptr) << " " << *yptr << std::endl;
            return true;
        }
        if (piece == 'K') { // white king
            switch (dir) {
                case fl: (*xptr)--;
                    (*yptr)++;
                    break;
                case fr: (*xptr)++;
                    (*yptr)++;
                    break;
                case bl: (*xptr)--;
                    (*yptr)--;
                    break;
                case br: (*xptr)++;
                    (*yptr)--;
                    break;
            }
            return true;
        }
        if (piece == '0') { // black std
            switch (dir) {
                case fl: (*xptr)--;
                    (*yptr)--;
                    break;
                case fr: (*xptr)++;
                    (*yptr)--;
                    break;
                case bl: return false;
                case br: return false;
            }
            return true;
        }
        if (piece == 'k') { // black king
            switch (dir) {
                case fl: (*xptr)--;
                    (*yptr)--;
                    break;
                case fr: (*xptr)++;
                    (*yptr)--;
                    break;
                case bl: (*xptr)--;
                    (*yptr)++;
                    break;
                case br: (*xptr)++;
                    (*yptr)++;
                    break;
            }
            return true;
        }
        return false;
    }

    std::list<Checkers::Move> validMoves(int x, int y) {
        
    }
    bool Checkers::validMove(Checkers::Move move, bool* capture) {
        std::cout << "Checking piece at " << move.x << " " << move.y << std::endl;
        char piece = this->board[move.x][move.y];
        std::cout << "Found piece:" << piece << "." << std::endl;
        int x = move.x;
        int y = move.y;
        if (updateTarget(&x, &y, move.dir, piece)) {
            char target = this->board[x][y];
            if (checkEmpty(x, y)) {
                std::cout << "Move is valid, move" << std::endl;
                (*capture) = false;
                return true;
            } else if (isEnemy(piece, target) && updateTarget(&x, &y, move.dir, piece) && checkEmpty(x, y)) {
                std::cout << "Move is valid, capture" << std::endl;
                (*capture) = true;
                return true;
            } else {
                std::cout << "checked point " << x << " " << y << "And found " << this->board[x][y] << std::endl;
                std::cout << "Move is not valid boolean" << std::endl;
                return false;
            }
        } else {
            std::cout << "Move is not valid target: " << piece << std::endl;
            return false;
        }
    }
    
    bool Checkers::checkEmpty(int x, int y) {
        if (x >= 0 && x < 8 && y >= 0 && y < 8) {
            char target = this->board[x][y];
            if (target == ' ') {
                return true;
            }
        }
        return false;
    }
    
    void Checkers::drawBoard() {
        for (int y = 7; y >= 0; y--) {
            for (int x = 0; x < this->board.size(); x++) {
                std::cout << this->board[x][y];
            }
            std::cout << std::endl;
        }
    }
}