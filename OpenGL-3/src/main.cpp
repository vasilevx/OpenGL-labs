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

	GLfloat aVertex[4][2] = {
				{-0.95, 0.95},
				{-0.5, 0.95},
				{-0.5, 0.5},
				{-0.95, 0.5}
				};
	glVertexPointer(2, GL_FLOAT, 0, aVertex);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	randomColor();
	glDrawArrays(GL_POLYGON, 0, 4);
	randomColor();
	glDrawArrays(GL_QUADS, 0, 4);
	randomColor();
	glDrawArrays(GL_TRIANGLES, 0, 4);
	randomColor();
	glDrawArrays(GL_LINES, 0, 4);

	float kx = 2.5, ky = 0.5;
	int	x = 13, y = 7, angleA = -30, angleB = 35;

	/*Масштабирование и перенос треугольника*/
	glPushMatrix();
	randomColor();
	glBegin(GL_TRIANGLES);
		glVertex2f(-0.2, 0.8);
		glVertex2f(-0.3, 0.5);
		glVertex2f(-0.1, 0.5);
	glEnd();
		
	glScalef(kx, ky, 0);
	glTranslatef(0.2, 0.5, 0);
	glBegin(GL_TRIANGLES);
		glVertex2f(-0.2, 0.8);
		glVertex2f(-0.3, 0.5);
		glVertex2f(-0.1, 0.5);
	glEnd();
	glPopMatrix();

	/*Поворот линии*/
	randomColor();
	glBegin(GL_LINES);
		glVertex2f(-0.5, -0.5);
		glVertex2f(0.5, -0.5);
	glEnd();

	glPushMatrix();
	glRotatef(angleA, 0, 0, 1);
	glBegin(GL_LINES);
		glVertex2f(-0.5, -0.5);
		glVertex2f(0.5, -0.5);
	glEnd();
	glPopMatrix();
	
	/*Поворот прямоугольника*/
	glBegin(GL_QUADS);
	randomColor();
	glVertex2f(0.5, 0.7);
	glVertex2f(0.8, 0.7);
	glVertex2f(0.8, 0.4);
	glVertex2f(0.5, 0.4);
	glEnd();

	glPushMatrix();
	glRotatef(angleB, x, y, 1);
	glBegin(GL_QUADS);
		glVertex2f(0.5, 0.7);
		glVertex2f(0.8, 0.7);
		glVertex2f(0.8, 0.4);
		glVertex2f(0.5, 0.4);
	glEnd();
	glPopMatrix();

	/*Звезда линиями*/
	glColor3f(1, 1, 1);
	for (int i = 0; i < 5; i++) {
		glRotatef(72, 0, 0, 1);
		glBegin(GL_LINES);
			glVertex2f(-0.1, 0.0);
			glVertex2f(0, 0.3);
			glVertex2f(0.1, 0.0);
			glVertex2f(0, 0.3);
		glEnd();
	}
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
}

int main(int argc, char ** argv) {
	FreeConsole();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(640, 640);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("OpenGL#3");
	/*Включение режима работы с массивом вершин*/
	glEnableClientState(GL_VERTEX_ARRAY);
	glutDisplayFunc(DrawGLScene);
	glutKeyboardFunc(KeyboardHandler);
	glutReshapeFunc(ReSizeGLScene);
	glutMainLoop();
	return 0;
}