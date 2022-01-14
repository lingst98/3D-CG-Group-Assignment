#include <windows.h>
#include <stdlib.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>
#include <math.h>
#define PI 3.1415927
GLfloat x = 0.0; GLfloat y = 0.0; GLfloat angle = 0.0; GLfloat angle_size = 0.1;
int SCREEN_WIDTH = 1280;
int SCREEN_HEIGHT = 720;
#define FPS 60
GLfloat t_y = 0.0f;
GLfloat c_y = 0.0f;
GLfloat c1_x = 0.0f;
GLfloat c2_x = 0.0f;
float ball_x_direction = -3.0f;
float ball_y_direction = -3.0f;
float cloud1_x_direction = -1.4f;
float cloud2_x_direction = 1.4f;
float cloud3_x_direction = -2.0f;

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void k_background(void) {
    glColor3f(0.2, 0.7, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(-7.0f, 7.0f, -1.0f);
    glVertex3f(-7.0f, -0.5f, -1.0f);
    glVertex3f(7.0f, -0.5f, -1.0f);
    glVertex3f(7.0f, 7.0f, -1.0f);
    glEnd();

    glColor3f(0.3, 0.8, 0.3);
    glBegin(GL_QUADS);
    glVertex3f(-7.0f, -0.5f, -1.0f);
    glVertex3f(-7.0f, -7.0f, -1.0f);
    glVertex3f(7.0f, -7.0f, -1.0f);
    glVertex3f(7.0f, -0.5f, -1.0f);
    glEnd();

    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
    glVertex3f(-1.5f, -0.5f, -1.0f);
    glVertex3f(-9.5f, -6.0f, -1.0f);
    glVertex3f(7.0f, -6.0f, -1.0f);
    glVertex3f(-0.9f, -0.5f, -1.0f);
    glEnd();
}

void k_tree(void) {
    //1
    glLoadIdentity();
    glTranslatef(-3.7, -0.2f, -6.0f);

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.1f);
    //Front
    glVertex3f(0.0f, 0.4f, 0.0f);
    glVertex3f(-0.4f, -0.4f, 0.4f);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.4f, -0.4f, 0.4f);

    // Right
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.4f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.4f, -0.4f, 0.4f);
    glVertex3f(0.4f, -0.4f, -0.4f);

    // Back
    glVertex3f(0.0f, 0.4f, 0.0f);
    glVertex3f(0.4f, -0.4f, -0.4f);
    glVertex3f(-0.4f, -0.4f, -0.4f);

    // Left
    glVertex3f(0.0f, 0.4f, 0.0f);
    glVertex3f(-0.4f, -0.4f, -0.4f);
    glVertex3f(-0.4f, -0.4f, 0.4f);
    glEnd();

    glLoadIdentity();
    glTranslatef(-3.7f, 0.1f, -6.0f);

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f);
    //Front
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(-0.3f, -0.3f, 0.3f);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.3f, -0.3f, 0.3f);

    // Right
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.3f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.3f, -0.3f, 0.3f);
    glVertex3f(0.3f, -0.3f, -0.3f);

    // Back
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(0.3f, -0.3f, -0.3f);
    glVertex3f(-0.3f, -0.3f, -0.3f);

    // Left
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(-0.3f, -0.3f, -0.3f);
    glVertex3f(-0.3f, -0.3f, 0.3f);
    glEnd();

    glLoadIdentity();
    glTranslatef(-3.7f, -0.5f, -6.0f);
    glRotatef(90, 1.0, 0.0, 0.0);

    glColor3f(1.0, 0.3, 0.2);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while (angle < 2 * PI)
    {
        x = 0.07 * cos(angle);
        y = 0.07 * sin(angle);
        glVertex3f(x, y, 0.5);
        glVertex3f(x, y, 0.0);
        angle += angle_size;
    }
    glVertex3f(0.07, 0.0, 0.5);
    glVertex3f(0.07, 0.0, 0.0);
    glEnd();

    //2
    glLoadIdentity();
    glTranslatef(-1.5, 1.0f, -6.0f);
    glRotatef(15, 1.0, -1.0, 0.0);

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.1f);
    //Front
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(-0.3f, -0.3f, 0.3f);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.3f, -0.3f, 0.3f);

    // Right
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.3f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.3f, -0.3f, 0.3f);
    glVertex3f(0.3f, -0.3f, -0.3f);

    // Back
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(0.3f, -0.3f, -0.3f);
    glVertex3f(-0.3f, -0.3f, -0.3f);

    // Left
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(-0.3f, -0.3f, -0.3f);
    glVertex3f(-0.3f, -0.3f, 0.3f);
    glEnd();

    glLoadIdentity();
    glTranslatef(-1.5f, 1.2f, -6.0f);
    glRotatef(15, 1.0, -1.0, 0.0);

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f);
    //Front
    glVertex3f(0.0f, 0.2f, 0.0f);
    glVertex3f(-0.2f, -0.2f, 0.2f);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.2f, -0.2f, 0.2f);

    // Right
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.2f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.2f, -0.2f, 0.2f);
    glVertex3f(0.2f, -0.2f, -0.2f);

    // Back
    glVertex3f(0.0f, 0.2f, 0.0f);
    glVertex3f(0.2f, -0.2f, -0.2f);
    glVertex3f(-0.2f, -0.2f, -0.2f);

    // Left
    glVertex3f(0.0f, 0.2f, 0.0f);
    glVertex3f(-0.2f, -0.2f, -0.2f);
    glVertex3f(-0.2f, -0.2f, 0.2f);
    glEnd();

    glLoadIdentity();
    glTranslatef(-1.5f, 0.8f, -6.0f);
    glRotatef(90, 1.0, 0.0, 0.0);

    glColor3f(1.0, 0.3, 0.2);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while (angle < 2 * PI)
    {
        x = 0.05 * cos(angle);
        y = 0.05 * sin(angle);
        glVertex3f(x, y, 0.3);
        glVertex3f(x, y, 0.0);
        angle += angle_size;
    }
    glVertex3f(0.05, 0.0, 0.3);
    glVertex3f(0.05, 0.0, 0.0);
    glEnd();

    //3
    glLoadIdentity();
    glTranslatef(3.65, -0.2f, -6.0f);
    glRotatef(55, 0.0, -1.0, 0.0);

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.1f);
    //Front
    glVertex3f(0.0f, 0.4f, 0.0f);
    glVertex3f(-0.4f, -0.4f, 0.4f);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.4f, -0.4f, 0.4f);

    // Right
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.4f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.4f, -0.4f, 0.4f);
    glVertex3f(0.4f, -0.4f, -0.4f);

    // Back
    glVertex3f(0.0f, 0.4f, 0.0f);
    glVertex3f(0.4f, -0.4f, -0.4f);
    glVertex3f(-0.4f, -0.4f, -0.4f);

    // Left
    glVertex3f(0.0f, 0.4f, 0.0f);
    glVertex3f(-0.4f, -0.4f, -0.4f);
    glVertex3f(-0.4f, -0.4f, 0.4f);
    glEnd();

    glLoadIdentity();
    glTranslatef(3.65f, 0.1f, -6.0f);
    glRotatef(55, 0.0, -1.0, 0.0);

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f);
    //Front
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(-0.3f, -0.3f, 0.3f);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.3f, -0.3f, 0.3f);

    // Right
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.3f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.3f, -0.3f, 0.3f);
    glVertex3f(0.3f, -0.3f, -0.3f);

    // Back
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(0.3f, -0.3f, -0.3f);
    glVertex3f(-0.3f, -0.3f, -0.3f);

    // Left
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(-0.3f, -0.3f, -0.3f);
    glVertex3f(-0.3f, -0.3f, 0.3f);
    glEnd();

    glLoadIdentity();
    glTranslatef(3.65f, -0.5f, -6.0f);
    glRotatef(90, 1.0, 0.0, 0.0);

    glColor3f(1.0, 0.3, 0.2);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while (angle < 2 * PI)
    {
        x = 0.07 * cos(angle);
        y = 0.07 * sin(angle);
        glVertex3f(x, y, 0.5);
        glVertex3f(x, y, 0.0);
        angle += angle_size;
    }
    glVertex3f(0.07, 0.0, 0.5);
    glVertex3f(0.07, 0.0, 0.0);
    glEnd();

    //4
    glLoadIdentity();
    glTranslatef(1.5f, 1.0f, -6.0f);
    glRotatef(45, 0.2, -1.0, -0.05);

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.1f);
    //Front
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(-0.3f, -0.3f, 0.3f);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.3f, -0.3f, 0.3f);

    // Right
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.3f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.3f, -0.3f, 0.3f);
    glVertex3f(0.3f, -0.3f, -0.3f);

    // Back
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(0.3f, -0.3f, -0.3f);
    glVertex3f(-0.3f, -0.3f, -0.3f);

    // Left
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(-0.3f, -0.3f, -0.3f);
    glVertex3f(-0.3f, -0.3f, 0.3f);
    glEnd();

    glLoadIdentity();
    glTranslatef(1.5f, 1.2f, -6.0f);
    glRotatef(45, 0.2, -1.0, -0.05);

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f);
    //Front
    glVertex3f(0.0f, 0.2f, 0.0f);
    glVertex3f(-0.2f, -0.2f, 0.2f);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.2f, -0.2f, 0.2f);

    // Right
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.2f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.2f, -0.2f, 0.2f);
    glVertex3f(0.2f, -0.2f, -0.2f);

    // Back
    glVertex3f(0.0f, 0.2f, 0.0f);
    glVertex3f(0.2f, -0.2f, -0.2f);
    glVertex3f(-0.2f, -0.2f, -0.2f);

    // Left
    glVertex3f(0.0f, 0.2f, 0.0f);
    glVertex3f(-0.2f, -0.2f, -0.2f);
    glVertex3f(-0.2f, -0.2f, 0.2f);
    glEnd();

    glLoadIdentity();
    glTranslatef(1.5f, 0.8f, -6.0f);
    glRotatef(90, 1.0, 0.0, 0.0);

    glColor3f(1.0, 0.3, 0.2);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while (angle < 2 * PI)
    {
        x = 0.05 * cos(angle);
        y = 0.05 * sin(angle);
        glVertex3f(x, y, 0.3);
        glVertex3f(x, y, 0.0);
        angle += angle_size;
    }
    glVertex3f(0.05, 0.0, 0.3);
    glVertex3f(0.05, 0.0, 0.0);
    glEnd();
}

