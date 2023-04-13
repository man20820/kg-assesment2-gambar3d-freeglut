#include <GL/freeglut.h>

void display() {
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);

  // Find the center point of the vector
  GLfloat center_x = (0.450 + 0.515 + 0.570 + 0.545 + 0.625 + 0.635 + 0.725 + 0.700 + 0.735 + 0.600 + 0.610 + 0.475 + 0.480 + 0.440 + 0.450 + 0.310 + 0.320 + 0.185 + 0.220 + 0.195 + 0.280 + 0.295 + 0.375 + 0.350 + 0.400) / 24.0;
  GLfloat center_y = (-0.000 -0.100 -0.075 -0.230 -0.155 -0.200 -0.185 -0.280 -0.300 -0.420 -0.465 -0.450 -0.600 -0.600 -0.450 -0.465 -0.420 -0.300 -0.280 -0.190 -0.200 -0.160 -0.235 -0.075 -0.100) / 24.0;

  glMatrixMode(GL_MODELVIEW); // switch to model view matrix
  glLoadIdentity(); // reset the model view matrix
  glTranslatef(-center_x, -center_y, 0.0); // translate to the center of the vector

  glColor3f(1.0, 0.0, 0.0);
  glBegin(GL_LINE_LOOP);
  glVertex2f(0.450, -0.000);
  glVertex2f(0.515, -0.100);
  glVertex2f(0.570, -0.075);
  glVertex2f(0.545, -0.230);
  glVertex2f(0.625, -0.155);
  glVertex2f(0.635, -0.200);
  glVertex2f(0.725, -0.185);
  glVertex2f(0.700, -0.280);
  glVertex2f(0.735, -0.300);
  glVertex2f(0.600, -0.420);
  glVertex2f(0.610, -0.465);
  glVertex2f(0.475, -0.450);
  glVertex2f(0.480, -0.600);
  glVertex2f(0.440, -0.600);
  glVertex2f(0.450, -0.450);
  glVertex2f(0.310, -0.465);
  glVertex2f(0.320, -0.420);
  glVertex2f(0.185, -0.300);
  glVertex2f(0.220, -0.280);
  glVertex2f(0.195, -0.190);
  glVertex2f(0.280, -0.200);
  glVertex2f(0.295, -0.160);
  glVertex2f(0.375, -0.235);
  glVertex2f(0.350, -0.075);
  glVertex2f(0.400, -0.100);
  glEnd();

  glFlush();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(400, 400);
  glutCreateWindow("Godong");
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
