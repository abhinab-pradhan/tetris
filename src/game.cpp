#include "game.h"
#include <random>
Game ::Game(){
    grid=Grid();
    blocks=GetAllBlocks();
    currentBlock=GetRandomBlock();
    nextBlock=GetRandomBlock();
    gameOver=false;
    score=0;
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
    currentBlock.Draw(11,11);
    nextBlock.Draw(270,270);
}

void Game::handleInput(){
    int keyPressed=GetKeyPressed();
    if(gameOver && keyPressed!=0){
        gameOver=false;
        reset();
    }
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
        updateScore(0,1);
        break;
    case KEY_UP:
        rotateBlock();
        break;
    default:
        break;
    }
}

void Game::moveBlockLeft(){
    if(!gameOver){

    
    currentBlock.Move(0,-1);
    if(isBlockOutside() || blockFits() ==false){
        currentBlock.Move(0,1);
    }
}
}

void Game::moveBlockRight(){
    if(!gameOver){
    currentBlock.Move(0,1);
    if(isBlockOutside() || blockFits() ==false){
        currentBlock.Move(0,-1);
    }
}
}

void Game::moveBlockDown(){
    if(!gameOver){
    currentBlock.Move(1,0);
    if(isBlockOutside() || blockFits() ==false){
        currentBlock.Move(-1,0);
        LockBlock();
    }
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
    if(!gameOver){
    currentBlock.Rotate();
    if(isBlockOutside() || blockFits() ==false){
        currentBlock.UndoRotation();
    }
}
}

void Game::LockBlock(){
    std::vector<Position> tiles= currentBlock.GetCellPosition();
    for(Position item:tiles){
        grid.grid[item.row][item.column]= currentBlock.id;
    }
    currentBlock=nextBlock;
    if(blockFits() == false){
        gameOver=true;
    }
    nextBlock=GetRandomBlock();
    int rowsCleared=grid.clearFulllRows();
    updateScore(rowsCleared,0);
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

void Game::reset(){
    grid.initialize();
    blocks=GetAllBlocks();
    currentBlock=GetRandomBlock();
    nextBlock=GetRandomBlock();
    score=0;
}

void Game::updateScore(int linesCleared,int moveDownPoint){
    switch (linesCleared)
    {
    case 1 :
        score+=10;
        break;
    case 2:
        score+=30;
        break;
    case 3:
        score+=50;
        break;
    default:
        break;
    }

    score+=moveDownPoint;
}