void k_streetlamp(void) {
    //1
    glLoadIdentity();
    glTranslatef(-2.5f, 0.7f, -6.0f);
    glRotatef(90, 1.0, 0.0, 0.0);

    glColor3f(0.8, 0.2, 0.2);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while (angle < 2 * PI)
    {
        x = 0.04 * cos(angle);
        y = 0.04 * sin(angle);
        glVertex3f(x, y, 0.9);
        glVertex3f(x, y, 0.0);
        angle += angle_size;
    }
    glVertex3f(0.04, 0.0, 0.9);
    glVertex3f(0.04, 0.0, 0.0);
    glEnd();

    glLoadIdentity();
    glTranslatef(-2.5f, 0.7f, -6.0f);
    glRotatef(190, 1.0, 0.0, 0.0);

    glColor3f(0.8, 0.2, 0.2);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while (angle < 2 * PI)
    {
        x = 0.04 * cos(angle);
        y = 0.04 * sin(angle);
        glVertex3f(x, y, 0.8);
        glVertex3f(x, y, 0.0);
        angle += angle_size;
    }
    glVertex3f(0.04, 0.0, 0.8);
    glVertex3f(0.04, 0.0, 0.0);
    glEnd();

    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat ball1[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, ball1);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glColor3f(1.0, 0.9, 0.4);
    glTranslatef(-2.2f, 0.62f, -6.0f);
    glutSolidSphere(0.08, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    //2
    glLoadIdentity();
    glTranslatef(-0.73f, 1.4f, -6.0f);
    glRotatef(90, 1.0, 0.0, 0.0);

    glColor3f(0.8, 0.2, 0.2);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while (angle < 2 * PI)
    {
        x = 0.03 * cos(angle);
        y = 0.03 * sin(angle);
        glVertex3f(x, y, 0.4);
        glVertex3f(x, y, 0.0);
        angle += angle_size;
    }
    glVertex3f(0.03, 0.0, 0.4);
    glVertex3f(0.03, 0.0, 0.0);
    glEnd();

    glLoadIdentity();
    glTranslatef(-0.73f, 1.4f, -6.0f);
    glRotatef(65, 0.0, 1.0, 0.0);

    glColor3f(0.8, 0.2, 0.2);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while (angle < 2 * PI)
    {
        x = 0.03 * cos(angle);
        y = 0.03 * sin(angle);
        glVertex3f(x, y, 0.25);
        glVertex3f(x, y, 0.0);
        angle += angle_size;
    }
    glVertex3f(0.03, 0.0, 0.25);
    glVertex3f(0.03, 0.0, 0.0);
    glEnd();

    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat ball2[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, ball2);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glColor3f(1.0, 0.9, 0.4);
    glTranslatef(-0.5f, 1.33f, -6.0f);
    glutSolidSphere(0.06, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    //3
    glLoadIdentity();
    glTranslatef(2.45f, 0.7f, -6.0f);
    glRotatef(90, 1.0, 0.0, 0.0);

    glColor3f(0.8, 0.2, 0.2);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while (angle < 2 * PI)
    {
        x = 0.04 * cos(angle);
        y = 0.04 * sin(angle);
        glVertex3f(x, y, 0.9);
        glVertex3f(x, y, 0.0);
        angle += angle_size;
    }
    glVertex3f(0.04, 0.0, 0.9);
    glVertex3f(0.04, 0.0, 0.0);
    glEnd();

    glLoadIdentity();
    glTranslatef(2.45f, 0.7f, -6.0f);
    glRotatef(190, 1.0, 0.0, 0.0);

    glColor3f(0.8, 0.2, 0.2);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while (angle < 2 * PI)
    {
        x = 0.04 * cos(angle);
        y = 0.04 * sin(angle);
        glVertex3f(x, y, 0.8);
        glVertex3f(x, y, 0.0);
        angle += angle_size;
    }
    glVertex3f(0.04, 0.0, 0.8);
    glVertex3f(0.04, 0.0, 0.0);
    glEnd();

    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat ball3[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, ball3);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glColor3f(1.0, 0.9, 0.4);
    glTranslatef(2.15f, 0.62f, -6.0f);
    glutSolidSphere(0.08, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    //4
    glLoadIdentity();
    glTranslatef(0.75f, 1.4f, -6.0f);
    glRotatef(90, 1.0, 0.0, 0.0);

    glColor3f(0.8, 0.2, 0.2);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while (angle < 2 * PI)
    {
        x = 0.03 * cos(angle);
        y = 0.03 * sin(angle);
        glVertex3f(x, y, 0.4);
        glVertex3f(x, y, 0.0);
        angle += angle_size;
    }
    glVertex3f(0.03, 0.0, 0.4);
    glVertex3f(0.03, 0.0, 0.0);
    glEnd();

    glLoadIdentity();
    glTranslatef(0.52f, 1.43f, -6.0f);
    glRotatef(110, 0.0, 1.0, 0.0);

    glColor3f(0.8, 0.2, 0.2);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while (angle < 2 * PI)
    {
        x = 0.03 * cos(angle);
        y = 0.03 * sin(angle);
        glVertex3f(x, y, 0.25);
        glVertex3f(x, y, 0.0);
        angle += angle_size;
    }
    glVertex3f(0.03, 0.0, 0.25);
    glVertex3f(0.03, 0.0, 0.0);
    glEnd();

    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat ball4[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, ball4);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glColor3f(1.0, 0.9, 0.4);
    glTranslatef(0.52f, 1.33f, -6.0f);
    glutSolidSphere(0.06, 100, 100);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

void kelefei(void) {
    glPushMatrix();
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat head[] = { -2.0, 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, head);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(0.0f, 1.6f + (-t_y), -6.0f);
    glColor3f(1.0f, 1.0f, 0.8f);
    glutSolidSphere(0.2, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glPopMatrix();

    //eye
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-0.07f, 1.37f + (-c_y), -5.0f);
    glColor3f(0.0, 0.0, 0.0);
    glutSolidSphere(0.03, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glLoadIdentity();
    glTranslatef(0.07f, 1.37f + (-c_y), -5.0f);
    glColor3f(0.0, 0.0, 0.0);
    glutSolidSphere(0.03, 100, 100);
    glPopMatrix();
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    //mouth
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(0.00f, 1.30f + (-c_y), -5.0f);
    glColor3f(1.0, 0.7, 0.3);
    glutSolidSphere(0.03, 100, 100);
    glPopMatrix();

    //Body
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(0.0f, 1.22f + (-t_y), -6.0f);
    //glRotatef(15, 1.0, 0.0, 0.0);
    glColor3f(1.0f, 0.4f, 0.4f);

    glBegin(GL_QUADS);
    // Top
    glVertex3f(0.2f, 0.2f, -0.2f);
    glVertex3f(-0.2f, 0.2f, -0.2f);
    glVertex3f(-0.2f, 0.2f, 0.2f);
    glVertex3f(0.2f, 0.2f, 0.2f);

    // Bottom
    glVertex3f(0.2f, -0.2f, 0.2f);
    glVertex3f(-0.2f, -0.2f, 0.2f);
    glVertex3f(-0.2f, -0.2f, -0.2f);
    glVertex3f(0.2f, -0.2f, -0.2f);

    // Front
    glVertex3f(0.2f, 0.2f, 0.2f);
    glVertex3f(-0.2f, 0.2f, 0.2f);
    glVertex3f(-0.2f, -0.2f, 0.2f);
    glVertex3f(0.2f, -0.2f, 0.2f);

    // Back
    glVertex3f(0.2f, -0.2f, -0.2f);
    glVertex3f(-0.2f, -0.2f, -0.2f);
    glVertex3f(-0.2f, 0.2f, -0.2f);
    glVertex3f(0.2f, 0.2f, -0.2f);

    // Left 
    glVertex3f(-0.2f, 0.2f, 0.2f);
    glVertex3f(-0.2f, 0.2f, -0.2f);
    glVertex3f(-0.2f, -0.2f, -0.2f);
    glVertex3f(-0.2f, -0.2f, 0.2f);

    // Right 
    glVertex3f(0.2f, 0.2f, -0.2f);
    glVertex3f(0.2f, 0.2f, 0.2f);
    glVertex3f(0.2f, -0.2f, 0.2f);
    glVertex3f(0.2f, -0.2f, -0.2f);
    glEnd();
    glPopMatrix();

    //Hand
    glLoadIdentity();
    glTranslatef(-0.25f, 1.3f + (-t_y), -6.0f);
    glRotatef(90, 1.0, 0.0, -1.0);
    glColor3f(1.0f, 1.0f, 0.8f);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while (angle < 2 * PI)
    {
        x = 0.06 * cos(angle);
        y = 0.06 * sin(angle);
        glVertex3f(x, y, 0.2);
        glVertex3f(x, y, 0.0);
        angle += angle_size;
    }
    glVertex3f(0.06, 0.0, 0.2);
    glVertex3f(0.06, 0.0, 0.0);
    glEnd();

    glLoadIdentity();
    glTranslatef(-0.36f, 1.13f + (-t_y), -6.0f);
    glutSolidSphere(0.06, 100, 100);

    glLoadIdentity();
    glTranslatef(-0.37f, 1.12f + (-t_y), -6.0f);
    glRotatef(90, 1.0, 0.0, -0.3);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while (angle < 2 * PI)
    {
        x = 0.06 * cos(angle);
        y = 0.06 * sin(angle);
        glVertex3f(x, y, 0.15);
        glVertex3f(x, y, 0.0);
        angle += angle_size;
    }
    glVertex3f(0.06, 0.0, 0.15);
    glVertex3f(0.06, 0.0, 0.0);
    glEnd();

    glEnable(GL_COLOR_MATERIAL);
    GLfloat lh[] = { 0.0, 1.0, 0.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lh);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLoadIdentity();
    glTranslatef(-0.43f, 0.92f + (-t_y), -6.0f);
    glutSolidSphere(0.06, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    glLoadIdentity();
    glTranslatef(0.26f, 1.3f + (-t_y), -6.0f);
    glRotatef(90, 1.0, 0.0, 0.3);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while (angle < 2 * PI)
    {
        x = 0.06 * cos(angle);
        y = 0.06 * sin(angle);
        glVertex3f(x, y, 0.2);
        glVertex3f(x, y, 0.0);
        angle += angle_size;
    }
    glVertex3f(0.06, 0.0, 0.2);
    glVertex3f(0.06, 0.0, 0.0);
    glEnd();

    glLoadIdentity();
    glTranslatef(0.32f, 1.1f + (-t_y), -6.0f);
    glutSolidSphere(0.06, 100, 100);

    glLoadIdentity();
    glTranslatef(0.33f, 1.1f + (-t_y), -6.0f);
    glRotatef(90, 1.0, 0.0, -0.3);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while (angle < 2 * PI)
    {
        x = 0.06 * cos(angle);
        y = 0.06 * sin(angle);
        glVertex3f(x, y, 0.15);
        glVertex3f(x, y, 0.0);
        angle += angle_size;
    }
    glVertex3f(0.06, 0.0, 0.15);
    glVertex3f(0.06, 0.0, 0.0);
    glEnd();

    glEnable(GL_COLOR_MATERIAL);
    GLfloat rh[] = { 0.0, 1.0, 0.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, rh);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLoadIdentity();
    glTranslatef(0.28f, 0.9f + (-t_y), -6.0f);
    glutSolidSphere(0.06, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    //Leg
    glLoadIdentity();
    glTranslatef(-0.1f, 1.0f + (-t_y), -6.0f);
    glRotatef(90, 1.0, 0.0, 0.0);
    glColor3f(0.5, 0.8, 1.0);

    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while (angle < 2 * PI)
    {
        x = 0.06 * cos(angle);
        y = 0.06 * sin(angle);
        glVertex3f(x, y, 0.5);
        glVertex3f(x, y, 0.0);
        angle += angle_size;
    }
    glVertex3f(0.06, 0.0, 0.5);
    glVertex3f(0.06, 0.0, 0.0);
    glEnd();

    glLoadIdentity();
    glTranslatef(0.1f, 1.0f + (-t_y), -6.0f);
    glRotatef(90, 1.0, 0.0, 0.0);

    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while (angle < 2 * PI)
    {
        x = 0.06 * cos(angle);
        y = 0.06 * sin(angle);
        glVertex3f(x, y, 0.5);
        glVertex3f(x, y, 0.0);
        angle += angle_size;
    }
    glVertex3f(0.06, 0.0, 0.5);
    glVertex3f(0.06, 0.0, 0.0);
    glEnd();

    //pillar
    glLoadIdentity();
    glTranslatef(-3.8f, 1.38, -6.0f);
    glColor3f(1.0, 0.9, 0.3);
    glRotatef(90, 1.0, 0.0, 0.0);

    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while (angle < 2 * PI)
    {
        x = 0.03 * cos(angle);
        y = 0.03 * sin(angle);
        glVertex3f(x, y, 0.8);
        glVertex3f(x, y, 0.0);
        angle += angle_size;
    }
    glVertex3f(0.03, 0.0, 0.8);
    glVertex3f(0.03, 0.0, 0.0);
    glEnd();

    glLoadIdentity();
    glTranslatef(-3.65f, 1.37, -6.0f);
    glColor3f(1.0, 0.9, 0.3);
    glRotatef(90, 1.0, 0.0, 0.0);

    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while (angle < 2 * PI)
    {
        x = 0.03 * cos(angle);
        y = 0.03 * sin(angle);
        glVertex3f(x, y, 0.6);
        glVertex3f(x, y, 0.0);
        angle += angle_size;
    }
    glVertex3f(0.03, 0.0, 0.6);
    glVertex3f(0.03, 0.0, 0.0);
    glEnd();

    glLoadIdentity();
    glTranslatef(-3.0f, 1.37, -6.0f);
    glColor3f(1.0, 0.9, 0.3);
    glRotatef(90, 1.0, 0.0, 0.0);

    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while (angle < 2 * PI)
    {
        x = 0.03 * cos(angle);
        y = 0.03 * sin(angle);
        glVertex3f(x, y, 0.6);
        glVertex3f(x, y, 0.0);
        angle += angle_size;
    }
    glVertex3f(0.03, 0.0, 0.6);
    glVertex3f(0.03, 0.0, 0.0);
    glEnd();

    glLoadIdentity();
    glTranslatef(-2.85f, 1.38, -6.0f);
    glColor3f(1.0, 0.9, 0.3);
    glRotatef(90, 1.0, 0.0, 0.0);

    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while (angle < 2 * PI)
    {
        x = 0.035 * cos(angle);
        y = 0.035 * sin(angle);
        glVertex3f(x, y, 0.8);
        glVertex3f(x, y, 0.0);
        angle += angle_size;
    }
    glVertex3f(0.035, 0.0, 0.8);
    glVertex3f(0.035, 0.0, 0.0);
    glEnd();

    //Ball
    glPushMatrix();
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat ball[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, ball);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glColor3f(1.0, 0.8, 0.0);
    glTranslatef(-0.26f, 0.9f + (-t_y), -6.0f);
    glutSolidSphere(0.1, 10, 10);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glPopMatrix();

    glLoadIdentity();
    glTranslatef(1.2f, 2.0f, -6.0f);
}

void s4_basketball(float ball_x_direction, float ball_y_direction)
{
    //Center sphere
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat ball[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, ball);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(ball_x_direction, ball_y_direction, -6.0f);
    glColor3f(1.0, 0.5, 0.0);
    glutSolidSphere(0.2, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

void k_house() {
    glPushMatrix();
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat ball[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, ball);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(-3.3f, 1.35f, -6.0f);
    glRotatef(82, -1.0, 0.0, 0.0);
    glColor3f(1.0, 0.0, 0.0);
    glutSolidCone(0.6, 0.4, 20, 20);

    glLoadIdentity();
    glTranslatef(-3.32f, 0.80f, -6.0f);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidSphere(0.2, 100, 100);

    glLoadIdentity();
    glTranslatef(-3.32f, 1.05f, -6.0f);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidSphere(0.1, 100, 100);

    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glPopMatrix();

    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-2.8f, 0.9f, -5.0f);
    glColor3f(0.0, 0.0, 0.0);
    glutSolidSphere(0.015, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-2.74f, 0.9f, -5.0f);
    glColor3f(0.0, 0.0, 0.0);
    glutSolidSphere(0.015, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-2.765f, 0.85f, -5.0f);
    glColor3f(1.0, 0, 0);
    glutSolidSphere(0.015, 100, 100);
    glPopMatrix();
}

void k_cloud() {
    //cloud 1
    glPushMatrix();
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat ball[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, ball);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(-2.0f + c1_x, 2.0f, -6.0f);
    glColor3f(0, 0, 1);
    glutSolidSphere(0.2, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-1.8f + c1_x, 2.0f, -6.0f);
    glColor3f(0, 0, 1);
    glutSolidSphere(0.15, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-2.2f + c1_x, 2.0f, -6.0f);
    glColor3f(0, 0, 1);
    glutSolidSphere(0.15, 100, 100);
    glPopMatrix();

    //cloud 2
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(3.0f + c2_x, 2.0f, -6.0f);
    glColor3f(0, 0, 1);
    glutSolidSphere(0.2, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glLoadIdentity();
    glTranslatef(2.8f + c2_x, 2.0f, -6.0f);
    glColor3f(0, 0, 1);
    glutSolidSphere(0.15, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glLoadIdentity();
    glTranslatef(3.2f + c2_x, 2.0f, -6.0f);
    glColor3f(0, 0, 1);
    glutSolidSphere(0.15, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glPopMatrix();
}

void s4_combinedCloud()
{
    //Center sphere
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat ball[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, ball);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(cloud1_x_direction, 1.0f, -6.0f);
    glColor3f(0, 0, 1);
    glutSolidSphere(0.2, 100, 100);

    //Right Sphere
    glLoadIdentity();
    glTranslatef(cloud1_x_direction + 0.2f, 1.0f, -6.0f);
    glColor3f(0, 0, 1);
    glutSolidSphere(0.15, 100, 100);

    //Left Sphere
    glLoadIdentity();
    glTranslatef(cloud1_x_direction - 0.2f, 1.0f, -6.0f);
    glColor3f(0, 0, 1);
    glutSolidSphere(0.15, 100, 100);

    //Center sphere
    glLoadIdentity();
    glTranslatef(cloud2_x_direction, 2.0f, -6.0f);
    glColor3f(0, 0, 1);
    glutSolidSphere(0.2, 100, 100);

    //Right Sphere
    glLoadIdentity();
    glTranslatef(cloud2_x_direction - 0.2f, 2.0f, -6.0f);
    glColor3f(0, 0, 1);
    glutSolidSphere(0.15, 100, 100);

    //Left Sphere
    glLoadIdentity();
    glTranslatef(cloud2_x_direction + 0.2f, 2.0f, -6.0f);
    glColor3f(0, 0, 1);
    glutSolidSphere(0.15, 100, 100);

    //Center sphere
    glLoadIdentity();
    glTranslatef(cloud3_x_direction, 0.0f, -6.0f);
    glColor3f(0, 0, 1);
    glutSolidSphere(0.2, 100, 100);

    //Right Sphere
    glLoadIdentity();
    glTranslatef(cloud3_x_direction - 0.2f, 0.0f, -6.0f);
    glColor3f(0, 0, 1);
    glutSolidSphere(0.15, 100, 100);

    //Left Sphere
    glLoadIdentity();
    glTranslatef(cloud3_x_direction + 0.2f, 0.0f, -6.0f);
    glColor3f(0, 0, 1);
    glutSolidSphere(0.15, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

void k_display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    k_tree();
    k_streetlamp();
    kelefei();
    k_house();
    k_background();
    k_cloud();
    glFlush();
    glutSwapBuffers();
}

void s4_display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    s4_basketball(ball_x_direction, ball_y_direction);
    s4_combinedCloud();
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

void s2_animation(int) {
    glutTimerFunc(0, s2_animation, 0);
    DWORD start = GetTickCount();
    while (GetTickCount() - start < 1000 / FPS);
    t_y += 0.02;
    c_y += 0.017;

    c1_x += 0.02;
    c2_x += 0.02;

    if (c2_x > 2.0)
    {
        c2_x = -7.0;
    }

    glutPostRedisplay();
}

void s4_animation(int)
{
    glutTimerFunc(0, s4_animation, 1);
    DWORD start = GetTickCount();
    while (GetTickCount() - start < 1000 / FPS);

    //Cloud Animation
    cloud1_x_direction += 0.01;
    cloud2_x_direction += 0.03;
    cloud3_x_direction += 0.025;
    if (cloud2_x_direction > 3.0 && cloud1_x_direction > 3.0 && cloud3_x_direction > 3.0)
    {
        cloud2_x_direction = -4.0;
        cloud1_x_direction = -5.4;
        cloud3_x_direction = -3.0;
    }

    //Basketball Animation
    if (ball_y_direction >= -3.0 && ball_y_direction < 0.9)
    {
        ball_x_direction += 0.03;
        ball_y_direction += 0.05;
    }
    //After hit the first cloud, fall down
    else if (ball_x_direction < 0.01 && ball_y_direction >= 1.0)
    {
        ball_x_direction += 0.02;
        ball_y_direction -= 0.4;
    }
    //Bounce back
    else if (ball_x_direction > 0.03 && ball_y_direction > 1.0)
    {
        ball_x_direction += 0.03;
        ball_y_direction += 0.05;
    }

    glutPostRedisplay();
}

void switchDisplay(int value) {
    if (value == 1)
    {
        glutDisplayFunc(s4_display);
        glutIdleFunc(s4_display);
        glutTimerFunc(0, s4_animation, 1);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("3D project");
    glutDisplayFunc(k_display);
    glutReshapeFunc(k_reshape);
    glutTimerFunc(0,s2_animation,0);
    glutTimerFunc(8500,switchDisplay,1);
    initGL();
    glutMainLoop();
}