/*
* lab5 cubo colorido: cubo.colo.cpp
 *<João Victor Martins Reis>, RA <11201810522>, data 11/10/2022
 *<Guilherme Braz de Lima>, RA <11201922157>, data 11/10/2022
 *<Vitor Inácio da Silva>, RA <11201810048>, data 11/10/2022
 *<Jeniffer Santos Campos>, RA <11201920325>, data 11/10/2022
 */

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>


namespace Cube {

const int NUM_VERTICES = 8;
const int NUM_FACES = 6;

GLint vertices[NUM_VERTICES][3] = {
  {0, 0, 0}, {0, 0, 1}, {0, 1, 0}, {0, 1, 1},
  {1, 0, 0}, {1, 0, 1}, {1, 1, 0}, {1, 1, 1}};

GLint faces[NUM_FACES][4] = {
  {1, 5, 7, 3}, {5, 4, 6, 7}, {4, 0, 2, 6},
  {3, 7, 6, 2}, {0, 1, 3, 2}, {0, 4, 5, 1}};

GLfloat vertexColors[NUM_VERTICES][3] = {
  {0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 1.0, 0.0}, {0.0, 1.0, 1.0},
  {1.0, 0.0, 0.0}, {1.0, 0.0, 1.0}, {1.0, 1.0, 0.0}, {1.0, 1.0, 1.0}};

void draw() {
  glBegin(GL_QUADS);
  for (int i = 0; i < NUM_FACES; i++) {
    for (int j = 0; j < 4; j++) {
      glColor3fv((GLfloat*)&vertexColors[faces[i][j]]);
      glVertex3iv((GLint*)&vertices[faces[i][j]]);
    }
  }
  glEnd();
}
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  Cube::draw();
  glFlush();
  glutSwapBuffers();
}


void init() {
  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);
}

// The usual main for a GLUT application.
int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Cubo colorido");


  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(20.0, 1, 0.5, 40.0);
  glMatrixMode(GL_MODELVIEW);
  
  glLoadIdentity();
  gluLookAt(8, 6, 6, .5, .5, .5, 1, 1, 0);
  glutPostRedisplay();

  
  glutDisplayFunc(display);
  init();
  glutMainLoop();
}
