#ifndef CHECKERS_H
#define CHECKERS_H

#include <vector>
#include <list>

namespace minimax {
    enum Direction { fl, fr, bl, br };
    class Checkers {
        public:
        static int main();
        std::vector<std::vector<char> > board;
        struct Move {
            int x;
            int y;
            Direction dir;
            Move(int x, int y, Direction dir) {
                this->x = x;
                this->y = y;
                this->dir = dir;
            }
        };
        Checkers();
        ~Checkers();
        bool move(Checkers::Move move);
        std::list<Move> validMoves();
        void drawBoard();
        bool validMove(Checkers::Move move, bool* capture);
        bool checkEmpty(int x, int y);
    };
}
#endif