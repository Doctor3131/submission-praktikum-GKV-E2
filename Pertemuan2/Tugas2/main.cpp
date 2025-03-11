#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.1415926535898
#define CIRCLE_POINTS 100

void RenderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // (GL_QUADS)
    glPushMatrix();
    glColor3f(0.8f, 0.5f, 0.3f); 
    glBegin(GL_QUADS);
    glVertex3f(-0.5f, -0.4f, 0.0f);
    glVertex3f(-0.8f, -0.6f, 0.0f);
    glVertex3f(0.8f, -0.6f, 0.0f);
    glVertex3f(0.5f,-0.4f, 0.0f);
    glEnd();
    glPopMatrix();

    // (GL_TRIANGLE_FAN)
    glPushMatrix();
    glColor3f(1.0f, 0.85f, 0.3f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0f, 0.0f, 0.0f); // Titik pusat
    for (int i = 0; i <= CIRCLE_POINTS; i++) {
        float angle = 2 * PI * i / CIRCLE_POINTS;
        glVertex3f(0.5 * cos(angle), 0.5 * sin(angle), 0.0);
    }
    glEnd();
    glPopMatrix();

    // (GL_LINE_STRIP)
    glPushMatrix();
    glLineWidth(10.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINE_STRIP);
    glVertex3f(-0.4f, 0.4f, 0.0f);
    glVertex3f(-0.3f, 0.4f, 0.0f);
    glVertex3f(-0.2f, 0.3f, 0.0f);
    glEnd();
    glPopMatrix();

    // (GL_LINE_LOOP)
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < CIRCLE_POINTS; i++) {
        float angle = 2 * PI * i / CIRCLE_POINTS;
        glVertex3f(0.5 * cos(angle), 0.5 * sin(angle), 0.0);
    }
    glEnd();
    glPopMatrix();



    // (GL_TRIANGLE_STRIP)
    glPushMatrix();
    glColor3f(0.3f, 0.5f, 0.2f);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex3f(-0.3f, 0.4f, 0.0f);  
    glVertex3f(-0.35f, 0.35f, 0.0f); 
    glVertex3f(-0.3f, 0.35f, 0.0f); 
    glVertex3f(-0.38f, 0.28f, 0.0f); 
    glEnd();
    glPopMatrix();


    // (GL_QUAD_STRIP)
    glPushMatrix();
    glColor3f(0.6f, 0.3f, 0.1f); 
    glBegin(GL_QUADS);
    glVertex3f(-0.8f, -0.6f, 0.0f);  
    glVertex3f(0.8f, -0.6f, 0.0f);  
    glVertex3f(0.8f, -0.9f, 0.0f);  
    glVertex3f(-0.8f, -0.9f, 0.0f);  
    glEnd();
    glPopMatrix();

    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Tugas 2");
    glutDisplayFunc(RenderScene);
    glClearColor(0.25f, 0.15f, 0.10f, 1.0f);
    glutMainLoop();
    return 0;
}
