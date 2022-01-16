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
float ballX2 = -1.7;
float ballY2 = 1.2;
float G_ballX2 = -1.4;
float G_ballY2 = 1.2;
float B_ballX2 = -2.0;
float B_ballY2 = 1.2;
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

void basketball2()
{
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat basketball[] = { -1.0, 2.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, basketball);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(ballX2, ballY2, -3.3);
    glColor3ub(255, 126, 0);
    glutSolidSphere(0.12, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

void gold_basketball()
{
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat basketball[] = { -1.0, 2.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, basketball);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(G_ballX2, G_ballY2, -3.3);
    glColor3ub(255, 220, 0);
    glutSolidSphere(0.12, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

void blue_basketball()
{
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat basketball[] = { -1.0, 2.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, basketball);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(B_ballX2, B_ballY2, -3.3);
    glColor3ub(40, 25, 255);
    glutSolidSphere(0.12, 100, 100);
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

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000 / 30, timer, 4);

    if (ballX2 < -0.8)
    {
        ballX2 += 0.011;
        ballY2 -= 0.022;
    }

    if (G_ballX2 < -0.5)
    {
        G_ballX2 += 0.011;
        G_ballY2 -= 0.022;
    }

    if (B_ballX2 < -1.1)
    {
        B_ballX2 += 0.011;
        B_ballY2 -= 0.022;
    }

    glutPostRedisplay();
}

void display3ballsDown() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    body();
    hand();
    basketball2();
    gold_basketball();
    blue_basketball();

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
    glutDisplayFunc(display3ballsDown);
    glutReshapeFunc(k_reshape);
    glutTimerFunc(0, timer, 0);
    initGL();
    glutMainLoop();

}
