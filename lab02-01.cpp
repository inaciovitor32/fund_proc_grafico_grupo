/*
 * -lab02-01.cpp
 *<João Victor Martins Reis>, RA <11201810522>, data 11/10/2022
 *<Guilherme Braz de Lima>, RA <11201922157>, data 11/10/2022
 *<Vitor Inácio da Silva>, RA <11201810048>, data 11/10/2022
 *<Jeniffer Santos Campos>, RA <11201920325>, data 11/10/2022
 */

#include <GL/glut.h>

void display(void)
{
/* clear all pixels  */
   glClear (GL_COLOR_BUFFER_BIT);

  glBegin(GL_TRIANGLE_STRIP); 
  glColor3f (0.29, 1, 1);
   	glVertex3f (0.35, 0.25, 0.0);//P2
 	glVertex3f (0.1, 0.85, 0.0);//P1
   	glVertex3f (0.55, 0.55, 0.0);//P5
   	glVertex3f (0.55, 0.55, 0.0);//P5
 	glVertex3f (0.9, 0.35, 0.0);//P4
	glVertex3f (0.35, 0.25, 0.0);//P1
	glVertex3f (0.8, 0.95, 0.0);//P4

      
   glEnd();

/* don't wait!  
 * start processing buffered OpenGL routines 
 */
   glFlush ();
}

void init (void) 
{
/* select clearing color 	*/
   glClearColor (1,1, 1, 1);

/* initialize viewing values  */
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (250, 250); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("lab02-01");
   init ();
   glutDisplayFunc(display); 
   glutMainLoop();
   return 0;   /* ANSI C requires main to return int. */
}
