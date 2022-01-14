#include <windows.h>
#include <stdlib.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glut.h>
#include <math.h>

int SCREEN_WIDTH = 1280;
int SCREEN_HEIGHT = 720;
float mcX = 0.0;
float mchandX = -0.4;
float mcEyeX = -0.8;
float mcEyeBX = -0.75;


int tx = 0;
int ty = 0;

GLUquadricObj* n = gluNewQuadric();


void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void body()
{
    //head
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat head[] = { 2.0, 1.0, -1.0, -2.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, head);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(mcX, 0.3, -4.0);
    glColor3ub(240, 184, 160);
    glutSolidSphere(0.15, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    //eye start
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat eye[] = { 1.0, 1.0, -1.0, -2.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, eye);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(-0.06, 0.28, -3.3);
    glColor3ub(255, 255, 255);
    glScaled(1.0, 0.6, 1.0);
    glutSolidSphere(0.05, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat eye2[] = { 1.0, 1.0, -1.0, -2.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, eye2);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(-0.07, 0.28, -3.2);
    glColor3ub(0, 0, 0);
    glutSolidSphere(0.02, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    //eye ends

    // Body start
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat body[] = { 2.0, 1.0, -1.0, -2.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, body);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(mcX, 0.0, -4.0);
    glColor3ub(0, 193, 255);
    glutSolidSphere(0.2, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat body2[] = { 2.0, 1.0, -1.0, -2.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, body2);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(mcX, -0.45, -4.0);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    glColor3ub(0, 193, 255);
    gluCylinder(n, 0.2, 0.2, 0.45, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    //body end

    //lower body
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat body3[] = { 2.0, 1.0, -1.0, -2.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, body3);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(mcX, -0.7, -4.0);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    glColor3ub(0, 0, 220);
    gluCylinder(n, 0.17, 0.17, 0.25, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);


    //legs
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat body4[] = { 2.0, 1.0, -1.0, -2.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, body4);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(mcX, -1.0, -4.0);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    glColor3ub(240, 184, 160);
    gluCylinder(n, 0.1, 0.1, 0.35, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);


    //shoes
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat body5[] = { 2.0, 1.0, -1.0, -2.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, body5);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(mcX, -1.05, -4.0);
    glColor3ub(240, 0, 0);
    glScaled(1.0, 0.6, 1.0);
    glutSolidSphere(0.15, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

void hand()
{

    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat arm[] = { 2.0, 1.0, -1.0, -2.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, arm);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(-0.02, -0.03, -3.3);
    glColor3ub(240, 184, 160);
    glutSolidSphere(0.07, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat arm2[] = { 2.0, 1.0, -1.0, -2.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, arm2);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(-0.02, -0.03, -3.3);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glColor3ub(240, 184, 160);
    gluCylinder(n, 0.07, 0.07, 0.4, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat arm3[] = { 2.0, 1.0, -1.0, -2.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, arm3);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(-0.02, -0.49, -3.3);
    glColor3ub(240, 184, 160);
    glutSolidSphere(0.07, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

void court()
{
    glLoadIdentity();
    glBegin(GL_QUADS);
    glColor3ub(194, 197, 204);
    glVertex3f(-6.0, -1.5, -2.0);
    glVertex3f(-6.0, -1.0, -10.0);
    glVertex3f(8.0, -1.0, -10.0);
    glVertex3f(8.0, -1.5, -2.0);

    glColor3ub(200, 0, 0);
    glVertex3f(-5, -1.49, -2.5);
    glVertex3f(-5, -0.99, -8.5);
    glVertex3f(-4.8, -0.99, -8.5);
    glVertex3f(-4.8, -1.49, -2.5);

    glColor3ub(200, 0, 0);
    glVertex3f(-5, -0.99, -8.5);
    glVertex3f(-5, -0.99, -8.7);
    glVertex3f(8, -0.99, -8.7);
    glVertex3f(8, -0.99, -8.5);

    glEnd();
}

void background()
{

    glLoadIdentity();
    glBegin(GL_QUADS);
    glColor3ub(25, 189, 255);
    glVertex3f(-10, 10, -12);
    glVertex3f(10, 10, -12);
    glVertex3f(10, -10, -12);
    glVertex3f(-10, -10, -12);

    glColor3ub(0, 200, 0);
    glVertex3f(-10, -1, -11.9);
    glVertex3f(10, -1, -11.9);
    glVertex3f(10, -6, -11.9);
    glVertex3f(-10, -6, -11.9);
    glEnd();
}

void tick()
{
    glLoadIdentity();                 // Reset the model-view matrix
    glTranslatef(-1.5f, 0.5f, -7.0f);  // Move right and into the screen
    //glRotatef(yRotated, 0.0, 1.0, 0.0);
    //draw tick
    glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
       // Define vertices in counter-clockwise (CCW) order with normal pointing out
    glColor3f(0.0f, 1.0f, 0.0f);     // green
    glVertex3f(tx + 0.40f, ty + 0.30f, 0.15f);
    glVertex3f(tx, ty - 0.10f, 0.15f);
    glVertex3f(tx - 0.20, ty, 0.15f);
    glVertex3f(tx, ty - 0.25f, 0.15f);

    glColor3f(0.0f, 1.0f, 0.0f);     // green
    glVertex3f(tx + 0.40f, ty + 0.30f, 0.05f);
    glVertex3f(tx, ty - 0.10f, 0.05f);
    glVertex3f(tx - 0.20, ty, 0.05f);
    glVertex3f(tx, ty - 0.25f, 0.05f);

    //topcover
    glColor3f(0.0f, 0.50f, 0.0f); //dark green
    glVertex3f(tx + 0.40f, ty + 0.30f, 0.05f);
    glVertex3f(tx + 0.40f, ty + 0.30f, 0.15f);
    glVertex3f(tx, ty - 0.10f, 0.15f);
    glVertex3f(tx, ty - 0.10f, 0.05f);

    glColor3f(0.0f, 0.50f, 0.0f); //dark green
    glVertex3f(tx - 0.20, ty, 0.05f);
    glVertex3f(tx - 0.20, ty, 0.15f);
    glVertex3f(tx, ty - 0.10f, 0.15f);
    glVertex3f(tx, ty - 0.10f, 0.05f);

    //bottom cover
    glColor3f(0.0f, 0.50f, 0.0f); //dark green
    glVertex3f(tx - 0.20, ty, 0.05f);
    glVertex3f(tx - 0.20, ty, 0.15f);
    glVertex3f(tx, ty - 0.25f, 0.15f);
    glVertex3f(tx, ty - 0.25f, 0.05f);

    glColor3f(0.0f, 0.50f, 0.0f); //dark green
    glVertex3f(tx + 0.40f, ty + 0.30f, 0.05f);
    glVertex3f(tx + 0.40f, ty + 0.30f, 0.15f);
    glVertex3f(tx, ty - 0.25f, 0.15f);
    glVertex3f(tx, ty - 0.25f, 0.05f);



    glEnd();  // End of drawing 
}



void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    body();
    hand();
    tick();

    court();
    background();

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
    glutCreateWindow("test");
    glutDisplayFunc(display);
    glutReshapeFunc(k_reshape);
    //glutTimerFunc(0, timer, 0);
    //glutIdleFunc(idleFunc);
    initGL();
    glutMainLoop();

}