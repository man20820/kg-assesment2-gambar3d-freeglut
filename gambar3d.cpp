#include <GL/freeglut.h>
#include <cmath>

#define PI 3.14159265

void gambarGaris(float x1, float y1, float z1, float x2, float y2, float z2) {
    glBegin(GL_LINES);
    glVertex3f(x1, y1, z1);
    glVertex3f(x2, y2, z2);
    glEnd();
}

void gambar3d() {
    float t = (1.0 + std::sqrt(5.0)) / 2.0; 

    
    float vertices[12][3] = {
        {-1, t, 0},
        {1, t, 0},
        {-1, -t, 0},
        {1, -t, 0},
        {0, -1, t},
        {0, 1, t},
        {0, -1, -t},
        {0, 1, -t},
        {t, 0, -1},
        {t, 0, 1},
        {-t, 0, -1},
        {-t, 0, 1}
    };

    
    int indices[30][2] = {
        {0, 1}, {0, 4}, {0, 5}, {0, 11}, {0, 10},
        {1, 7}, {1, 9}, {1, 5}, {2, 3}, {2, 6},
        {2, 4}, {2, 9}, {3, 8}, {3, 4}, {3, 6},
        {4, 5}, {4, 9}, {5, 11}, {5, 9}, {6, 7},
        {6, 8}, {7, 8}, {7, 9}, {8, 9}, {10, 11},
        {10, 6}, {10, 7}, {11, 5}, {11, 7}, {11, 4}
    };

    glColor3f(1, 0.5, 0.2); 

    
    for (int i = 0; i < 30; i++) {
        gambarGaris(
            vertices[indices[i][0]][0], vertices[indices[i][0]][1], vertices[indices[i][0]][2],
            vertices[indices[i][1]][0], vertices[indices[i][1]][1], vertices[indices[i][1]][2]
        );
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0); 

    glRotatef(30, 1, 0, 0); 
    glRotatef(45, 0, 1, 0); 

    gambar3d();

    glFlush();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)width / (float)height, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("gambar3d");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glEnable(GL_DEPTH_TEST);

    glutMainLoop();

    return 0;
}
