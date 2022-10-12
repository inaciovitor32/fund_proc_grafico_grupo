/*
 * -lab02-02cpp
 *<João Victor Martins Reis>, RA <11201810522>, data 11/10/2022
 *<Guilherme Braz de Lima>, RA <11201922157>, data 11/10/2022
 *<Vitor Inácio da Silva>, RA <11201810048>, data 11/10/2022
 *<Jeniffer Santos Campos>, RA <11201920325>, data 11/10/2022
 */

#include <GL/glut.h>
#include <math.h>

void drawFilledCircle()
{

    float x = 0.5;
    float y = 0.5;
    float radius = 0.32;

    float PI = 3.1415926f;

    int i;
    int triangleAmount = 200; //# of triangles used to draw circle

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.29, 1, 1);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
}

void drawCircle()
{

    float cx = 0.5;
    float cy = 0.5;
    float r = 0.5;
    int num_segments = 200;

    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    for (int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments); // get the current angle
        float x = r * cosf(theta);                                         // calculate the x component
        float y = r * sinf(theta);                                         // calculate the y component
        glVertex2f(x + cx, y + cy);                                        // output vertex
    }
    glEnd();
}

void drawTriangle()
{

    glBegin(GL_TRIANGLES);
    glColor3f(1, 0.6f, 0.8f);
    glVertex3f(0.25f, 0.3f, 0.f);
    glVertex3f(0.75f, 0.3f, 0.f);
    glVertex3f(0.25f, 0.7f, 0.f);
    glEnd();
}

void drawSquare()
{

    glBegin(GL_POLYGON);
    glColor3f(0, 0.5, 0);
    glVertex3f(0.18, 0.18, 0.0);
    glVertex3f(0.82, 0.18, 0.0);
    glVertex3f(0.82, 0.82, 0.0);
    glVertex3f(0.18, 0.82, 0.0);
    glEnd();
}

void drawline()
{

    float cx = 0.5;
    float cy = 0.5;
    float r = 0.5;
    int num_segments = 100;

    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex3f(0, 0.5, 0.0);
    glVertex3f(1, 0.5, 0.0);

    glVertex3f(0.5, 0, 0.0);
    glVertex3f(0.5, 1, 0.0);

    glEnd();
}

void drawHexagon()
{

    float x = 0.5;
    float y = 0.5;
    float radius = 0.5;

    float PI = 3.1415926f;

    int i;
    int triangleAmount = 6; //# of triangles used to draw circle
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1, 0, 0);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
}

void display(void)
{
    /* clear all pixels  */
    glClear(GL_COLOR_BUFFER_BIT);

    drawCircle();
    drawHexagon();
    drawSquare();
    drawFilledCircle();
    drawline();
    drawTriangle();

    glFlush();
}

void init(void)
{
    /* select clearing color 	*/
    glClearColor(1, 1, 1, 1);

    /* initialize viewing values  */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(110, 110);
    glutCreateWindow("lab02-2");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0; /* ANSI C requires main to return int. */
}
