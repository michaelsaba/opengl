#include <GL/glut.h>
#include<GL/GL.h>
#include<GL/GLU.h>
#include<math.h>
void timer(int);
void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0);
}
float xpos = 0, ypos = 0,apos=0,a2pos=0;
int state = 1;

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 400, 0, 300);
	glMatrixMode(GL_MODELVIEW);
}
void plane2() {
	glColor3f(1, 1, 1);
	glBegin(GL_TRIANGLES);
	glVertex2f( 400+50 - a2pos, 215+50);
	glVertex2f( 390+50 - a2pos, 195+50);
	glVertex2f( 390+50 - a2pos, 205+50);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f( 390 + 50 - a2pos, 195+50);
	glVertex2f( 360 + 50 - a2pos, 195+50);
	glVertex2f( 360 + 50 - a2pos, 205 + 50);
	glVertex2f( 390 + 50 - a2pos, 205 + 50);
	glEnd();

	glColor3f(1, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f(	370 + 50 - a2pos, 200 + 50);
	glVertex2f( 380 + 50 - a2pos, 200 + 50);
	glVertex2f( 377 + 50 - a2pos, 210 + 50);
	glEnd();

	glColor3f(1, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f( 360 + 50 - a2pos, 195 + 50);
	glVertex2f( 355 + 50 - a2pos, 200 + 50);
	glVertex2f( 360 + 50 - a2pos, 205 + 50);
	glEnd();
}
void plane() {
	glColor3f(1,1,1);
	glBegin(GL_TRIANGLES);
	glVertex2f(apos+0, 215);
	glVertex2f(apos + 10, 195);
	glVertex2f(apos + 10, 205);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(apos + 10, 195);
	glVertex2f(apos + 40, 195);
	glVertex2f(apos + 40, 205);
	glVertex2f(apos + 10, 205);
	glEnd();

	glColor3f(1, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f(apos + 15, 200);
	glVertex2f(apos + 35, 200);
	glVertex2f(apos + 22, 210);
	glEnd();

	glColor3f(1,0,0);
	glBegin(GL_TRIANGLES);
	glVertex2f(apos + 40,195);
	glVertex2f(apos + 45,200);
	glVertex2f(apos + 40,205);
	glEnd();


}
void boat() {
	glColor3f(0.329412, 0.329412, 0.329412);
	glBegin(GL_POLYGON);
	glVertex2f(350 - xpos, 75);
	glVertex2f(425 - xpos, 75);
	glVertex2f(450 - xpos, 100);
	glVertex2f(325 - xpos, 100);
	glEnd();
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(385 - xpos, 100);
	glVertex2f(390 - xpos, 100);
	glVertex2f(390 - xpos, 150);
	glVertex2f(385 - xpos, 150);
	glEnd();
	glColor3f(0.329412, 0.329412, 0.329412);
	glBegin(GL_POLYGON);
	glVertex2i(385 - xpos, 115);
	glVertex2i(370 - xpos, 125);
	glVertex2i(385 - xpos, 135);
	glEnd();//boat1

	glColor3f(0.329412, 0.329412, 0.329412);
	glBegin(GL_POLYGON);
	glVertex2f(xpos + 25, 25);
	glVertex2f(xpos + 100, 25);
	glVertex2f(xpos + 125, 50);
	glVertex2f(xpos + 0, 50);
	glEnd();
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(xpos + 60, 50);
	glVertex2f(xpos + 65, 50);
	glVertex2f(xpos + 65, 100);
	glVertex2f(xpos + 60, 100);
	glEnd();
	glColor3f(0.329412, 0.329412, 0.329412);
	glBegin(GL_POLYGON);
	glVertex2i(xpos + 65, 65);
	glVertex2i(xpos + 75, 75);
	glVertex2i(xpos + 65, 85);
	glEnd();//boat2
}

void sun() {
	float O;
	glColor3f(0.93,0.57,0.13);
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 360; i++) {
		O = i * 3.14159 / 180;
		glVertex2f(50 + 30 * cos(O),250 + 30 * sin(O));

	}
	glEnd();
}
void sea(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.53, 0.81, 0.91);
	glBegin(GL_QUADS);
	glVertex2f(0, 150);
	glVertex2f(500, 150);
	glVertex2f(500, 500);
	glVertex2f(0, 500);
	glEnd();//sky

	glColor3f(0, 0, 205);
	glBegin(GL_QUADS);
	glVertex2d(0, 0);
	glVertex2d(500, 0);
	glVertex2d(500, 150);
	glVertex2d(0, 150);
	glEnd();//sea
	boat();
	sun();
	plane();
	plane2();
	glutSwapBuffers();

}
void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode
	glutInitWindowPosition(0,0); // Set top-left display-window position. 
	glutInitWindowSize(1000, 700); // Set display-window width and height.
	glutCreateWindow("project"); // Create display window.
	init();
	glutDisplayFunc(sea);
	glutReshapeFunc(reshape);
	glutTimerFunc(0, timer, 0);
	glutMainLoop();
}
void timer(int) {
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer, 0);
	switch (state) {
	case 1:
		if (xpos < 450) {
			xpos += 1;
			ypos += 1;
			apos += 1;
		}
		else
			state = -1;
		break;
	case -1:
		if (xpos > -50) {
			xpos -= 1;
			ypos += 1;
			a2pos += 1;
		}

		else
			state = 1;
		break;
	}
}

