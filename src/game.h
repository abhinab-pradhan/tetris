#pragma once
#include "grid.h"
#include "blocks.cpp"
class Game{
    public:
        Game();
        Block GetRandomBlock();
        std::vector<Block> GetAllBlocks();
        void Draw();
        void handleInput();
        void moveBlockLeft();
        void moveBlockRight();
        void moveBlockDown();
        Grid grid;
        bool gameOver;
        int score;

    private:
        bool isBlockOutside();
        void rotateBlock();
        void LockBlock();
        bool blockFits();
        void reset();
        void updateScore(int linesCleared,int moveDownPoint);
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
};
