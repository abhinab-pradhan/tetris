#include "game.h"
#include <random>
Game ::Game(){
    grid=Grid();
    blocks=GetAllBlocks();
    currentBlock=GetRandomBlock();
    nextBlock=GetRandomBlock();
}

Block Game::GetRandomBlock(){
    if(blocks.empty()){
        blocks=GetAllBlocks();
    }
    int randomIndex=rand()% blocks.size();
    Block block=blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

std::vector<Block> Game::GetAllBlocks(){
    return {IBlock(),JBlock(),LBlock(),OBlock(),SBlock(),TBlock(),ZBlock()};
}

void Game::Draw(){
    grid.draw();
    currentBlock.Draw();
}

void Game::handleInput(){
    int keyPressed=GetKeyPressed();
    switch (keyPressed)
    {
    case KEY_LEFT:
        moveBlockLeft();
        break;
    case KEY_RIGHT:
        moveBlockRight();
        break;
    case KEY_DOWN:
        moveBlockDown();
        break;
    case KEY_UP:
        rotateBlock();
        break;
    default:
        break;
    }
}

void Game::moveBlockLeft(){
    currentBlock.Move(0,-1);
    if(isBlockOutside() || blockFits() ==false){
        currentBlock.Move(0,1);
    }
}

void Game::moveBlockRight(){
    currentBlock.Move(0,1);
    if(isBlockOutside() || blockFits() ==false){
        currentBlock.Move(0,-1);
    }
}

void Game::moveBlockDown(){
    currentBlock.Move(1,0);
    if(isBlockOutside() || blockFits() ==false){
        currentBlock.Move(-1,0);
        LockBlock();
    }
}

bool  Game::isBlockOutside(){
    std::vector<Position> tiles=currentBlock.GetCellPosition();
    for(Position item: tiles){
        if(grid.isCellOutSide(item.row,item.column)){
            return true;
        }
    }
    return false;
}

void Game::rotateBlock(){
    currentBlock.Rotate();
    if(isBlockOutside() || blockFits() ==false){
        currentBlock.UndoRotation();
    }
}

void Game::LockBlock(){
    std::vector<Position> tiles= currentBlock.GetCellPosition();
    for(Position item:tiles){
        grid.grid[item.row][item.column]= currentBlock.id;
    }
    currentBlock=nextBlock;
    nextBlock=GetRandomBlock();
}

bool Game::blockFits(){
    std::vector<Position> tiles=currentBlock.GetCellPosition();
    for(Position item: tiles){
        if(grid.isCellEmpty(item.row,item.column) == false){
            return false;
        }
    }
    return true;
}
