#include "/opt/homebrew/Cellar/raylib/5.0/include/raylib.h"
#include "cell.h"
#include <cmath>
#include <iostream>

const int columns{24};
const int rows{24};

int countNeighbors(const cell cellGrid[columns][rows],int i , int j){
    int count = 0;
    for (int x = std::max(0, i - 1); x < std::min(columns, i + 2); ++x) {
        for (int y = std::max(0, j - 1); y < std::min(rows, j + 2); ++y) {
            if (x != i || y != j) {
                count += cellGrid[x][y].alive ? 1 : 0;
            }
        }
    }
    return count;
}
void updateGrid(cell cellGrid[columns][rows])
{
    for(int i = 0; i < columns; i++)
    {
        for(int j = 0; j < rows; j++)
        {
           if(cellGrid[i][j].alive)
           {
               if(countNeighbors(cellGrid, i,j) < 2 || countNeighbors(cellGrid,i,j) > 3)
                   cellGrid[i][j].alive = false;
               else if(countNeighbors(cellGrid,i,j) >= 2 && countNeighbors(cellGrid,i,j) <=3)
               {
                   cellGrid[i][j].alive = true;
               }
           }
           else{
               if(countNeighbors(cellGrid,i,j) == 3)
               {
                   cellGrid[i][j].alive = true;
               }
           }
        }
    }
}

int main() {
    const int screenWidth = 800;
    const int screenHeight = 800;
    const int cellWidth = screenWidth / columns;
    const int cellHeight = screenHeight / rows;
    bool isInitialized = false;
    cell cellGrid[columns][rows];
    InitWindow(screenWidth, screenHeight, "GAME OF LIFE");
    SetTargetFPS(60);
    //initializing grid below
    for(int i = 0; i < columns; i++)
    {
        for(int j = 0; j < rows; j++){
            DrawRectangleLines(i*cellWidth, j*cellHeight,cellWidth,cellHeight,BLACK);
        }
    }

    int iterations = 0;
    while (!WindowShouldClose()) {
        ++iterations;
        updateGrid(cellGrid);
        BeginDrawing();
        //we initialize the cells randomly
        while(!isInitialized)
        {
            for(int i = 0; i < columns; i++)
            {
                for(int j = 0; j < rows; j++)
                {
                    bool state = rand() % 2 == 0; // Randomly set true or false
                    cellGrid[i][j] = cell(state);
                    if (state)
                    {
                        cellGrid[i][j].Draw(i*cellWidth,j*cellHeight,cellWidth,cellHeight,BLACK);
                    }
                    else{
                        cellGrid[i][j].Draw(i*cellWidth,j*cellHeight,cellWidth,cellHeight,WHITE);
                    }

                }
            }
            isInitialized = true;
        }

        for(int i = 0; i < columns; i++) // this is the loop that redraws the cells to show them living and dying
        {
            for(int j = 0;j < rows; j++)
            {
                if(cellGrid[i][j].alive){
                    cellGrid[i][j].Draw(i*cellWidth,j*cellHeight,cellWidth,cellHeight,BLACK);
                }
                else{
                    cellGrid[i][j].Draw(i*cellWidth,j*cellHeight,cellWidth,cellHeight,WHITE);
                }
            }
        }
        DrawText(TextFormat("ITERATIONS: %i", iterations), 5, 20, 30, BLUE);
        EndDrawing();
    }

    // De-Initialization
    CloseWindow();  // Close window and OpenGL context

    return 0;
}
