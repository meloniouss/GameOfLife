//
// Created by Andrei Jianu on 2024-05-14.
//
#include "/opt/homebrew/Cellar/raylib/5.0/include/raylib.h"
#ifndef UNTITLED_CELL_H
#define UNTITLED_CELL_H
class cell{
public:
    cell();

    bool alive;
    cell(bool state);
    void Draw(int i, int j, int width, int height, Color colour);

    void Update();
};
#endif //UNTITLED_CELL_H
