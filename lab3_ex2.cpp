/*
 * -lab03-02.cpp
 *<João Victor Martins Reis>, RA <11201810522>, data 11/10/2022
 *<Guilherme Braz de Lima>, RA <11201922157>, data 11/10/2022
 *<Vitor Inácio da Silva>, RA <11201810048>, data 11/10/2022
 *<Jeniffer Santos Campos>, RA <11201920325>, data 11/10/2022
 */



#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>

static GLfloat spin = 0.0;

void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-6.0, 6.0, -6.0, 6.0, -10.0, 10.0);
   glShadeModel (GL_FLAT);
   
}

void display(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glPushMatrix();
glRotatef(spin, 0.0, 0.0, 1.0);
glColor3f(1.0, 1.0, 1.0);

glBegin(GL_TRIANGLES);
   //0_Triangulo
   glVertex3f(-1.0f, 2.0f, 0);
   glVertex3f(1.0f, 2.0f, 0);
   glVertex3f(0.0f, 6.0f, 0);
glEnd();

glBegin(GL_TRIANGLES);
   //1_Triangulo
   glVertex3f(-2.0f, 1.0f, 0);
   glVertex3f(-2.0f, -1.0f, 0);
   glVertex3f(-6.0f, 0.0f, 0);
glEnd();

glBegin(GL_TRIANGLES);
   //2_Triangulo
   glVertex3f(-1.0f, -2.0f, 0);
   glVertex3f(1.0f, -2.0f, 0);
   glVertex3f(0.0f, -6.0f, 0);
glEnd();

glBegin(GL_TRIANGLES);
   //3_Triangulo
   glVertex3f(2.0f, 1.0f, 0);
   glVertex3f(2.0f, -1.0f, 0);
   glVertex3f(6.0f, 0.0f, 0);
glEnd();

glBegin(GL_TRIANGLES);
   //4_Triangulo
   glVertex3f(-1.0f, 2.0f, 0);
   glVertex3f(1.0f, 2.0f, 0);
   glVertex3f(0.0f, 1.0f, 0);
glEnd();

glBegin(GL_TRIANGLES);
   //5_Triangulo
   glVertex3f(-2.0f, 1.0f, 0);
   glVertex3f(-1.0f, 2.0f, 0);
   glVertex3f(0.0f, 1.0f, 0);
glEnd();

glBegin(GL_TRIANGLES);
   //6_Triangulo
   glVertex3f(-2.0f, 1.0f, 0);
   glVertex3f(-1.0f, 0.0f, 0);
   glVertex3f(0.0f, 1.0f, 0);
glEnd();

glBegin(GL_TRIANGLES);
   //7_Triangulo
   glVertex3f(-2.0f, 1.0f, 0);
   glVertex3f(-2.0f, -1.0f, 0);
   glVertex3f(-1.0f, 0.0f, 0);
glEnd();

glBegin(GL_TRIANGLES);
   //8_Triangulo
   glVertex3f(-2.0f, -1.0f, 0);
   glVertex3f(-1.0f, 0.0f, 0);
   glVertex3f(0.0f, -1.0f, 0);
glEnd();

glBegin(GL_TRIANGLES);
   //9_Triangulo
   glVertex3f(-2.0f, -1.0f, 0);
   glVertex3f(-1.0f, -2.0f, 0);
   glVertex3f(0.0f, -1.0f, 0);
glEnd();

glBegin(GL_TRIANGLES);
   //10_Triangulo
   glVertex3f(-1.0f, -2.0f, 0);
   glVertex3f(0.0f, -1.0f, 0);
   glVertex3f(1.0f, -2.0f, 0);
glEnd();

glBegin(GL_TRIANGLES);
   //11_Triangulo
   glVertex3f(0.0f, -1.0f, 0);
   glVertex3f(1.0f, -2.0f, 0);
   glVertex3f(2.0f, -1.0f, 0);
glEnd();

glBegin(GL_TRIANGLES);
   //12_Triangulo
   glVertex3f(0.0f, -1.0f, 0);
   glVertex3f(2.0f, -1.0f, 0);
   glVertex3f(1.0f, 0.0f, 0);
glEnd();

glBegin(GL_TRIANGLES);
   //13_Triangulo
   glVertex3f(2.0f, -1.0f, 0);
   glVertex3f(1.0f, 0.0f, 0);
   glVertex3f(2.0f, 1.0f, 0);
glEnd();

glBegin(GL_TRIANGLES);
   //14_Triangulo
   glVertex3f(1.0f, 0.0f, 0);
   glVertex3f(2.0f, 1.0f, 0);
   glVertex3f(0.0f, 1.0f, 0);
glEnd();

glBegin(GL_TRIANGLES);
   //15_Triangulo
   glVertex3f(0.0f, 1.0f, 0);
   glVertex3f(1.0f, 2.0f, 0);
   glVertex3f(2.0f, 1.0f, 0);
glEnd();

glPopMatrix();
glutSwapBuffers();
glFlush();

}

void spinDisplay(void)
{
   spin = spin + 2.0;
   if (spin > 360.0)
      spin = spin - 360.0;
   glutPostRedisplay();
}

void reshape(int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-6.0, 6.0, -6.0, 6.0, -10.0, 10.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void mouse(int button, int state, int x, int y) 
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay);
         break;
      case GLUT_MIDDLE_BUTTON:
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(NULL);
         break;
      default:
         break;
   }
}

void animate_callback(void){
    glutPostRedisplay(); /* Manda o redesenhar o ecr� em cada frame */
    return;
}


void keyboard_callback(unsigned char key, int x, int y){
    if (key==27) exit(0); /* Esc: sai do programa */
    return;
}
 
void keyboard_callback_special(int key, int x, int y){
    switch(key){
        case GLUT_KEY_F1:
            glColor3f(0.0, 0.0, 1.0);      /* F1: muda a cor para azul */
            break;

        case GLUT_KEY_F2:
            glColor3f(0.0, 1.0, 0.0);      /* F2: muda a cor para verde */
            break;

        case GLUT_KEY_F3:
            glColor3f(1.0, 0.0, 0.0);      /* F2: muda a cor para vermelho */
            break;

        default: /* isto aqui n�o faz nada, mas evita warnings :P */
            break;
    }
    return;
}
   


int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE);
   glutInitWindowSize (600, 600); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Laboratorio 3 - Ex 2");
   glutReshapeFunc(reshape); 
   glutMouseFunc(mouse);
   glutKeyboardFunc(keyboard_callback);
   glutSpecialFunc(keyboard_callback_special);
   glutDisplayFunc(display); 
   glutIdleFunc(animate_callback);
   init (); 
   glutMainLoop();
   return 0; 
}
