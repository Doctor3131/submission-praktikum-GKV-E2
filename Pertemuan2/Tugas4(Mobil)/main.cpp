#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926535898
#define CIRCLE_POINTS 100

void RenderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // langit
    glPushMatrix();
    glColor3f(0.5f, 0.7f, 1.0f);
    glBegin(GL_QUADS);
    glVertex3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, 1.0f, 0.0f);
    glEnd();
    glPopMatrix();
    
    // jalan
    glPushMatrix();
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-1.0f, 0.0f, 0.0f);
    glEnd();
    glPopMatrix();
    
    // badan mobil bawah
    glPushMatrix();
    glColor3f(0.8f, 0.2f, 0.2f); 
    glBegin(GL_QUADS);
    glVertex3f(-0.6f, -0.3f, 0.0f);
    glVertex3f(0.6f, -0.3f, 0.0f);
    glVertex3f(0.6f, -0.1f, 0.0f);
    glVertex3f(-0.6f, -0.1f, 0.0f);
    glEnd();
    glPopMatrix();
    
    // badan mobil atas
    glPushMatrix();
    glColor3f(0.7f, 0.2f, 0.2f); 
    glBegin(GL_QUADS);
    glVertex3f(-0.3f, -0.1f, 0.0f);
    glVertex3f(0.3f, -0.1f, 0.0f);
    glVertex3f(0.2f, 0.1f, 0.0f);
    glVertex3f(-0.2f, 0.1f, 0.0f);
    glEnd();
    glPopMatrix();
    
    // jendela 1
    glPushMatrix();
    glColor3f(0.8f, 0.9f, 1.0f); 
    glBegin(GL_QUADS);
    glVertex3f(-0.25f, -0.08f, 0.0f);
    glVertex3f(-0.05f, -0.08f, 0.0f);
    glVertex3f(-0.05f, 0.08f, 0.0f);
    glVertex3f(-0.15f, 0.08f, 0.0f);
    glEnd();
    glPopMatrix();
    
    // jendela 2
    glPushMatrix();
    glColor3f(0.8f, 0.9f, 1.0f); 
    glBegin(GL_QUADS);
    glVertex3f(0.05f, -0.08f, 0.0f);
    glVertex3f(0.25f, -0.08f, 0.0f);
    glVertex3f(0.15f, 0.08f, 0.0f);
    glVertex3f(0.05f, 0.08f, 0.0f);
    glEnd();
    glPopMatrix();
    
    // roda 1
    glPushMatrix();
    glColor3f(0.1f, 0.1f, 0.1f); 
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(-0.4f, -0.3f, 0.0f); 
    for (int i = 0; i <= CIRCLE_POINTS; i++) {
        float angle = 2 * PI * i / CIRCLE_POINTS;
        glVertex3f(-0.4f + 0.12f * cos(angle), -0.3f + 0.12f * sin(angle), 0.0f);
    }
    glEnd();
    glPopMatrix();
    
    // daleman roda 1
    glPushMatrix();
    glColor3f(0.7f, 0.7f, 0.7f); 
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(-0.4f, -0.3f, 0.0f); 
    for (int i = 0; i <= CIRCLE_POINTS; i++) {
        float angle = 2 * PI * i / CIRCLE_POINTS;
        glVertex3f(-0.4f + 0.06f * cos(angle), -0.3f + 0.06f * sin(angle), 0.0f);
    }
    glEnd();
    glPopMatrix();
    
    // roda 2
    glPushMatrix();
    glColor3f(0.1f, 0.1f, 0.1f); 
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.4f, -0.3f, 0.0f); 
    for (int i = 0; i <= CIRCLE_POINTS; i++) {
        float angle = 2 * PI * i / CIRCLE_POINTS;
        glVertex3f(0.4f + 0.12f * cos(angle), -0.3f + 0.12f * sin(angle), 0.0f);
    }
    glEnd();
    glPopMatrix();
    
    // daleman roda 2
    glPushMatrix();
    glColor3f(0.7f, 0.7f, 0.7f); 
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.4f, -0.3f, 0.0f); 
    for (int i = 0; i <= CIRCLE_POINTS; i++) {
        float angle = 2 * PI * i / CIRCLE_POINTS;
        glVertex3f(0.4f + 0.06f * cos(angle), -0.3f + 0.06f * sin(angle), 0.0f);
    }
    glEnd();
    glPopMatrix();
    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Tugas4()");
    glutDisplayFunc(RenderScene);
    glClearColor(0.25f, 0.15f, 0.10f, 1.0f);
    glutMainLoop();
    return 0;
}