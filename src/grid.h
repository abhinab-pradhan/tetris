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
        int grid[20][20];
    private:
        int numRows;
        int numCols;
        int cellSize;
        std::vector<Color> colors;
        std::vector<Color> getCelllColors();

};