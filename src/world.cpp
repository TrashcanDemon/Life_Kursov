#include "world.h"

World::World(int x, int y){
    _size.x = x+1;
    _size.y = y+1;
    _map.assign(x+2, std::vector<bool>(y+2));
    _map.assign(x+2, std::vector<bool>(y+2));
    _check.assign(x+2, std::vector<bool>(y+2));
    _check.assign(x+2, std::vector<bool>(y+2));
}


void World::invert(int x, int y){
    paint pnt = {x,y};
    _onInvert.push(pnt);
}

int World::step(){
    if(_onCheck.size()){
        int n = _onCheck.size();
        for(int i = 0; i < n; i++){
            paint pnt;
            pnt = _onCheck.front();
            _onCheck.pop();
            _check[pnt.x][pnt.y] = 0;
            int about = 0;
            about += _map[pnt.x-1][pnt.y];
            about += _map[pnt.x-1][pnt.y+1];
            about += _map[pnt.x][pnt.y+1];
            about += _map[pnt.x+1][pnt.y+1];
            about += _map[pnt.x+1][pnt.y];
            about += _map[pnt.x+1][pnt.y-1];
            about += _map[pnt.x][pnt.y-1];
            about += _map[pnt.x-1][pnt.y-1];
            bool m = (_map[pnt.x][pnt.y]*(about-3)+(about-2))*about*(about-1)*(about-4)*(about-5)*(about-6)*(about-7)*(about-8);
            if(m!=_map[pnt.x][pnt.y]) {
                inOnCk(pnt);
                _onInvert.push(pnt);
            }
        }
    }else{
        return 1;
    }
    return 0;
}

World::paint World::getInvert(){
    paint pnt = _onInvert.front();
    _onInvert.pop();
    _map[pnt.x][pnt.y] = -1*_map[pnt.x][pnt.y]+1;
    inOnCk(pnt);
    pnt.x++;
    pnt.y++;
    return pnt;
}

int World::sizeInv(){
    return _onInvert.size();
}

bool World::operator[](paint pnt){
    return _map[pnt.x][pnt.y];
}

void World::inOnCk(paint pnt){
    if(!_check[pnt.x][pnt.y]){
        _check[pnt.x][pnt.y] = 1;
        _onCheck.push(pnt);
    }
    paint pntC;
    for(int j = 0; j<8; j++){
        pntC = {pnt.x + (int)round(cos(j*M_PI/4)*1.414), pnt.y + (int)round(sin(j*M_PI/4)*1.414)};
        if((!_check[pntC.x][pntC.y])&&pntC.x&&pntC.y&&(pntC.x-_size.x)&&(pntC.y-_size.y)){
            _onCheck.push(pntC);
            _check[pntC.x][pntC.y] = 1;
        }
    }
}