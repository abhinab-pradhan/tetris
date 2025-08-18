#include "grid.h"
#include "colors.h"
#include<iostream>
using namespace std;


Grid::Grid(){
    numRows=20;
    numCols=10;
    cellSize=30;
    initialize();
    colors=getCelllColors();
}

void Grid::initialize(){
    for (int row=0;row<numRows;row++){
        for(int column=0;column<numCols;column++){

            grid[row][column]=0;  //look all the array then apply 0
        }
    }
}

void Grid::print(){
    for (int row=0;row<numRows;row++){
        for(int column=0;column<numCols;column++){
            cout<<grid[row][column]<<" ";
        }
        cout<<endl;
    }
}


void Grid::draw(){
    for(int row=0;row<numRows;row++){
        for(int column=0;column<numCols;column++){
            int cellValues=grid[row][column];
            DrawRectangle(column*cellSize+1,row*cellSize+1,cellSize-1,cellSize-1,colors[cellValues]);
        }
    }
}

bool Grid::isCellOutSide(int row,int column){
    if(row>= 0 && row< numRows && column>=0 &&column<numCols){
        return false;
    }
    return true;
}

bool Grid::isCellEmpty(int row,int column){
    if(grid[row][column] == 0){
        return true;
    }
    return false;
}
