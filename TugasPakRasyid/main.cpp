#include <GL/glut.h>
#include <math.h>

static int putarX = 0, putarY = 0;

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void buatSilinder(float radius, float height, int slices) {
    float angle, x, y;
    int i;
    
    // Tutup bawah silinder
    glBegin(GL_POLYGON);
    for (i = 0; i < slices; i++) {
        angle = 2 * M_PI * i / slices;
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, 0, y);
    }
    glEnd();
    
    // Tutup atas silinder
    glBegin(GL_POLYGON);
    for (i = 0; i < slices; i++) {
        angle = 2 * M_PI * i / slices;
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, height, y);
    }
    glEnd();
    
    // Sisi silinder
    glBegin(GL_QUAD_STRIP);
    for (i = 0; i <= slices; i++) {
        angle = 2 * M_PI * i / slices;
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, 0, y);
        glVertex3f(x, height, y);
    }
    glEnd();
}

// Fungsi untuk membuat kasur
void buatKasur() {
    // Kasur 
    glPushMatrix();
    glColor3f(0.8, 0.6, 0.5);
    glScalef(5.0, 0.5, 3.0);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Rangka kasur
    glPushMatrix();
    glColor3f(0.5, 0.3, 0.1);
    glTranslatef(0.0, -0.5, 0.0);
    glScalef(5.2, 0.5, 3.2);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Kaki kasur 1 (kiri depan)
    glPushMatrix();
    glColor3f(0.4, 0.2, 0.1);
    glTranslatef(-2.3, -1.25, 1.3);
    glScalef(0.4, 1.0, 0.4);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Kaki kasur 2 (kanan depan)
    glPushMatrix();
    glColor3f(0.4, 0.2, 0.1);
    glTranslatef(2.3, -1.25, 1.3);
    glScalef(0.4, 1.0, 0.4);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Kaki kasur 3 (kiri belakang)
    glPushMatrix();
    glColor3f(0.4, 0.2, 0.1);
    glTranslatef(-2.3, -1.25, -1.3);
    glScalef(0.4, 1.0, 0.4);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Kaki kasur 4 (kanan belakang)
    glPushMatrix();
    glColor3f(0.4, 0.2, 0.1);
    glTranslatef(2.3, -1.25, -1.3);
    glScalef(0.4, 1.0, 0.4);
    glutSolidCube(1.0);
    glPopMatrix();
}

// Fungsi untuk membuat bantal
void buatBantal() {
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glScalef(1.2, 0.3, 0.8);
    glutSolidCube(1.0);
    glPopMatrix();
}

// Fungsi untuk membuat guling (silinder)
void buatGuling() {
    glPushMatrix();
    glColor3f(1.0, 1.0, 0.9);
    glRotatef(90, 0, 0, 1); 
    buatSilinder(0.25, 2.5, 20);
    glPopMatrix();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    
    glPushMatrix();
    
    glRotatef((GLfloat)putarX, 1.0, 0.0, 0.0);
    glRotatef((GLfloat)putarY, 0.0, 1.0, 0.0);
    
    buatKasur();
    glPushMatrix();
    glTranslatef(-1.8, 0.4, -0.5);
    glRotatef(90, 0.0, 1.0, 0.0); 
    buatBantal();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.5, 0.5, 0.7);
    buatGuling();
    glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

void reshapeOrthograpic(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    GLdouble aspect = (GLdouble)w / (GLdouble)h;
    GLdouble size = 5.0;
    
    if (w <= h)
        glOrtho(-size, size, -size*h/w, size*h/w, 1.0, 20.0);
    else
        glOrtho(-size*w/h, size*w/h, -size, size, 1.0, 20.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 3.0, 8.0,  
              0.0, 0.0, 0.0,  
              0.0, 1.0, 0.0); 
}


void reshapeIsometric(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    GLdouble aspect = (GLdouble)w / (GLdouble)h;
    GLdouble size = 5.0;
    
    if (w <= h)
        glOrtho(-size, size, -size*h/w, size*h/w, 1.0, 20.0);
    else
        glOrtho(-size*w/h, size*w/h, -size, size, 1.0, 20.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(5.0, 5.0, 5.0,  
              0.0, 0.0, 0.0,  
              0.0, 1.0, 0.0); 
}

void rehsapeDimetric(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    GLdouble aspect = (GLdouble)w / (GLdouble)h;
    GLdouble size = 5.0;
    
    if (w <= h)
        glOrtho(-size, size, -size*h/w, size*h/w, 1.0, 20.0);
    else
        glOrtho(-size*w/h, size*w/h, -size, size, 1.0, 20.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(5.0, 3.0, 6.0,  
              0.0, 0.0, 0.0,  
              0.0, 1.0, 0.0); 
}

void reshapeTrimetric(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    GLdouble aspect = (GLdouble)w / (GLdouble)h;
    GLdouble size = 5.0;
    
    if (w <= h)
        glOrtho(-size, size, -size*h/w, size*h/w, 1.0, 20.0);
    else
        glOrtho(-size*w/h, size*w/h, -size, size, 1.0, 20.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(7.0, 4.0, 5.0,  
              0.0, 0.0, 0.0,  
              0.0, 1.0, 0.0); 
}

void reshapePOV1(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 8.0,  
              0.0, 0.0, 0.0,  
              0.0, 1.0, 0.0); 
}

void reshapePOV2(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(5.0, 0.0, 8.0,  
              0.0, 0.0, 0.0,  
              0.0, 1.0, 0.0); 
}

void reshapePOV3(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(5.0, 3.0, 8.0,  
              0.0, 0.0, 0.0,  
              0.0, 1.0, 0.0); 
}


void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'x': 
            putarX = (putarX + 5) % 360;
            glutPostRedisplay();
            break;
        case 'X': 
            putarX = (putarX - 5) % 360;
            glutPostRedisplay();
            break;
        case 'y': 
            putarY = (putarY + 5) % 360;
            glutPostRedisplay();
            break;
        case 'Y': 
            putarY = (putarY - 5) % 360;
            glutPostRedisplay();
            break;
        case 27: 
            exit(0);
            break;
        default:
            break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Kasur 3D Solid dengan Satu Bantal dan Satu Guling");
    init();
    
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutReshapeFunc(reshapePOV3);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}