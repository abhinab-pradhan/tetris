#include "grid.h"
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

std::vector<Color> Grid::getCelllColors(){
    Color darkGrey={26,31,40,255};
    Color green={47,230,23,255};
    Color red={232,18,18,255};
    Color yellow={237,234,4,255};
    Color purple={166,0,247,255};
    Color cyan={21,204,209,255};
    Color blue={13,64,216,255};

    return {darkGrey,green,red,yellow,purple,cyan,blue};
}

void Grid::draw(){
    for(int row=0;row<numRows;row++){
        for(int column=0;column<numCols;column++){
            int cellValues=grid[row][column];
            DrawRectangle(column*cellSize+1,row*cellSize+1,cellSize-1,cellSize-1,colors[cellValues]);
        }
    }
}