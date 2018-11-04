#include <GL/freeglut.h>
#include <Windows.h>

/*������� ��������� �����*/
GLvoid DrawGLScene() {
	/*���� ������������ ������*/
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	/*������� ������*/
	glClear(GL_COLOR_BUFFER_BIT);

	glPointSize(2); //������ �����
	glBegin(GL_POINTS);
	glColor3d(1, 0, 0);
	glVertex3d(-0.45, -0.4, 0); // ������ �����
	glColor3d(0, 1, 0);
	glVertex3d(0.4, 0.4, 0); // ������ �����
	glColor3d(0, 0, 1);
	glVertex3d(-0.35, 0.4, 0); // ������ �����
	glEnd();

	/*����������� �������� ������ �� �����*/
	glutSwapBuffers();
}

/*������� ��������������� �����*/
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