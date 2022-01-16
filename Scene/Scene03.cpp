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

float ballX = -0.4;
float ballY = -0.2;
int state = 1;

void rectangle()
{
    glBegin(GL_QUADS);
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(-4.0, 1.0, 0.0);
    glVertex3f(-4.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glEnd();
}

void initGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void court()
{
    glLoadIdentity();
    glBegin(GL_QUADS);
    glColor3ub(194, 197, 204);
    glVertex3f(-4.0, -1.5, -2.0);
    glVertex3f(-4.0, -1.5, -10.0);
    glVertex3f(6.0, -1.5, -10.0);
    glVertex3f(6.0, -1.5, -2.0);


    /*glColor3ub(200, 0, 0);
    glVertex3f(-3.5, -1.4, -2.5);
    glVertex3f(-3.5, -1.4, -9.5);*/

    //glEnd();

    //court line start
    glColor3ub(200, 0, 0);
    glVertex3f(-3.5, -1.45, -2.5);
    glVertex3f(-3.5, -1.45, -9.0);
    glVertex3f(-3.4, -1.45, -9.0);
    glVertex3f(-3.4, -1.45, -2.5);

    glColor3ub(200, 0, 0);
    glVertex3f(-3.5, -1.45, -9.0);
    glVertex3f(5.5, -1.45, -9.0);
    glVertex3f(5.5, -1.45, -8.9);
    glVertex3f(-3.5, -1.45, -8.9);

    glColor3ub(200, 0, 0);
    glVertex3f(5.4, -1.45, -9.0);
    glVertex3f(5.5, -1.45, -9.0);
    glVertex3f(5.5, -1.45, -2.5);
    glVertex3f(5.4, -1.45, -2.5);
    //court line end

    //Background
    glColor3ub(0, 200, 0);
    glVertex3f(-10, -1, -11.9);
    glVertex3f(10, -1, -11.9);
    glVertex3f(10, -6, -11.9);
    glVertex3f(-10, -6, -11.9);

    glColor3ub(25, 189, 255);
    glVertex3f(-10, 10, -12);
    glVertex3f(10, 10, -12);
    glVertex3f(10, -10, -12);
    glVertex3f(-10, -10, -12);
    glEnd();
}

void basketball()
{
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat basketball[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, basketball);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(ballX, ballY, -5.0);
    glColor3ub(255, 126, 0);
    glutSolidSphere(0.12, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

void bBoard()
{
    glLoadIdentity();                 // Reset the model-view matrix
    glTranslatef(2.5f, 0.5f, -8.0f);  // Move right and into the screen

    glBegin(GL_QUADS);
    //Net Frame (Left Face Side)
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(-0.6, 1.6, -0.5); //Left top corner
    glVertex3f(0.0, 1.4, -0.2); //Right top corner
    glVertex3f(0.0, 0.9, -0.2); //Right down corner
    glVertex3f(-0.6, 1.05, -0.4); //Left down corner

    //Pillar
    // Right face (z = 0.5f)
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.2, 0.8, -0.5); //Left Top corner
    glVertex3f(0.6, 0.8, 0.5); //Right Top corner
    glVertex3f(0.6, -1.9, 0.5); //Right down corner
    glVertex3f(0.2, -2.0, 0.5); //Left down corner

    // Left face (z = 0.5f)
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.2, 0.8, -0.5); //Left top corner
    glVertex3f(0.2, 0.8, 0.5); //Right top corner
    glVertex3f(0.2, -2.0, 0.5); //Right down corner
    glVertex3f(0.2, -2.0, -0.5); //Left down corner

    //board
    //Top face
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.25, 1.85, 0.5); //Left top corner
    glVertex3f(1.25, 1.55, 0.5); //Right top corner
    glVertex3f(0.50, 1.6, -0.8); //Right down corner
    glVertex3f(-1.0, 1.85, -0.8); //Left down corner

    // Left face (x = 0.2f)
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-1.0, 1.8, -0.6); //Left top corner
    glVertex3f(0.4, 1.55, -0.5); //Right top corner
    glVertex3f(0.4, 0.75, -0.5); //Right down corner
    glVertex3f(-1.0, 1.1, -0.6); //Left down corner

    // Right face 
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.45, 1.60, -0.7); //Left top corner
    glVertex3f(1.15, 1.50, 0.7); //Right top corner
    glVertex3f(1.15, 0.90, 0.7); //Right down corner
    glVertex3f(0.45, 0.75, -0.6); //Left down corner    

    glEnd();  // End of drawing color-cube

    //Basketball frame
    glBegin(GL_LINES);
    //Right line
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.5, 0.45, 0.0);
    glVertex3f(-0.5, 0.6, 1.5);

    //Left line
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-1.15, 0.6, 0.0);
    glVertex3f(-1.25, 0.5, 2.5);

    //Bottom line
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-1.15, 0.60, 0.0); //Left vertex
    glVertex3f(-0.5, 0.45, 0.0); //Right vertex

    glEnd(); //End of drawing lines
}


void displayScene1()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    basketball();
    bBoard();
    court();

    glFlush();
    glutSwapBuffers();
}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000 / 30, timer, 4);

    if (ballY < 1.0)
    {
        ballX += 0.15;
        ballY += 0.1;
    }
    if (ballY >= 1.0)
    {
        ballX -= 0.15;
        ballY += 0.1;
    }

    glutPostRedisplay();
}


void k_reshape(GLsizei SCREEN_WIDTH, GLsizei SCREEN_HEIGHT) {
    if (SCREEN_HEIGHT == 0) SCREEN_HEIGHT = 1;
    GLfloat aspect = (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT;

    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0f, aspect, 0.1f, 20.0f);
}


int  main(int argc, char** argv)
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInit(&argc, argv);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutCreateWindow("test");
    glutDisplayFunc(displayScene1);
    glutReshapeFunc(k_reshape);
    glutTimerFunc(0, timer, 0);
    initGL();
    glutMainLoop();
}
