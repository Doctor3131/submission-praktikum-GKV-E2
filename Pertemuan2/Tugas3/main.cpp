#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.1415926535898
#define CIRCLE_POINTS 100

void RenderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    float offset = -0.4f; 
    float size = 0.2f;    

    for (int i = 0; i < 5; i++) {
        glPushMatrix();
        glColor3f(0.2f + 0.1f * i, 0.5f, 0.8f - 0.1f * i); 
        glBegin(GL_QUADS);

        glVertex3f(-size, offset, 0.0f);
        glVertex3f(size, offset, 0.0f);
        glVertex3f(size, offset + size, 0.0f);
        glVertex3f(-size, offset + size, 0.0f);


        glEnd();
        glPopMatrix();

        offset += size; 
        size *= 0.9f;   
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.7f, 0.3f, 0.1f);
    glBegin(GL_QUADS);
    glVertex3f(-1.0f, -1.0f, 0.0f); 
    glVertex3f(1.0f, -1.0f, 0.0f);  
    glVertex3f(1.0f, -0.4f, 0.0f);  
    glVertex3f(-1.0f, -0.4f, 0.0f); 
    glEnd();
    glPopMatrix();

    glFlush();
    }

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Tugas 3");
    glutDisplayFunc(RenderScene);
    glClearColor(0.25f, 0.15f, 0.10f, 1.0f);
    glutMainLoop();
    return 0;
}
