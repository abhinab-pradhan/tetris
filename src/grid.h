#pragma once
#include <vector>
#include <raylib.h>
class Grid
{
    public:
        Grid();
        void initialize();
        void print();
        void draw();
        bool isCellOutSide(int row,int column);
        bool isCellEmpty(int row,int column);
        int clearFulllRows();
        int grid[20][20];
    private:
        bool isRowFull(int row);
        void clearRow(int row);
        void moveRowDown(int row,int numRows);
        int numRows;
        int numCols;
        int cellSize;
        std::vector<Color> colors;

};
