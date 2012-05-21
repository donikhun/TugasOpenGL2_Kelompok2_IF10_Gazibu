/* 
 * File:   main.cpp
 * Author: Doni
 *
 * Created on 21 Mei 2012, 20:54
 * 
 * Kelompok 2
 * Febrian Doni (10108513)
 * Zulfikar Sembiring (10108475)
 * Nurhalimah (10108513)
 * Muhammad Fauzan (10108473)
 */

#include <windows.h>
#include <GL/glut.h>


double putar = 0.0;
double besar = -13.0;

void gazibu(double putar) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, besar);
    glRotatef(putar, 0.0f, 1.0f, 0.0f);

    //lantai
    glPushMatrix();
    glScaled(0.8, 0.04, 0.8);
    glTranslatef(0.0, -30.2, 0.0);
    glutSolidCube(7.0);
    glPopMatrix();

    //atap
    glPushMatrix();
    glScaled(0.8, 1.0, 0.8);
    glTranslatef(0.0, 0.9, 0.0);
    glRotated(-90, 1, 0, 0);
    glutSolidCone(4.5, 2, 8, 1);
    glPopMatrix();

    glTranslatef(0.0, 0.4, 0.0);
    glScaled(1.2, 0.25, 1.2);



    //tiang1
    glPushMatrix();
    glTranslated(2, -1.9, 2);
    glScaled(.2, 10.5, .2);
    glutSolidSphere(0.4, 80, 120);
    glPopMatrix();


    //tiang2
    glPushMatrix();
    glTranslated(-2, -1.9, 2);
    glScaled(.2, 10.5, .2);
    glutSolidSphere(0.4, 80, 120);
    glPopMatrix();


    //tiang3
    glPushMatrix();
    glTranslated(-2, -1.9, -2);
    glScaled(.2, 10.5, .2);
    glutSolidSphere(0.4, 80, 120);
    glPopMatrix();


    //tiang4
    glPushMatrix();
    glTranslated(2, -1.9, -2);
    glScaled(.2, 10.5, .2);
    glutSolidSphere(0.4, 80, 120);
    glPopMatrix();


    glFlush();
    glutSwapBuffers();
}

void putar_kanan() {
    putar += 1.0;
    gazibu(putar);
}

void putar_kiri() {
    putar -= 1.0;
    gazibu(putar);
}

void besar_tam() {
    besar++;
    glutPostRedisplay();
}

void besar_kec() {
    besar--;
    glutPostRedisplay();
}

void putar_skanan() {
    putar++;
    glutPostRedisplay();
}

void putar_skiri() {
    putar--;
    glutPostRedisplay();
}

void init() {

    /* Background and foreground color */
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(.0, .0, .0);
    glViewport(0, 0, 640, 480);

    /* Select the projection matrix and reset it then setup our view perspective */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0f, (GLfloat) 640 / (GLfloat) 480, 0.1f, 200.0f);

    /* Select the modelview matrix, which we alter with rotatef() */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void display() {

    GLfloat mat_ambient[] = {0.0f, 1.0f, 2.0f, 1.0f};
    GLfloat mat_diffuse[] = {0.0f, 1.5f, .5f, 1.0f};
    GLfloat mat_specular[] = {5.0f, 1.0f, 1.0f, 1.0f};
    GLfloat mat_shininess[] = {50.0f};
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    /*GLfloat lightIntensity[]={3.7f,0.7f,0.7f,1.0f};     Orange
    GLfloat light_position[]={2.0f,5.0f,3.0f,1.0f};*/

    /*light source properties*/
    GLfloat lightIntensity[] = {1.7f, 1.7f, 1.7f, 1.0f};
    GLfloat light_position[] = {2.0f, 0.0f, 0.0f, 0.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    GLfloat light_position2[] = {0.0f, 0.0f, 8.0f, 0.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, light_position2);
    GLfloat light_position3[] = {0.0f, 5.0f, 2.0f, 0.5f};
    glLightfv(GL_LIGHT0, GL_POSITION, light_position3);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
    glFlush();
    glutSwapBuffers();

    gazibu(putar);

}

void keyboard(unsigned char key, int putar, int y) {
    if (key == 'v' || key == 'V') {
        glutIdleFunc(putar_kanan);
    }
    if (key == 'b' || key == 'B') {
        glutIdleFunc(putar_kiri);
    }
    if (key == 'f' || key == 'F') {
        besar_tam();
    }
    if (key == 'g' || key == 'G') {
        besar_kec();
    }
    if (key == 'c' || key == 'C') {
        putar_skanan();
    }
    if (key == 'n' || key == 'N') {
        putar_skiri();
    }
    if (key == 'q' || key == 'Q') {
        exit(0);
    }

}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Tugas OpenGL Gazibu IF10 KEL2");
    glutDisplayFunc(display);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glutKeyboardFunc(keyboard);
    init();
    glutMainLoop();
    return 0;
}

