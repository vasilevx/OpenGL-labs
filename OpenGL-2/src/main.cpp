#include <GL/freeglut.h>
#include <Windows.h>

/*������� ��������� �����*/
GLvoid DrawGLScene() {
	/*���� ������������ ������*/
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	/*������� ������*/
	glClear(GL_COLOR_BUFFER_BIT);

	/*�������� �����������*/
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);

	/*����� � ��������*/
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

	/*n-�������� �������(solid)*/
	glLineWidth(3);
	glLineStipple(1, 0x0F0F);
	glBegin(GL_LINES);
		glVertex2f(-0.6, 0.95);
		glVertex2f(-0.6, 0.65);
		glVertex2f(-0.3, 0.95);
		glVertex2f(-0.3, 0.65);
	glEnd();

	/*n-�������� �������(dashed)*/
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

	/*���.1 ������� �����*/
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
		glutLeaveMainLoop();
}

int main(int argc, char ** argv) {
	FreeConsole();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("OpenGL#2");
	glutDisplayFunc(DrawGLScene);
	glutKeyboardFunc(KeyboardHandler);
	glutReshapeFunc(ReSizeGLScene);
	glutMainLoop();
	return 0;
}