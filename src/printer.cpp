#include "printer.h"

Printer::Printer(){
    _sizeMap = {30,20};
    Map = new World(_sizeMap.x, _sizeMap.y);
}

void Printer::startDraw(){
    if(starter){
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POLYGON);
            glColor3f(1,1,1);
            glVertex2f(-1, -1);
            glVertex2f(-1, 1);
            glVertex2f(0.6, 1);
            glVertex2f(0.6, -1);
        glEnd();

        glBegin(GL_LINES);
            glColor3f(1,1,1);
            for (float i = -0.5; i <= 0.5; i+=0.5){
                glVertex2f(0.6, i);
                glVertex2f(1, i);
            }
        glEnd();
        glBegin(GL_TRIANGLES);
            glColor3f(1,1,1);
            glVertex2f(0.67, 0.4);
            glVertex2f(0.85, 0.25);
            glVertex2f(0.67, 0.1);

            glVertex2f(0.68, -0.1);
            glVertex2f(0.8, -0.25);
            glVertex2f(0.68, -0.4);

            glVertex2f(0.78, -0.1);
            glVertex2f(0.9, -0.25);
            glVertex2f(0.78, -0.4);

            glVertex2f(0.9, -0.6);
            glVertex2f(0.78, -0.75);
            glVertex2f(0.9, -0.9);

            glVertex2f(0.8, -0.6);
            glVertex2f(0.68, -0.75);
            glVertex2f(0.8, -0.9);
        glEnd();
        glBegin(GL_QUADS);
            glColor3f(1,1,1);
            glVertex2f(0.85, 0.4);
            glVertex2f(0.85, 0.1);
            glVertex2f(0.9, 0.1);
            glVertex2f(0.9, 0.4);
        glEnd();

        for(int y = 0; y<_sizeMap.y; y++)
            for(int x = 0; x<_sizeMap.x; x++)
                printCell(x,y);
        starter=0;
    }
    if(invCell){
        int n = Map->sizeInv();
        for (int i = 0; i < n; i++){
            World::paint pnt = Map->getInvert();
            printCell(pnt.x-2, pnt.y-2);
        }
        invCell = 0;
    }
    if(step){
        Map->step();
        int n = Map->sizeInv();
        World::paint pnt;
        for(int i = 0; i < n; i++){
            pnt = Map->getInvert();
            printCell(pnt.x-2, pnt.y-2);
        }
        step = 0;
    }
    if(play){
        int m = 0;
        if (timer >= speed){
            m = Map->step();
            int n = Map->sizeInv();
            World::paint pnt;
            for(int i = 0; i < n; i++){
                pnt = Map->getInvert();
                printCell(pnt.x-2, pnt.y-2);
            }
            timer = 0;
        }
        timer++;
        glutPostRedisplay();
        Sleep(25);
        if (m) play = 0;
    }
    printPauseButton(play);
    glFlush();
}

void Printer::clicMause(int button, int state, int x, int y){
    if(x<_sizeCell*_sizeMap.x*1.05 && y<_sizeCell*_sizeMap.y*1.05 && button==GLUT_LEFT_BUTTON && state==GLUT_UP){
        Map->invert(x/(_sizeCell*1.05)+1,y/(_sizeCell*1.05)+1);
        invCell = 1;
    }
    if(x>_sizeWin.x*0.8 && button==GLUT_LEFT_BUTTON && state==GLUT_UP){
        int location = 4*y/_sizeWin.y;
        switch(location){
            case 0:
                play = -1*play+1;
                timer = 0;
                break;
            case 1:
                step = 1;
                break;
            case 2:
                speed--;
                if (speed==0) speed++;
                break;
            case 3:
                speed++;
                if (speed==4294967295) speed--;
                break;
        }
    }
}

void Printer::reshWin(int width, int height){
    if(height==0) height=1;
    _sizeCell = (0.8*width/(_sizeMap.x*1.05) > height/(_sizeMap.y*1.05)) ? height/(_sizeMap.y*1.05) : 0.8*width/(_sizeMap.x*1.05);
    _CellHW = {(float)(2.0*_sizeCell/width), (float)(2.0*_sizeCell/height)};
    _sizeWin = {width, height};
    glViewport(0, 0, width, height);
    starter=1;
}

void Printer::printCell(int x, int y){
    World::paint pnt = {x+1,y+1};
    glBegin(GL_POLYGON);
    if(Map[0][pnt])
        glColor3f(1,1,1);
    else
        glColor3f(0, 0, 0);
    glVertex2f(-1+x*_CellHW.w*1.05, 1-y*_CellHW.h*1.05);
    glVertex2f(-1+x*_CellHW.w*1.05+_CellHW.w, 1-y*_CellHW.h*1.05);
    glVertex2f(-1+x*_CellHW.w*1.05+_CellHW.w, 1-y*_CellHW.h*1.05-_CellHW.h);
    glVertex2f(-1+x*_CellHW.w*1.05, 1-y*_CellHW.h*1.05-_CellHW.h);
    glEnd();
}

void Printer::printPauseButton(bool play){
    switch(play)
        case 0:
            glBegin(GL_QUADS);
                glColor3f(0, 0, 0);
                glVertex2f(0.68, 0.92);
                glVertex2f(0.68, 0.58);
                glVertex2f(0.9, 0.58);
                glVertex2f(0.9, 0.92);
            glEnd();
            glBegin(GL_TRIANGLES);
                glColor3f(1,1,1);
                glVertex2f(0.68, 0.92);
                glVertex2f(0.9, 0.75);
                glVertex2f(0.68, 0.58);
            glEnd();
            break;
        case 1:
            glBegin(GL_QUADS);
                glColor3f(0,0,0);
                glVertex2f(0.68, 0.92);
                glVertex2f(0.68, 0.58);
                glVertex2f(0.9, 0.58);
                glVertex2f(0.9, 0.92);

                glColor3f(1,1,1);
                glVertex2f(0.68, 0.92);
                glVertex2f(0.68, 0.58);
                glVertex2f(0.78, 0.58);
                glVertex2f(0.78, 0.92);

                glVertex2f(0.8, 0.92);
                glVertex2f(0.8, 0.58);
                glVertex2f(0.9, 0.58);
                glVertex2f(0.9, 0.92);
            glEnd();
            break;
    }
}