#pragma once

#include <queue>
#include <math.h>
#include <iostream>
#include <vector>

class World{
    public:
        World(int x, int y);
        void invert(int x, int y);
        int step();
        struct paint{
            int x;
            int y;
        };
        paint getInvert();
        int sizeInv();
        bool operator[] (paint pnt);

    private:
        paint _size;

        void inOnCk(paint pnt);
        std::queue<paint> _onCheck;
        std::queue<paint> _onInvert;
        std::vector<std::vector<bool>> _map;
        std::vector<std::vector<bool>> _check;
};