/*
 * -lab03-01cpp
 *<João Victor Martins Reis>, RA <11201810522>, data 25/10/2022
 *<Guilherme Braz de Lima>, RA <11201922157>, data 25/10/2022
 *<Vitor Inácio da Silva>, RA <11201810048>, data 25/10/2022
 *<Jeniffer Santos Campos>, RA <11201920325>, data 25/10/2022
 */

 
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>

static int shoulder = 0, elbow = 0 , dedo_base = 0 , dedo_ponta = 0;

void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glPushMatrix();
   //Mouse movements
   glRotatef(10, 1.0, 0.0, 0.0);
   glRotatef(-80, 0.0, 1.0, 0.0);
   glTranslatef (-1.0, 0.0, 0.0);

   //Shoulder
   glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);
   glTranslatef (1.0, 0.0, 0.0);
   glPushMatrix();
   glScalef (2.0, 0.6, 1.0);
   glutWireCube (1.0);
   glPopMatrix();
   glTranslatef (1.0, 0.0, 0.0);

   //Elbow
   glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
   glTranslatef (1.0, 0.0, 0.0);
   glPushMatrix();
   glScalef (2.0, 0.6, 1.0);
   glutWireCube (1.0);
   glPopMatrix();



 glPushMatrix();
   //dedo 1.1 
   glTranslatef(1.0, 0.0, 0.0);
   glRotatef((GLfloat)dedo_base, 0.0, 0.0, 1.0);
   glTranslatef(0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.1, 0.1);
   glutWireCube(1);
   glPopMatrix();

   //dedo 1.2 
   glTranslatef(0.15, 0.0, 0.0);
   glRotatef((GLfloat)dedo_ponta, 0.0, 0.0, 1.0);
   glTranslatef(0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.1, 0.1);
   glutWireCube(1);
   glPopMatrix();


   //dedo 2.1 
   glTranslatef(-0.45, 0.0, 0.2);
   glRotatef((GLfloat)dedo_base, 0.0, 0.0, -1.0);
   glTranslatef(0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.1, 0.1);
   glutWireCube(1);
   glPopMatrix();

   //dedo 2.2 
   glTranslatef(0.15, 0.0, 0.0);
   glRotatef(-(GLfloat)dedo_ponta, 0.0, 0.0, -1.0);
   glTranslatef(0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.1, 0.1);
   glutWireCube(1);
   glPopMatrix();

   //dedo 3.1 
   glTranslatef(-0.45, 0.0, 0.2);
   glRotatef((GLfloat)dedo_base, 0.0, 0.0, 1.0);
   glTranslatef(0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.1, 0.1);
   glutWireCube(1);
   glPopMatrix();

   //dedo 3.2 
   glTranslatef(0.15, 0.0, 0.0);
   glRotatef((GLfloat)dedo_ponta, 0.0, 0.0, 1.0);
   glTranslatef(0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.1, 0.1);
   glutWireCube(1);
   glPopMatrix();

   //dedo 4.1 
   glTranslatef(-0.45, 0.0, -0.6);
   glRotatef((GLfloat)dedo_base, 0.0, 0.0, -1.0);
   glTranslatef(0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.1, 0.1);
   glutWireCube(1);
   glPopMatrix();

   //dedo 4.2 
   glTranslatef(0.15, 0.0, 0.0);
   glRotatef(-(GLfloat)dedo_ponta, 0.0, 0.0, -1.0);
   glTranslatef(0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.1, 0.1);
   glutWireCube(1);
   glPopMatrix();


   //dedo 5.1 
   glTranslatef(-0.45, 0.2, -0.25);
   glRotatef((GLfloat)dedo_base, 0.0, 0.0, 1.0);
   glTranslatef(0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.1, 0.1);
   glutWireCube(1);
   glPopMatrix();

   //dedo 5.2 
   glTranslatef(0.15, 0.0, 0.0);
   glRotatef((GLfloat)dedo_ponta, 0.0, 0.0, 1.0);
   glTranslatef(0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.1, 0.1);
   glutWireCube(1);
   glPopMatrix();

   glPopMatrix();

   glPopMatrix();
   glutSwapBuffers();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(85.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef (0.0, 0.0, -5.0);
}

void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
      case 's':
         shoulder = (shoulder + 5) % 360;
         glutPostRedisplay();
         break;
      case 'S':
         shoulder = (shoulder - 5) % 360;
         glutPostRedisplay();
         break;
      case 'e':
         elbow = (elbow + 5) % 360;
         glutPostRedisplay();
         break;
      case 'E':
         elbow = (elbow - 5) % 360;
         glutPostRedisplay();
         break;

   case 'd':
      dedo_base = (dedo_base + 5) % 360;
      glutPostRedisplay();
      break;
   case 'D':
      dedo_base = (dedo_base - 5) % 360;
      glutPostRedisplay();
      break;
      case 'f':
      dedo_ponta = (dedo_ponta + 5) % 360;
      glutPostRedisplay();
      break;
   case 'F':
      dedo_ponta = (dedo_ponta - 5) % 360;
      glutPostRedisplay();
      break;

      case 27:
         exit(0);
         break;
      default:
         break;
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("lab03-1");
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}
