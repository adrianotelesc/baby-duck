#include <stdlib.h>
#include <GL/glut.h>

/** 
 * @author: Adriano Teles
 * */

static int rotation_y = 0, rotation_x = 0;

void init(void) {
    glEnable (GL_DEPTH_TEST);
    glClearColor(0.415686275, 0.811764706, 0.929411765, 1.0);
}

void drawDuck() {
    glPushMatrix();

    /* Duck left feet */
    glTranslatef(-1.50, 0.0, 0.5);
    glScalef(2.0, 0.5, 2.5);
    glColor3f(0.850980392, 0.349019608, 0.22745098);
    glutSolidCube(1.0);

    glPopMatrix();
    glPushMatrix();

    /* Duck right feet */
    glTranslatef(1.50, 0.0, 0.5);
    glScalef(2.0, 0.5, 2.5);
    glColor3f(0.850980392, 0.349019608, 0.22745098);
    glutSolidCube(1.0);

    glPopMatrix();
    glPushMatrix();

    /* Duck left leg */
    glTranslatef(-1.25, 1.0625, 0.0);
    glScalef(0.5, 2.125, 0.5);
    glColor3f(0.850980392, 0.349019608, 0.22745098);
    glutSolidCube(1.0);

    glPopMatrix();
    glPushMatrix();

    /* Duck right leg */
    glTranslatef(1.25, 1.0625, 0.0);
    glScalef(0.5, 2.125, 0.5);
    glColor3f(0.850980392, 0.349019608, 0.22745098);
    glutSolidCube(1.0);

    glPopMatrix();
    glPushMatrix();

    /* Duck body */
    glTranslatef(0.0, 3.25, -0.25);
    glScalef(3.25, 2.75, 5.5);
    glColor3f(0.964705882, 0.890196078, 0.337254902);
    glutSolidCube(1.0);

    glPopMatrix();
    glPushMatrix();

    /* Duck right wing */
    glTranslatef(2.125, 3.75, 0.0);
    glScalef(1.0, 2.0, 4.0);
    glColor3f(0.964705882, 0.890196078, 0.337254902);
    glutSolidCube(1.0);

    glPopMatrix();
    glPushMatrix();

    /* Duck left wing */
    glTranslatef(-2.125, 3.75, 0.0);
    glScalef(1.0, 2.0, 4.0);
    glColor3f(0.964705882, 0.890196078, 0.337254902);
    glutSolidCube(1.0);

    glPopMatrix();
    glPushMatrix();

    /* Duck tail */
    glTranslatef(0.0, 4.75, -2.5);
    glScalef(2.25, 0.5, 1.0);
    glColor3f(0.964705882, 0.890196078, 0.337254902);
    glutSolidCube(1.0);

    glPopMatrix();
    glPushMatrix();

    /* Duck head */
    glTranslatef(0.0, 6.75, 0.5);
    glScalef(3.25, 4.5, 4.0);
    glColor3f(0.964705882, 0.890196078, 0.337254902);
    glutSolidCube(1.0);

    glPopMatrix();
    glPushMatrix();

    /* Duck bill */
    glTranslatef(0.0, 7.25, 3.75);
    glScalef(2.5, 1.0, 2.5);
    glColor3f(0.850980392, 0.349019608, 0.22745098);
    glutSolidCube(1.0);

    glPopMatrix();
    glPushMatrix();

    /* Duck right eye */
    glTranslatef(1.75, 7.50, 1);
    glScalef(0.1, 0.5, 0.5);
    glColor3f(0.384313725, 0.235294118, 0.258823529);
    glutSolidCube(1.0);

    glPopMatrix(); 
    glPushMatrix();

    /* Duck left eye */
    glTranslatef(-1.75, 7.50, 1.0);
    glScalef(0.1, 0.5, 0.5);
    glColor3f(0.384313725, 0.235294118, 0.258823529);
    glutSolidCube(1.0);

    glPopMatrix(); 
    glPopMatrix();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotatef((GLfloat)rotation_x, 1.0, 0.0, 0.0);
    glRotatef((GLfloat)rotation_y, 0.0, 1.0, 0.0);
    drawDuck();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glTranslatef(0.0, -4, -15.0);
    glRotatef((GLfloat)10.0, 1.0, 0.0, 0.0);
}

void keyboard(unsigned char key, int x, int y) {
    if(key == 's' || key == 'S')
        rotation_x = (rotation_x + 2) % 360;
    if(key == 'w' || key == 'W')
            rotation_x = (rotation_x - 2) % 360;
    if(key == 'd' || key == 'D')
        rotation_y = (rotation_y + 2) % 360;
    if(key == 'a' || key == 'A')
        rotation_y = (rotation_y - 2) % 360;
    glutPostRedisplay();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Baby Duck - Crossy Road by Adriano Teles");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
