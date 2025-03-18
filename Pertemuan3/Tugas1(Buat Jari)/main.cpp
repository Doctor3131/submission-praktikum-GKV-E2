#include <GL/glut.h>

static int bahu = 0, siku = 0;
static int pergelangan = 0; 
static int jari1 = 0, jari2 = 0, jari3 = 0; 

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    
    // Buat bahu
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)bahu, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    
    // lengan atas
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();
    
    // transformasi bahu
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)siku, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    
    // lengan bawah
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();
    
    // pergelangan tangan
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)pergelangan, 0.0, 0.0, 1.0);
    
    // tangan
    glPushMatrix();
    glScalef(0.8, 0.7, 0.5);
    glutWireCube(1.0);
    glPopMatrix();
    
    // jari 1
    glPushMatrix();
    glTranslatef(0.4, 0.0, 0.0);
    glRotatef((GLfloat)jari1, 0.0, 0.0, 1.0);
    glTranslatef(0.2, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.4, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();
    
    // jari 2
    glPushMatrix();
    glTranslatef(0.4, 0.2, 0.0);
    glRotatef((GLfloat)jari2, 0.0, 0.0, 1.0);
    glTranslatef(0.2, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.4, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();
    
    // jari 3
    glPushMatrix();
    glTranslatef(0.4, -0.2, 0.0);
    glRotatef((GLfloat)jari3, 0.0, 0.0, 1.0);
    glTranslatef(0.2, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.4, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();
    
    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 's':
            bahu = (bahu + 5) % 360;
            glutPostRedisplay();
            break;
        case 'S':
            bahu = (bahu - 5) % 360;
            glutPostRedisplay();
            break;
        case 'e':
            siku = (siku + 5) % 360;
            glutPostRedisplay();
            break;
        case 'E':
            siku = (siku - 5) % 360;
            glutPostRedisplay();
            break;
        case 'w':
            pergelangan = (pergelangan + 5) % 360;
            glutPostRedisplay();
            break;
        case 'W':
            pergelangan = (pergelangan - 5) % 360;
            glutPostRedisplay();
            break;
        case 'f':
            jari1 = (jari1 + 5) % 360;
            glutPostRedisplay();
            break;
        case 'F':
            jari1 = (jari1 - 5) % 360;
            glutPostRedisplay();
            break;
        case 'g':
            jari2 = (jari2 + 5) % 360;
            glutPostRedisplay();
            break;
        case 'G':
            jari2 = (jari2 - 5) % 360;
            glutPostRedisplay();
            break;
        case 'h':
            jari3 = (jari3 + 5) % 360;
            glutPostRedisplay();
            break;
        case 'H':
            jari3 = (jari3 - 5) % 360;
            glutPostRedisplay();
            break;
        case 27: // tombol esc
            exit(0);
            break;
        default:
            break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}