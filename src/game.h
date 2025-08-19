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

    private:
        bool isBlockOutside();
        void rotateBlock();
        void LockBlock();
        bool blockFits();
        void reset();
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
};
