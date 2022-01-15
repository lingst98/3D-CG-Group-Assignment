#include <windows.h>
#include <stdlib.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>
#include <math.h>

#define PI 3.141592653

int SCREEN_WIDTH = 1280;
int SCREEN_HEIGHT = 720;
#define FPS	30

float angle = 0.0;
float cloud1_x_direction = -1.4f;
float cloud2_x_direction = 1.4f;
float cloud3_x_direction = -2.0f;
float ball_x_direction = -3.0f;
float ball_y_direction = -3.0f;

void basketball(float ball_x_direction, float ball_y_direction)
{
	//Center sphere
	glLoadIdentity();
	glTranslatef(ball_x_direction, ball_y_direction, -6.0f);
	glColor3f(1.0, 0.5, 0.0);
	glutSolidSphere(0.2, 100, 100);
}

void combinedCloud()
{
	//Center sphere
	glLoadIdentity();
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
}

void display()
{
	//This is the place that all the things get place
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Clear the screen and filled with glClearColor
	
	glPushMatrix(); //Push the current state of the matrix to save
	combinedCloud();
	basketball(ball_x_direction, ball_y_direction);
	glPopMatrix(); //Undo the matrix transformation
	gluLookAt(7.0, 7.0, 7.0, 0.0, 0.0, 0.0, 5.0, 1.0, 1.0); //Look at which direction
	glFlush(); //Send all the vertex into the screen
	glutSwapBuffers();
}

void idle()
{
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
	else if (ball_x_direction < 0.01 && ball_y_direction >= 0.9)
	{
		ball_x_direction += 0.02;
		ball_y_direction -= 0.4;
	}
	//Bounce back
	else if (ball_x_direction > 0.03 && ball_y_direction >= 0.9)
	{
		ball_x_direction += 0.03;
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