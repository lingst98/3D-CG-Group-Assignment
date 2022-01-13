#include <windows.h>
#include <stdlib.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glut.h>
#include <math.h>

int SCREEN_WIDTH = 1280;
int SCREEN_HEIGHT = 720;
int PI = 3.142;
GLUquadricObj* n = gluNewQuadric();

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

//drawing starts here

//head
void head() {
    glLoadIdentity();
    glTranslatef(0.0, 1.6, -6.0);
    glColor3ub(255, 75, 28);
    //lights
    glEnable(GL_COLOR_MATERIAL); //cheat
    glEnable(GL_LIGHTING); //turn on lighting
    GLfloat dir[] = { 0.2, 0.0, 1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, dir);
    glEnable(GL_LIGHT0);
    glutSolidSphere(0.3, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
   
    //depth buffer
   // glEnable(GL_DEPTH_TEST);

    
}

//body
void upper_body(){
    glLoadIdentity();
    glTranslatef(0.0, 0.85, -6.0);
    glRotatef(15, 1.0, 0.0, 0.0);
    glColor3ub(0, 193, 255);
    glScalef(3.0, 2.3, 1.5);

    /*
    //lighting
    glEnable(GL_COLOR_MATERIAL); //cheat
    GLfloat body[] = { 0.2, 0.0, 1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, body);
    glEnable(GL_LIGHTING); //turn on lighting
    glEnable(GL_LIGHT0);
    */

    glBegin(GL_QUADS);
    //Top
    glVertex3f(0.2f, 0.2f, -0.2f);
    glVertex3f(-0.2f, 0.2f, -0.2f);
    glVertex3f(-0.2f, 0.2f, 0.2f);
    glVertex3f(0.2f, 0.2f, 0.2f);

    //Bottom
    glVertex3f(0.2f, -0.2f, 0.2f);
    glVertex3f(-0.2f, -0.2f, 0.2f);
    glVertex3f(-0.2f, -0.2f, -0.2f);
    glVertex3f(0.2f, -0.2f, -0.2f);

    //Front
    glVertex3f(0.2f, 0.2f, 0.2f);
    glVertex3f(-0.2f, 0.2f, 0.2f);
    glVertex3f(-0.2f, -0.2f, 0.2f);
    glVertex3f(0.2f, -0.2f, 0.2f);

    //Back
    glVertex3f(0.2f, -0.2f, -0.2f);
    glVertex3f(-0.2f, -0.2f, -0.2f);
    glVertex3f(-0.2f, 0.2f, -0.2f);
    glVertex3f(0.2f, 0.2f, -0.2f);

    //Left
    glVertex3f(-0.2f, 0.2f, 0.2f);
    glVertex3f(-0.2f, 0.2f, -0.2f);
    glVertex3f(-0.2f, -0.2f, -0.2f);
    glVertex3f(-0.2f, -0.2f, 0.2f);

    //Right
    glVertex3f(0.2f, 0.2f, -0.2f);
    glVertex3f(0.2f, 0.2f, 0.2f);
    glVertex3f(0.2f, -0.2f, 0.2f);
    glVertex3f(0.2f, -0.2f, -0.2f);

    glEnd();

    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    //depth buffer
    //glEnable(GL_DEPTH_TEST);
    
}

//Right_Hand
void right_hand() {
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat hand[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, hand);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(0.55, 1.1, -6.0);
    glRotatef(60.0, 1.0, 1.0, 0.0);
    glColor3ub(0, 193, 255);
    gluCylinder(n, 0.25, 0.25, 0.75, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    }

//forearms_right
void right_forearm() {
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat hand[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, hand);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(1.1, 0.55, -5.5);
    glRotatef(60.0, 1.0, 1.0, 0.0);
    glColor3ub(0, 193, 255);
    gluCylinder(n, 0.22, 0.22, 0.75, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

//palm_right
void right_palm() {
    glLoadIdentity();
    glTranslatef(1.65, 0.05, -5.2);
    glColor3ub(255, 75, 28);
    //lights
    glEnable(GL_COLOR_MATERIAL); //cheat
    glEnable(GL_LIGHTING); //turn on lighting
    GLfloat dir[] = { 0.2, 0.0, 1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, dir);
    glEnable(GL_LIGHT0);
    glutSolidSphere(0.21, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}
  
//Left_Hand
void left_hand() {
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat hand[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, hand);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(-0.55, 1.1, -6.0);
    glRotatef(-60, 0.0, 1.0, -0.5);
    glColor3ub(0, 193, 255);
    gluCylinder(n, 0.25, 0.25, 0.75, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

//forearms_left
void left_forearm() {
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat hand[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, hand);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(-1.2, 0.90, -5.5);
    glRotatef(-60, 0.0, 1.0, -0.5);
    glColor3ub(0, 193, 255);
    gluCylinder(n, 0.22, 0.22, 0.70, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

//palm_left
void left_palm() {
    glLoadIdentity();
    glTranslatef(-1.85, 0.77, -5.2);
    glColor3ub(255, 75, 28);
    //lights
    glEnable(GL_COLOR_MATERIAL); //cheat
    glEnable(GL_LIGHTING); //turn on lighting
    GLfloat dir[] = { 0.2, 0.0, 1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, dir);
    glEnable(GL_LIGHT0);
    glutSolidSphere(0.21, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

//Lower body
void lower_body() {
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat hand[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, hand);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(0.0, -1.2, -6.0);
    glRotatef(-90, 1.0, 0.0, 0.0);
    glColor3ub(0, 193, 255);
    gluCylinder(n, 0.8, 0.6, 1.5, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}


//Left_leg
void left_leg() {
    glLoadIdentity();
    glTranslatef(-0.55, -1.5, -6.0);
    glScaled(1.5, 1.0, 1.0);
    glColor3ub(229, 95, 56);
    //lights
    glEnable(GL_COLOR_MATERIAL); //cheat
    glEnable(GL_LIGHTING); //turn on lighting
    GLfloat leg[] = { 0.2, 0.0, 1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, leg);
    glEnable(GL_LIGHT0);
    glutSolidSphere(0.2, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

}

//Right_leg
void right_leg() {
    glLoadIdentity();
    glTranslatef(0.55, -1.5, -6.0);
    glScaled(1.5, 1.0, 1.0);
    glColor3ub(229, 95, 56);
    //lights
    glEnable(GL_COLOR_MATERIAL); //cheat
    glEnable(GL_LIGHTING); //turn on lighting
    GLfloat leg[] = { 0.2, 0.0, 1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, leg);
    glEnable(GL_LIGHT0);
    glutSolidSphere(0.2, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

}

//Joint
void joint1() {
    glLoadIdentity();
    glTranslatef(1.05, 0.57, -5.6);
    glColor3ub(255, 75, 28);
    //lights
    glEnable(GL_COLOR_MATERIAL); //cheat
    glEnable(GL_LIGHTING); //turn on lighting
    GLfloat dir[] = { 0.2, 0.0, 1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, dir);
    glEnable(GL_LIGHT0);
    glutSolidSphere(0.19, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

void joint2() {
    glLoadIdentity();
    glTranslatef(-1.2, 0.95, -5.6);
    glColor3ub(255, 75, 28);
    //lights
    glEnable(GL_COLOR_MATERIAL); //cheat
    glEnable(GL_LIGHTING); //turn on lighting
    GLfloat dir[] = { 0.2, 0.0, 1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, dir);
    glEnable(GL_LIGHT0);
    glutSolidSphere(0.19, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}



void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    head();
    upper_body();
    right_hand();
    left_hand();
    lower_body();
    left_leg();
    right_leg();
    glFlush();
    joint1();
    joint2();
    left_forearm();
    right_forearm();
    left_palm();
    right_palm();
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