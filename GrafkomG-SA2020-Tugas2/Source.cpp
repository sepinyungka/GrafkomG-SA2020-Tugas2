#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <GL/freeglut.h>

double rad = 0;

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 0.0); //MATAHARI
	glBegin(GL_POLYGON);
	for (int i = 0; i < 100; i++) {
		double x = 50 * cos(2 * M_PI * i / 100);
		double y = 50 * sin(2 * M_PI * i / 100);
		glVertex2d(x, y);
	}
	glEnd(); 

	glColor3f(1.0, 1.0, 1.0); //ORBIT MERKURIUS
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 100; i++) {
		double x = 100 * cos(2 * M_PI * i / 100);
		double y = 100 * sin(2 * M_PI * i / 100);
		glVertex2d(x, y);
	}
	glEnd();

	glColor3f(0.7, 0.7, 0.7);
	glBegin(GL_POLYGON); //MERKURIUS
	for (int i = 0; i < 100; i++) {
		double x = 10 * cos(2 * M_PI * i / 100); //gede planet ke samping = 10
		double y = 10 * sin(2 * M_PI * i / 100); // gede planet ke atas =10
		glVertex2d(sin(rad * 5) * 100 + x, cos(rad * 5) * 100 + y); // jarak mutarnya = 100, kecepatan =5 
	}
	glEnd();

	glColor3f(1.0, 1.0, 1.0); //ORBIT VENUS
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 100; i++) {
		double x = 180 * cos(2 * M_PI * i / 100);
		double y = 180 * sin(2 * M_PI * i / 100);
		glVertex2d(x, y);
	}
	glEnd();

	glColor3ub(238, 203, 139);
	glBegin(GL_POLYGON); //VENUS
	for (int i = 0; i < 100; i++) {
		double x = 20 * cos(2 * M_PI * i / 100); //gede planet ke samping = 20
		double y = 20 * sin(2 * M_PI * i / 100); // gede planet ke atas = 20
		glVertex2d(sin(rad * 4) * 180 + x, cos(rad * 4) * 180 + y); // jarak mutarnya = 180, kecepatan =4 
	}
	glEnd();

	glColor3f(1.0, 1.0, 1.0); //ORBIT BUMI
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 100; i++) {
		double x = 250 * cos(2 * M_PI * i / 100);
		double y = 250 * sin(2 * M_PI * i / 100);
		glVertex2d(x, y);
	}
	glEnd();

	glColor3ub(140, 177, 222);
	glBegin(GL_POLYGON); //BUMI
	for (int i = 0; i < 100; i++) {
		double x = 25 * cos(2 * M_PI * i / 100); //gede planet ke samping = 25
		double y = 25 * sin(2 * M_PI * i / 100); // gede planet ke atas = 25
		glVertex2d(sin(rad * 2) * 250 + x, cos(rad * 2) * 250 + y); // jarak mutarnya = 250, kecepatan =2 
	}
	glEnd();

	glColor3f(1.0, 1.0, 1.0); //ORBIT MARS
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 100; i++) {
		double x = 320 * cos(2 * M_PI * i / 100);
		double y = 320 * sin(2 * M_PI * i / 100);
		glVertex2d(x, y);
	}
	glEnd();

	glColor3ub(233, 150, 122);
	glBegin(GL_POLYGON); //MARS
	for (int i = 0; i < 100; i++) {
		double x = 28 * cos(2 * M_PI * i / 100); //gede planet ke samping = 28
		double y = 28 * sin(2 * M_PI * i / 100); // gede planet ke atas = 28
		glVertex2d(sin(rad * 1) * 320 + x, cos(rad * 1) * 320 + y); // jarak mutarnya = 320, kecepatan = 1 
	}
	glEnd();

	glutSwapBuffers();
}

void myinit() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500, 500, -500, 500);
}

void Timer(int) {
	rad += 0.01f;
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, Timer, 1);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("TUGAS2 ASDOS");
	glutTimerFunc(1000 / 60, Timer, 1);
	glutDisplayFunc(display);

	myinit();
	glutMainLoop();

	return 0;
}