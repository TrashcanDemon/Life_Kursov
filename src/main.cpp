#include "printer.h"

Printer M;

void startDraw(){M.startDraw();}
void clicMause(int b, int s, int x, int y){M.clicMause(b, s, x, y);}
void reshWin(int w, int h){M.reshWin(w, h);}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_ACCUM);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("LIVE");
    glutReshapeFunc(reshWin);
    glutDisplayFunc(startDraw);
    glutMouseFunc(clicMause);
    glutMainLoop();
    return 0;
}