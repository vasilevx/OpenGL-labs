#include <GL/freeglut.h>
#include <Windows.h>
#include <time.h>
#include <iostream>

int sw = 1;
bool depthTest = false;

void randomColor() {
	glColor3ub(rand() % 255, rand() % 255, rand() % 255);
}

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

	glVertexPointer(3, GL_FLOAT, 0, triangles);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glColor3f(1, 0, 0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glColor3f(0, 1, 0);
	glDrawArrays(GL_TRIANGLES, 3, 3);
	glColor3f(0, 0, 1);
	glDrawArrays(GL_TRIANGLES, 6, 3);
}

void task3() {
	glOrtho(-0.8, 0.8, -0.9, 0.9, 3, 8);
	GLfloat cube[24][3] = {
		{-0.5, -0.5, -0.5},
		{-0.5, 0.5, -0.5},
		{0.5, 0.5, -0.5},
		{0.5, -0.5, -0.5},

		{0.5, -0.5, 0.5},
		{0.5, 0.5, 0.5},
		{-0.5, 0.5, 0.5},
		{-0.5, -0.5, 0.5},

		{0.5, -0.5, -0.5},
		{0.5, 0.5, -0.5},
		{0.5, 0.5, 0.5},
		{0.5, -0.5, 0.5},

		{-0.5, -0.5, 0.5},
		{-0.5, 0.5, 0.5},
		{-0.5, 0.5, -0.5},
		{-0.5, -0.5, -0.5},

		{0.5, 0.5, 0.5},
		{0.5, 0.5, -0.5},
		{-0.5, 0.5, -0.5},
		{-0.5, 0.5, 0.5},

		{0.5, -0.5, 0.5},
		{0.5, -0.5, 0.5},
		{-0.5, -0.5, 0.5},
		{-0.5, -0.5, -0.5}
	};

	glVertexPointer(3, GL_FLOAT, 0, cube);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	randomColor();
	glDrawArrays(GL_POLYGON, 0, 4);

	randomColor();
	glDrawArrays(GL_POLYGON, 4, 4);

	randomColor();
	glDrawArrays(GL_POLYGON, 8, 4);

	randomColor();
	glDrawArrays(GL_POLYGON, 12, 4);

	randomColor();
	glDrawArrays(GL_POLYGON, 16, 4);

	randomColor();
	glDrawArrays(GL_POLYGON, 20, 4);

}

/*Функция отрисовки сцены*/
GLvoid DrawGLScene() {
	/*Цвет закрашивания экрана*/
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	/*Очистка буферов глубины и цвета*/
	/*Включение буфера глубины*/
	if (depthTest) {
		glEnable(GL_DEPTH_TEST);
	}
	else {
		glDisable(GL_DEPTH_TEST);
	}
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	switch (sw) {
	case(1):
		task1();
		break;
	case(3):
		task3();
		break;


	}

	std::cout << "DEPTH:" << depthTest << " sw:" << sw << std::endl;







	/*Копирование скрытого буфера на экран*/
	glutSwapBuffers();
}

/*Функция масштабирования сцены*/
GLvoid ReSizeGLScene(GLsizei width, GLsizei height) {
	if (height == 0)
		height = 1;
	glViewport(0, 0, width, height);
}

void KeyboardHandler(unsigned char key, int x, int y) {
	if (key == 27)
		exit(0);
	if (key == 49) {
		sw = 1;
	}
	if (key == 51) {
		sw = 3;
	}
	if (key == VK_SPACE) {
		depthTest = !depthTest;
	}
	DrawGLScene();

}

int main(int argc, char ** argv) {
	//FreeConsole();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(640, 640);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("OpenGL#4");
	/*Включение режима работы с массивом вершин*/
	glEnableClientState(GL_VERTEX_ARRAY);
	glutDisplayFunc(DrawGLScene);
	glutKeyboardFunc(KeyboardHandler);
	glutReshapeFunc(ReSizeGLScene);
	glutMainLoop();
	return 0;
}