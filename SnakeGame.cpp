#include<GL/freeglut.h>
#include "game.h"
#include<iostream>
#include<string>

#define COLUMNS 40
#define ROWS 40
#define FPS 10

extern short sDirection;
bool gameOver = false;

int score = 0;
void display();
void init();
void reshape(int, int);
void timer(int);
void keyboard(int, int, int);

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(400, 20);
	glutCreateWindow("Snake Game");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(0, timer, 0);
	glutSpecialFunc(keyboard);
	init();
	glutMainLoop();

	return 0;
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	initGrid(COLUMNS, ROWS);
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawGrid();
	drawSnake();
	drawFood();
	glutSwapBuffers();
	if (gameOver)
	{
		std::string tmp = std::to_string(score);
		char const* num_char = tmp.c_str();
		char text[50] = "Your score: ";
		strcat_s(text, num_char);
		MessageBoxA(NULL, text, "GAME OVER", 0);
		exit(0);
	}
}

void reshape(int w, int h)
{
	glViewport(0.0, 0.0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, COLUMNS, 0.0, ROWS);
	glMatrixMode(GL_MODELVIEW);

}

void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000/FPS, timer, 0);
}


void keyboard(int key, int, int)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		if (sDirection != DOWN)
			sDirection = UP;
		break;
	case GLUT_KEY_DOWN:
		if (sDirection != UP)
			sDirection = DOWN;
		break;
	case GLUT_KEY_RIGHT:
		if (sDirection != LEFT)
			sDirection = RIGHT;
		break;
	case GLUT_KEY_LEFT:
		if (sDirection != RIGHT)
			sDirection = LEFT;
		break;
	}

}
