#ifndef COMMON_H
#define COMMON_H
#include<GL/glut.h>

#define NUM_FIGURE 7				//��״����
#define NUM_FIGURE_BLOCK 4			//ÿ����״��Ҫ�ķ��������
#define BLOCK_SIZE 19				//����߳�:19����
#define BLOCK_SPACING 1
#define MAX_BLOCK_SPACING 100		//��Ϸ�������������ɵķ�����
#define WINDOW_WIDTH 350			//��Ϸ����Ŀ�
#define WINDOW_HEIGHT 500			//��Ϸ����ĸ�
//�����Ϻ���������������ɵķ�����
#define NUM_BLOCKS_X WINDOW_WIDTH / (BLOCK_SIZE + BLOCK_SPACING)
#define NUM_BLOCKS_Y WINDOW_HEIGHT / (BLOCK_SIZE + BLOCK_SPACING)

//������Ϸ���map��λ������
//������λ�ò���ʾ����ʱ��Ϊ��
#define USED 1
#define  EMPTY 0

//��Ϸ����״̬

#define RUNNING 1
#define LOSE 0
// ʹ����ά���鶨��7�в�ͬ����״
// ��һά��ʾ7����ͬ����״
// �ڶ�άΪ�����״���ĸ�����
// ����άΪÿ��������������״�����ƫ����
const int image[NUM_FIGURE][NUM_FIGURE_BLOCK][2] = 
{
	{
		// 0����״
		{0,0},
		{0,1},
		{1,0},
		{1,1}		
	},
	{
		//I����״
		{0,-1},
		{0,0},
		{0,1},
		{0,2}
	},
	{
		// J����״
		{0,1},
		{-1,1},
		{-1,0},
		{-1,-1}
	},
	{
		// L����״
		{0,1},
		{1,1},
		{1,0},
		{1,-1}
	},
	{
		// S����״
		{-1,1}, 
		{-1,0}, 
		{0,0},
		{0,-1}
	},
	{
		// Z����״
		{0,1},
		{0,0},
		{-1,0},
		{-1,-1}
	},
	{
		// T����״
		{-1,0},
		{0,0},
		{1,0},
		{0,1}
	}
};
#endif

