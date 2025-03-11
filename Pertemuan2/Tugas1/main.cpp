#include <GL/glut.h>
#include <stdlib.h>

void renderObject(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // buat bintang
    glPushMatrix();
    glPointSize(0.5f);
    glBegin(GL_POINTS);
        for (int i = 0; i < 1000; i ++) {
            glColor3f(1.0f, 1.0f, 1.0f);

            float x = ((float)rand() / RAND_MAX) * 2.0f - 1.0f;
            float y = ((float)rand() / RAND_MAX) * 2.0f - 1.0f;

            glVertex3f(x,y,0.0);
        }
    glEnd();
    glPopMatrix();

    // matahari
    glPushMatrix();
    glPointSize(20.0f);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.85f, 0.3f);
    glVertex3f(0.5f, 0.5f, 0.0f);
    glEnd();
    glPopMatrix();

    // planet 1
    glPushMatrix();
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    glColor3f(0.53f, 0.81f, 0.92f);  
    glVertex3f(0.6f, 0.6f, 0.0f);
    glEnd();
    glPopMatrix();

    // pulau di planet 1
    glPushMatrix();
    glPointSize(2.5f);
    glBegin(GL_POINTS);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.6f, 0.6f, 0.0f);
    glEnd();
    glPopMatrix();

    // planet 2
    glPushMatrix();
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    glColor3f(0.8f, 0.3f, 0.1f);  
    glVertex3f(0.35f, 0.35f, 0.0f);
    glEnd();
    glPopMatrix();

    // bingkai diagonal
    glPushMatrix();
    glLineWidth(10.0f);
    glBegin(GL_LINES);
    glColor3f(0.40f, 0.26f, 0.13f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, -1.0f, 0.0f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glLineWidth(10.0f);
    glBegin(GL_LINES);
    glColor3f(0.40f, 0.26f, 0.13f);
    glVertex3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-1.0f, 0.0f, 0.0f);
    glEnd();
    glPopMatrix();

    // bingkai luar
    float n = 30.0f;  
    float r = 0.40f, g = 0.26f, b = 0.13f;  

    glPushMatrix();
    glLineWidth(n);
    glBegin(GL_LINES);
    glColor3f(r, g, b);
    glVertex3f(1.0f, -1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glLineWidth(n);
    glBegin(GL_LINES);
    glColor3f(r, g, b);
    glVertex3f(-1.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glLineWidth(n);
    glBegin(GL_LINES);
    glColor3f(r, g, b);
    glVertex3f(1.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 0.0f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glLineWidth(n);
    glBegin(GL_LINES);
    glColor3f(r, g, b);
    glVertex3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, 1.0f, 0.0f);
    glEnd();
    glPopMatrix();

    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Tugas 1");
    glutDisplayFunc(renderObject);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glutMainLoop();
    return 0;
}