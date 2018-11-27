#include <GL/freeglut.h>
#include <Windows.h>
#include <time.h>
#include <iostream>
#include <string>

int sw = 1;
int angleY = 0;
int angleX = 0;
double zoomAddition = 0;
bool depthTest = false;
bool fill = 1;
std::string projection("default");

void task1() {
	GLfloat triangles[9][3] = {
		{1, 1, 1,},
		{-1, 0, -1},
		{1, -1, 1},

		{-0.7, -0.7, 0},
		{-0.7, 0.7, 0},
		{0.7, 0, 0},

		{0, 0, -0.9},
		{-1, -0.8, 0.5},
		{1, 1, 1}
	};

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glVertexPointer(3, GL_FLOAT, 0, triangles);

	glColor3f(1, 0, 0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glColor3f(0, 1, 0);
	glDrawArrays(GL_TRIANGLES, 3, 3);
	glColor3f(0, 0, 1);
	glDrawArrays(GL_TRIANGLES, 6, 3);
}

void task3() {
	GLfloat cube[24][3] = {
		{0, 0, 0},
		{0, 0, 1},
		{1, 0, 1},
		{1, 0, 0},

		{0, 0, 0},
		{0, 0, 1},
		{0, 1, 1},
		{0, 1, 0},

		{0, 0, 0},
		{0, 1, 0},
		{1, 1, 0},
		{1, 0, 0},

		{1, 0, 1},
		{1, 1, 1},
		{1, 1, 0},
		{1, 0, 0},

		{1, 1, 1},
		{0, 1, 1},
		{0, 1, 0},
		{1 ,1, 0},

		{0, 0, 1},
		{0, 1, 1},
		{1, 1, 1},
		{1, 0, 1}
	};
	glVertexPointer(3, GL_FLOAT, 0, cube);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	if (projection == "Ortho") {
		glOrtho(-0.8, 0.8, -0.9, 0.9, 3, 8);
	}
	if (projection == "Frustum") {
		glFrustum(-0.8 , 0.8, -0.9, 0.9, 3, 8);
	}
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();

	if (projection == "Ortho") {
		glTranslatef(-0.7, -0.5, -5);
	}
	else if (projection == "Frustum") {
		glTranslatef(-0.5, -0.5, -5 + zoomAddition);
	}
	else {
		glTranslatef(-0.5, -0.5, 0.2);
	}	
	glRotatef(-15, 1, 0, 0);
	glRotatef(65, 0, 1, 0);
	/*Вращение вокруг оси*/
	glTranslatef(0.5, 0, 0.5);
	glRotatef(angleY, 0, 1, 0);
	glTranslatef(-0.5, 0, -0.5);
	glTranslatef(0, 0.5, 0.5);
	glRotatef(angleX, 1, 0, 0);
	glTranslatef(0, -0.5, -0.5);

	glColor3f(0, 0, 0);
	glDrawArrays(GL_QUADS, 0, 4);
	glColor3f(1, 0, 0);
	glDrawArrays(GL_QUADS, 4, 4);
	glColor3f(0, 1, 0);
	glDrawArrays(GL_QUADS, 8, 4);
	glColor3f(0, 0, 1);
	glDrawArrays(GL_QUADS, 12, 4);
	glColor3f(1, 1, 1);
	glDrawArrays(GL_QUADS, 16, 4);
	glColor3f(1, 1, 0);
	glDrawArrays(GL_QUADS, 20, 4);
	glPopMatrix();
}

GLvoid DrawGLScene() {
	glClearColor(0.2, 0.2, 0.2, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (depthTest) {
		glEnable(GL_DEPTH_TEST);
	}
	else {
		glDisable(GL_DEPTH_TEST);
	}
	if (fill) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	else {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}

	switch (sw) {
	case(1):
		task1();
		break;
	case(3):
		task3();
		break;
	}
	std::cout 
		<< "Depth:" << depthTest 
		<< " Task:" << sw 
		<< " Projection:" << projection 
		<< " Zoom:" << zoomAddition 
		<< " Fill:" << fill 
		<<  std::endl;
	glutSwapBuffers();
}

GLvoid ReSizeGLScene(GLsizei width, GLsizei height) {
	if (height == 0)
		height = 1;
	glViewport(0, 0, width, height);
}

void KeyboardHandler(unsigned char key, int x, int y) {
	switch (key) {
		case (27):
			exit(0);
			break;
		case (49):
			sw = 1;
			break;
		case(51):
			sw = 3;
			break;
		case(48):
			projection = "default";
			break;
		case(45):
			projection = "Ortho";
			break;
		case(61):
			projection = "Frustum";
			break;
		case('e'):
			zoomAddition += 0.05;
			break;
		case('q'):
			zoomAddition -= 0.05;
			break;
		case('f'):
			fill = !fill;
			break;
		case('a'):
			angleY += 2;
			break;
		case('d'):
			angleY -= 2;
			break;
		case('w'):
			angleX += 2;
			break;
		case('s'):
			angleX -= 2;
			break;
		case(VK_SPACE):
			depthTest = !depthTest;
			break;
		default:
			break;
	}
	DrawGLScene();
}

int main(int argc, char ** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(640, 640);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("OpenGL#4");
	glEnableClientState(GL_VERTEX_ARRAY);
	glutDisplayFunc(DrawGLScene);
	glutKeyboardFunc(KeyboardHandler);
	glutReshapeFunc(ReSizeGLScene);
	glutMainLoop();
	return 0;
}