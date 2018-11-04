#include <GL/freeglut.h>
#include <Windows.h>

/*Функция отрисовки сцены*/
GLvoid DrawGLScene() {
	/*Цвет закрашивания экрана*/
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	/*Очистка экрана*/
	glClear(GL_COLOR_BUFFER_BIT);

	glPointSize(2); //размер точки
	glBegin(GL_POINTS);
	glColor3d(1, 0, 0);
	glVertex3d(-0.45, -0.4, 0); // первая точка
	glColor3d(0, 1, 0);
	glVertex3d(0.4, 0.4, 0); // вторая точка
	glColor3d(0, 0, 1);
	glVertex3d(-0.35, 0.4, 0); // третья точка
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
		exit(0);
}

int main(int argc, char ** argv) {
	FreeConsole();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("OpenGL#1");
	glutDisplayFunc(DrawGLScene);
	glutKeyboardFunc(KeyboardHandler);
	glutReshapeFunc(ReSizeGLScene);
	glutMainLoop();
	return 0;
}