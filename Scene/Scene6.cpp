#include <windows.h>
#include <stdlib.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>
#include <math.h>

#define PI 3.141592653

int SCREEN_WIDTH = 1280;
int SCREEN_HEIGHT = 720;
int state = 1;
#define FPS	30
GLUquadricObj* n = gluNewQuadric();

float angle = 0.0;
float cloud1_x_direction = -1.4f;
float cloud2_x_direction = 1.4f;
float cloud3_x_direction = -2.0f;
float ball_x_direction = 0.0f;
float ball_y_direction = -1.0f;

void lower_body()
{
	glLoadIdentity();
	glEnable(GL_COLOR_MATERIAL);
	glTranslatef(0.0, 0.6, -6.0);
	glRotatef(-90, 1.0, 0.0, 0.0);
	glColor3ub(0, 193, 255);
	gluCylinder(n, 0.8, 0.6, 1.5, 100, 100);
}

void left_leg()
{
	glLoadIdentity();
	glTranslatef(-0.55, 0.5, -6.0);
	glScaled(1.5, 1.0, 1.0);
	glColor3ub(229, 95, 56);
	glutSolidSphere(0.2, 100, 100);
}

void right_leg()
{
	glLoadIdentity();
	glTranslatef(0.55, 0.5, -6.0);
	glScaled(1.5, 1.0, 1.0);
	glColor3ub(229, 95, 56);
	glutSolidSphere(0.2, 100, 100);
}

void ball1()
{
	//Center Ball (Gold ball)
	glLoadIdentity();
	glTranslatef(0.0, ball_y_direction, -6.0f);
	glColor3ub(255, 220, 0);
	glutSolidSphere(0.2, 100, 100);
}

void ball2()
{
	//Left Ball (Blue ball)
	glLoadIdentity();
	glTranslatef(-1.0, ball_y_direction, -6.0f);
	glColor3ub(40, 25, 255);
	glutSolidSphere(0.2, 100, 100);
}

void ball3()
{
	//Right Ball (Original ball)
	glLoadIdentity();
	glTranslatef(1.0, ball_y_direction, -6.0f);
	glColor3ub(255, 100, 0);
	glutSolidSphere(0.2, 100, 100);
}

void display()
{
	//This is the place that all the things get place
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Clear the screen and filled with glClearColor

	glPushMatrix(); //Push the current state of the matrix to save
	ball1();
	ball2();
	ball3();
	lower_body();
	left_leg();
	right_leg();
	glPopMatrix(); //Undo the matrix transformation
	gluLookAt(7.0, 7.0, 7.0, 0.0, 0.0, 0.0, 5.0, 1.0, 1.0); //Look at which direction
	glFlush(); //Send all the vertex into the screen
	glutSwapBuffers();
}



void idle()
{
	DWORD start = GetTickCount();
	while (GetTickCount() - start < 1000 / FPS);

	//Basketball Animation
	switch (state)
	{
	case 1:
		if (ball_y_direction < 0.2)
		{
			ball_y_direction += 0.1;
		}
		else
		{
			state = -1;
		}
		break;
	case -1:
		if (ball_y_direction > -1.0)
		{
			ball_y_direction -= 0.1;
		}
		else
		{
			state = 1;
		}
		break;
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
	gluPerspective(45.0, 1.0, 0.0001, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

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
