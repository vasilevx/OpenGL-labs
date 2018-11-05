#include <GL/freeglut.h>
#include <Windows.h>
#include <time.h>

void randomColor() {
	glColor3ub(rand() % 255, rand() % 255, rand() % 255);
}

/*Функция отрисовки сцены*/
GLvoid DrawGLScene() {
	/*Цвет закрашивания экрана*/
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	/*Очистка экрана*/
	glClear(GL_COLOR_BUFFER_BIT);

	/*Включаем сглаживание*/
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POLYGON_SMOOTH);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	/*Точки в вершинах*/
	glPointSize(10);
	glBegin(GL_POINTS);
		glColor3f(1, 0, 0);
		glVertex2f(-0.95, 0.95);
		glColor3f(0, 1, 0);
		glVertex2f(-0.65, 0.95);
		glColor3f(0, 0, 1);
		glVertex2f(-0.95, 0.65);
		glColor3f(1, 1, 1);
		glVertex2f(-0.65, 0.65);
	glEnd();

	/*n-угольник линиями(solid)*/
	glLineWidth(3);
	glLineStipple(1, 0x0F0F);
	glBegin(GL_LINES);
		glVertex2f(-0.6, 0.95);
		glVertex2f(-0.6, 0.65);
		glVertex2f(-0.3, 0.95);
		glVertex2f(-0.3, 0.65);
	glEnd();

	/*n-угольник линиями(dashed)*/
	glEnable(GL_LINE_STIPPLE);
	glLineWidth(10);
	glLineStipple(1, 0x0F0F);
	glBegin(GL_LINES);
		glColor3f(0.5, 0.3, 0.3);
		glVertex2f(-0.6, 0.95);
		glVertex2f(-0.3, 0.95);
		glVertex2f(-0.6, 0.65);
		glVertex2f(-0.3, 0.65);
	glEnd();
	glDisable(GL_LINE_STIPPLE);

	/*Рис.1 ломаная линия*/
	glLineWidth(1);
	glBegin(GL_LINE_STRIP);
		glColor3f(1, 1, 1);
		glVertex2f(-0.2, 0.95);
		glVertex2f(0.4, 0.95);
		glVertex2f(0, 0.85);
		glVertex2f(0.5, 0.75);
		glVertex2f(-0.2, 0.75);
		glVertex2f(0, 0.6);
		glVertex2f(-0.2, 0.45);
	glEnd();

	/*Рис.2 замкнутая линия*/
	glBegin(GL_LINE_LOOP);
		glColor3f(0.7, 0.7, 0.7);
		glVertex2f(-0.9, 0.4);//1
		glVertex2f(-0.5, 0.4);//2
		glVertex2f(-0.4, 0.2);//3
		glVertex2f(-0.4, -0.1);//4
		glVertex2f(-0.55, -0.2);//5
		glVertex2f(-0.6, 0.1);//6
		glVertex2f(-0.9, -0.2);//7
		glVertex2f(-0.85, 0.2);//8
		glVertex2f(-0.95, 0.3);//9
	glEnd();

	/*Рис.2 треугольники*/
	srand((unsigned int)time(0));
	glBegin(GL_TRIANGLES);
		randomColor();
		glVertex2f(-0.9 + 0.6, 0.4);
		glVertex2f(-0.5 + 0.6, 0.4);
		glVertex2f(-0.95 + 0.6, 0.3);
		randomColor();
		glVertex2f(-0.5 + 0.6, 0.4);
		glVertex2f(-0.95 + 0.6, 0.3);
		glVertex2f(-0.85 + 0.6, 0.2);
		randomColor();
		glVertex2f(-0.5 + 0.6, 0.4);
		glVertex2f(-0.85 + 0.6, 0.2);
		glVertex2f(-0.9 + 0.6, -0.2);
		randomColor();
		glVertex2f(-0.5 + 0.6, 0.4);
		glVertex2f(-0.9 + 0.6, -0.2);
		glVertex2f(-0.6 + 0.6, 0.1);
		randomColor();
		glVertex2f(-0.5 + 0.6, 0.4);
		glVertex2f(-0.6 + 0.6, 0.1);
		glVertex2f(-0.55 + 0.6, -0.2);
		randomColor();
		glVertex2f(-0.5 + 0.6, 0.4);
		glVertex2f(-0.55 + 0.6, -0.2);
		glVertex2f(-0.4 + 0.6, -0.1);
		randomColor();
		glVertex2f(-0.5 + 0.6, 0.4);
		glVertex2f(-0.4 + 0.6, -0.1);
		glVertex2f(-0.4 + 0.6, 0.2);
	glEnd();

	/*Рис.2 лента треугольников*/
	glShadeModel(GL_FLAT);
	glBegin(GL_TRIANGLE_STRIP);
		randomColor();
		glVertex2f(-0.9 + 1.2, 0.4);
		glVertex2f(-0.95 + 1.2, 0.3);
		glVertex2f(-0.5 + 1.2, 0.4);	
		randomColor();
		glVertex2f(-0.85 + 1.2, 0.2);
		randomColor();
		glVertex2f(-0.9 + 1.2, -0.2);
		glVertex2f(-0.5 + 1.2, 0.4);
		randomColor();
		glVertex2f(-0.6 + 1.2, 0.1);
		glVertex2f(-0.5 + 1.2, 0.4);
		randomColor();
		glVertex2f(-0.55 + 1.2, -0.2);
		glVertex2f(-0.5 + 1.2, 0.4);
		randomColor();
		glVertex2f(-0.4 + 1.2, -0.1);
		glVertex2f(-0.5 + 1.2, 0.4);
		randomColor();
		glVertex2f(-0.4 + 1.2, 0.2);
	glEnd();

	/*Рис.2 веер треугольников*/
	glShadeModel(GL_SMOOTH);
	glBegin(GL_TRIANGLE_FAN);
		randomColor();
		glVertex2f(-0.5, 0.4 - 0.7);
		glVertex2f(-0.9, 0.4 - 0.7);
		glVertex2f(-0.95, 0.3 - 0.7);
		randomColor();
		glVertex2f(-0.85, 0.2 - 0.7);
		randomColor();
		glVertex2f(-0.9, -0.2 - 0.7);
		randomColor();
		glVertex2f(-0.6, 0.1 - 0.7);
		randomColor();
		glVertex2f(-0.55, -0.2 - 0.7);
		randomColor();
		glVertex2f(-0.4, -0.1 - 0.7);
		randomColor();
		glVertex2f(-0.4, 0.2 - 0.7);
	glEnd();

	/*Правильный n-угольник как 4-угольник*/
	glBegin(GL_QUADS);
		randomColor();
		glVertex2f(-0.3, -0.3);
		glVertex2f(0.2, -0.3);
		glVertex2f(0.2, -0.8);
		glVertex2f(-0.3, -0.8);
	glEnd();

	/*Рис.3 многоугольниками*/
	glPointSize(4);
	glPolygonMode(GL_FRONT, GL_POINT);
	glBegin(GL_QUADS);
		randomColor();
		glVertex2f(0.3, -0.3);
		glVertex2f(0.9, -0.35);
		glVertex2f(0.9, -0.5);
		glVertex2f(0.35, -0.5);
		randomColor();
		glVertex2f(0.9, -0.5);
		glVertex2f(0.67, -0.5);
		glVertex2f(0.67, -0.75);
		glVertex2f(0.9, -0.8);
	glEnd();
	glPolygonMode(GL_BACK, GL_LINE);
	glBegin(GL_POLYGON);
		randomColor();
		glVertex2f(0.67, -0.75);
		glVertex2f(0.9, -0.8);
		glVertex2f(0.6, -0.88);
		glVertex2f(0.35, -0.88);
		glVertex2f(0.55, -0.75);
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLES);
		randomColor();
		glVertex2f(0.35, -0.88);
		glVertex2f(0.55, -0.75);
		glVertex2f(0.45, -0.6);
	glEnd();
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
		glutLeaveMainLoop();
}

int main(int argc, char ** argv) {
	FreeConsole();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(640, 640);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("OpenGL#2");
	glutDisplayFunc(DrawGLScene);
	glutKeyboardFunc(KeyboardHandler);
	glutReshapeFunc(ReSizeGLScene);
	glutMainLoop();
	return 0;
}