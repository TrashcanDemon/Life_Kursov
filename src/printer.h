#pragma once

#include "GL\glut.h"
#include "world.h"

typedef unsigned int uint;

class Printer{
public:
    Printer();
    ~Printer() = default;
    void startDraw();
    void clicMause(int button, int state, int x, int y);
    void reshWin(int width, int height);
    struct coord{
        float w;
        float h;
    };
private:
    void printCell(int x, int y);
    void printPauseButton(bool play);

    bool starter=1;
    bool play = 0;
    bool invCell = 0;
    bool step = 0;
    uint _sizeCell;
    uint timer = 0;
    uint speed = 10;
    World::paint _sizeMap;
    World::paint _sizeWin;
    coord _CellHW;
    World *Map;
};