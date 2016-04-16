#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "Common.h"
#include "Tetris.h"
#include <GL/glut.h>

using namespace std;

//��ʼ����Ҫ�ı���
//�������һ����״

Figure tetrisFigure(rand()%NUM_FIGURE);
//��Ϸ�����
Game tetrisGame;

//0penGLʹ�õĻص�����
//�������봦����
void HandleKeyPress(unsigned char key, int x, int y);
//��ʾ������
void Display(void);
//���´�����
void Update(int value);
//�������봦����
//��һ�������ǰ�����ASCII��
//ʣ�µİ�����ʱ���������꣬�����������Դ��ڵ����Ͻǵ�
void HandleKeyPress(unsigned char key, int x, int y)
{
	//���ư����������Ϸ��û��ʧ����֧�֣�
	//a����״�����ƶ�
	//s����״�����ƶ�
	//d����״�����ƶ�
	//w��������ת90��
	if(tetrisGame.GetStatus()
	{
		switch(key)
		{
		case 'a':
			tetrisFigure.Translate(-1,0);
			gluPostRedisplay();
			break;
		case 's':
			tetrisFigure.Translate(-1,0);
			gluPostRedisplay();
			break;
		case 'd':
			tetrisFigure.Translate(1,0);
			glutPostRedisplay();
			break;
		case 'w':
			tetrisFigure.Rotate();
			glutPostRedisplay();
			break;
		default:
			break;
		}
	}
	else {
		// �����Ϸ�Ѿ�ʧ�ܣ�֧�֣�
		// n����ʼ�µ���Ϸ
		switch(key){
			case 'n':
				tetrisGame.New();
				glutPostRedisplay();
				break;
			default:
				break;
		}
	}
}

//��ʾ����
void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);
	// �����Ϸû�н�����ʾ��ǰ����״
	if(tetrisGame.GetStatus())
		tetrisFigure.Draw();
	//��ʾ��Ϸ����
	tetrisGame.Draw();
	glutSwapBuffers();
}

// ���º���
void Update(int value){

	// �����Ϸû�н���
	if(tetrisGame.GetStatus()){

		// �����ƶ���״
		int moveSuccess = tetrisFigure.Translate(0, -1);
		// ����ƶ�ʧ�ܱ�ʾ��ǰ��״�Ѿ��޷���������
		// ������Ϸ״̬�������µ���״
		if(!moveSuccess){
			tetrisGame.Update(tetrisFigure);
			tetrisFigure.New(rand()%NUM_FIGURE);
		}
	}

	// ˢ����ʾ
	glutPostRedisplay();
	// ����ÿ0.5��ˢ��һ��
	glutTimerFunc(500, Update, 0);
}
// ������
int main(int argc, char **argv) {
	// ��ʼ��OpenGL
	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
	// ������Ϸ�����С�����ӵķ�Χ������ʾ�߽�
	glutInitWindowSize( WINDOW_WIDTH+100, WINDOW_HEIGHT+100);
	// ������Ϸ�����λ��
	glutInitWindowPosition( 50, 50 );
	// ������Ϸ����
	glutCreateWindow( "Tetris's Game" );
	// ��ʼ�����汳��ɫ
	glClearColor( 0.0, 0.0, 0.0, 0.0 ) ;
	glMatrixMode(GL_MODELVIEW) ;  
	glLoadIdentity(); 
	gluOrtho2D(-50, (GLdouble)WINDOW_WIDTH+50, -50, (GLdouble)WINDOW_HEIGHT+50 );
	srand(time(NULL));
	// ע����ʾ�ͼ��̴�����
	glutDisplayFunc(Display);
	glutKeyboardFunc(HandleKeyPress);
	// ����Timer�͸��º���
	glutTimerFunc(500,Update,0);

	// ������ѭ��
	glutMainLoop();
}

