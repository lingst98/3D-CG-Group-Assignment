#include <windows.h>
#include <stdlib.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>
#include <math.h>

#define SCREEN_WIDTH	1280
#define SCREEN_HEIGHT	720
#define FPS	30

float angle = 0.0;
float cloud1_x_direction = -1.4f;
float cloud2_x_direction = 1.4f;
float cloud3_x_direction = -2.0f;
float ball_x_direction = -3.0f;
float ball_y_direction = -3.0f;

void basketNetLine()
{
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.5, 0.0);
    glEnd();
}

void netLineFrame()
{
    glBegin(GL_LINES);
    glVertex3f(0.5, 0.0, 0.0);
    glVertex3f(0.0, 0.5, 0.0);
    glEnd();
}

void square()
{
    glBegin(GL_QUADS);
    glVertex3f(2.0, 2.0, 0.0);
    glVertex3f(0.0, 2.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(2.0, 0.0, 0.0);
    glEnd();
}

void squarenet()
{
    glBegin(GL_QUADS);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(1.0, 0.0, 0.0);
    glEnd();
}

void rectangle()
{
    glBegin(GL_QUADS);
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(-4.0, 1.0, 0.0);
    glVertex3f(-4.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glEnd();
}

//Basketball
void basketball(float ball_x_direction, float ball_y_direction)
{
    //Center sphere
    glLoadIdentity();
    glTranslatef(ball_x_direction, ball_y_direction, -6.0f);
    glColor3f(1.0, 0.5, 0.0);
    glutSolidSphere(0.2, 100, 100);
}

//Board
void board()
{
    glNormal3f(0, 0, 1);

    //Yellow Surface
    glPushMatrix();
    glColor3d(0.0, 1.0, 0.0);
    glTranslated(0.0, 0.0, 0.0);
    square();
    glPopMatrix();

    //Yellow Surface
    glPushMatrix();
    glColor3d(0.0, 1.0, 0.0);
    glRotated(90.0, 0.0, 1.0, 0.0);
    glTranslated(0.0, 0.0, 2.0);
    square();
    glPopMatrix();

    //White Surface
    glPushMatrix();
    glColor3d(1.0, 1.0, 1.0);
    glRotated(-270.0, 0.0, 1.0, 0.0);
    glTranslated(0.0, 0.0, 0.0);
    square();
    glPopMatrix();

    //Beige Surface
    glPushMatrix();
    glColor3d(0.0, 1.0, 0.5);
    glTranslated(0.0, 0.0, -2.0);
    square();
    glPopMatrix();

    //Purple Surface
    glPushMatrix();
    glColor3d(1.0, 0.0, 1.0);
    glRotated(90.0, 1.0, 0.0, 0.0);
    glTranslated(0.0, -2.0, -2.0);
    square();
    glPopMatrix();
}

//Pillar
void pillar()
{
    glNormal3f(0, 0, 1);

    //Yellow Surface
    glPushMatrix();
    glColor3d(0.0, 1.0, 0.0);
    glTranslated(0.0, 0.7, 0.0);
    rectangle();
    glPopMatrix();

    //Red Surface
    glPushMatrix();
    glColor3d(0.0, 1.0, 0.0);
    glRotated(90.0, 1.0, 0.0, 0.0);
    glTranslated(0.0, -1.0, -1.7);
    rectangle();
    glPopMatrix();
}

//Basket Net without Frame
void basket()
{
    //Line Net
    glPushMatrix();
    glColor3d(1.0, 1.0, 1.0);
    glTranslated(0.0, 3.0, 0.0);
    basketNetLine();
    glPopMatrix();
}

//Basket Net Frame
void net()
{
    //White Surface
    glPushMatrix();
    glColor3d(1.0, 1.0, 1.0);
    glRotated(90.0, 1.0, 0.0, 0.0);
    glTranslated(0.6, -1.3, -2.1);
    squarenet();
    glPopMatrix();

    //Line Net 1
    glPushMatrix();
    glColor3d(1.0, 1.0, 1.0);
    glTranslated(1.2, 3.0, 0.2);
    netLineFrame();
    glPopMatrix();

    //Line Net 2
    glPushMatrix();
    glColor3d(1.0, 1.0, 1.0);
    glTranslated(1.2, 3.0, 1.0);
    netLineFrame();
    glPopMatrix();

    //Line Net 3
    glPushMatrix();
    glColor3d(1.0, 1.0, 1.0);
    glRotated(90.0, 1.0, 1.0, 0.0);
    glTranslated(1.7, 4.0, -1.35);
    netLineFrame();
    glPopMatrix();
}

//FULL COMBINED
void basketball_board()
{
    pillar();
    board();
    net();
    //basket();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    basketball_board();
    basketball(ball_x_direction, ball_y_direction);
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

void idle()
{
    DWORD start = GetTickCount();
    while (GetTickCount() - start < 1000 / FPS);

    //Basketball Animation
    if (ball_y_direction >= -3.0 && ball_y_direction < 0.20)
    {
        ball_x_direction += 0.03;
        ball_y_direction += 0.05;
    }
    //After hit the first cloud, fall down
    else if (ball_x_direction < 0.01 && ball_y_direction >= 0.20)
    {
        ball_x_direction -= 0.03;
        ball_y_direction += 0.05;
    }

    glutPostRedisplay();
}

void initGL()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPointSize(1.0);
    glLineWidth(0.2);

    //Setting up a camera for 2-dimension
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //	glOrtho(-5, 5, -5, 5, 0.0001, 1000.0); //Setup the shape of camera -> Define the box shape || One of the box shape camera
    gluPerspective(45.0, 1.0, 0.0001, 1000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(7.0, 7.0, 7.0, 0.0, 0.0, 0.0, 5.0, 1.0, 1.0); //Look at which direction

    // lights
    glEnable(GL_COLOR_MATERIAL); //This is a global transformatiion 
    glEnable(GL_LIGHTING);
    GLfloat dir[] = { 1.0, 0.0, 1.0, 0.0 }; //1.0 means a directional of lighting, the direction of lighting is 3
    glLightfv(GL_LIGHT0, GL_POSITION, dir); //Reset the LIGHT0 with a new parameter
    glEnable(GL_LIGHT0); //Switch ON the LIGHT0

    // depth buffer
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char** argv)
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInit(&argc, argv);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT); //Setup the window size
    glutCreateWindow("Test"); //Setup the window with string as title
    glutDisplayFunc(display);
    glutIdleFunc(idle);

    initGL();
    glutMainLoop(); //Tell the glut I had finished initialisation and start compiling
}