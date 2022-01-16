#include <GL\glut.h>

GLfloat xRotated, yRotated, zRotated;
GLdouble radius = 0.5;
GLfloat qaBlack[] = { 0.0, 0.0, 0.0, 1.0 }; //Black Color
GLfloat qaOrange[] = { 1.0, 0.5, 0.0, 1.0 }; //Orange Color
GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 }; //White Color
GLfloat qaRed[] = { 1.0, 0.0, 0.0, 1.0 }; //White Color

    // Set lighting intensity and color
GLfloat qaAmbientLight[] = { 0.2, 0.2, 0.2, 1.0 };
GLfloat qaDiffuseLight[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat qaSpecularLight[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat emitLight[] = { 0.9, 0.9, 0.9, 0.01 };
GLfloat Noemit[] = { 0.0, 0.0, 0.0, 1.0 };
// Light source position
GLfloat qaLightPosition[] = { 0.5, 0, -3.5, 0.5 };

void display(void);
void reshape(int x, int y);

void idleFunc(void)
{

    zRotated += 0.05;
    yRotated += 0.05;

    display();
}
void initLighting()
{

    // Enable lighting
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    // Set lighting intensity and color
    glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);

    // Set the light position
    glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1080,720);
    glutCreateWindow("Basketball");
    initLighting();
    xRotated = yRotated = zRotated = 0.0;

    glutIdleFunc(idleFunc);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}

void Ball1(void)
{
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
    glScalef(1.0, 1.0, 1.0);
    glRotatef(zRotated, 0.0, 0.0, 1.0);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaOrange);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaOrange);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, qaWhite);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 20);
    glutSolidSphere(radius, 25, 25);

    glFlush();
    glutSwapBuffers();

}

void display(void) {
    Ball1();
}

void reshape(int x, int y) {
    //if (y == 0 || x == 0) return;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(39.0, (GLdouble)x / (GLdouble)y, 0.6, 21.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, x, y); 

}



