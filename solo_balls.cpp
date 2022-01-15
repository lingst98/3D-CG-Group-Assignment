#include <windows.h>
#include <stdlib.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glut.h>
#include <math.h>

int SCREEN_WIDTH = 1280;
int SCREEN_HEIGHT = 720;
int PI = 3.142;
int angle = 0;

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

//drawing starts here

//ball_solo
void big_ball() {
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -6.0);
    glRotatef(angle, 0.0, 0.0, 1.0);
    glColor3ub(40, 25, 255);
    //lights
    glEnable(GL_COLOR_MATERIAL); //cheat
    glEnable(GL_LIGHTING); //turn on lighting
    GLfloat dir[] = { 0.2, 0.0, 1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, dir);
    glEnable(GL_LIGHT0);
    glutSolidSphere(2.0, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

//animation
void ball_animation() {
    angle + 2;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    big_ball();
    glFlush();
    glutSwapBuffers();
}


void k_reshape(GLsizei SCREEN_WIDTH, GLsizei SCREEN_HEIGHT) {
    if (SCREEN_HEIGHT == 0) SCREEN_HEIGHT = 1;
    GLfloat aspect = (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT;

    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0f, aspect, 0.1f, 20.0f);
}

int  main(int argc, char** argv) {
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInit(&argc, argv);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutCreateWindow("im just trying");
    glutDisplayFunc(display);
    glutReshapeFunc(k_reshape);
    initGL();
    glutMainLoop();

}