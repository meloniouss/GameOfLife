//
// Created by Andrei Jianu on 2024-05-14.
//
#include "cell.h"
cell::cell(){};
cell::cell(bool state): alive(state) {}

void cell::Draw(int i,int j, int width, int height, Color colour)
{
    DrawRectangle(i,j,width,height,colour);
}
void cell::Update() {
    if(!alive){
        ClearBackground(WHITE);
    }
}