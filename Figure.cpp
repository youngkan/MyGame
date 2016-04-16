#include"Tetris.h"
#include "Common.h"
#include <stdio.h>
#include <time.h>

extern Game tetrisGame;
Figure::Figure()
{
	int numFigure = rand()%NUM_FIGURE;					//��ȡ�����״
	New(numFigure);										//������״
}


//����ָ������״
Figure::Figure(int numFigure)
{
	New(numFigure);
}

Figure::~Figure()
{

}

//��ʾ��״����ʾ��״�е�ÿ������
void Figure::Draw() const
{
	int i;
	for(i = 0;i < NUM_FIGURE_BLOCK;++i)
	{
		data[i].Draw();
	}
}

//�����µ���״
void Figure::New(int numFigure)
{
	int i;
	//�����������״��ϵͳ֧�ֵ���״
	if(numFigure >= 0 && numFigure < NUM_FIGURE)
	{
		//�������0����״������ת
		canRotate = (numFigure != 0);
		//��������״��ʼ״̬Ϊ��������
		posX = NUM_BLOCKS_X/2;
		posY = NUM_BLOCKS_Y/2;

		//�ж��Ƿ����㹻�Ŀռ䴴������״�����û������Ϸ����
		if(tetrisGame.GetMap(posX,posY + 1) == 1
			&& tetrisGame.GetStatus())
		{
			tetrisGame.SetStatus(false);
			return;
		}
		//�ֱ����������״��ÿ�������λ��
		for(i = 0;i < NUM_FIGURE_BLOCK;++i)
		{
			data[i].SetPosX(posX + image[numFigure][i][0]);
			data[i].SetPosY(posY + image[numFigure][i][1]);
		}
	}	
}

//������ת��״
bool Figure::Rotate()
{
	int i;
	//�����������ת�򷵻�False
	if(!canRotate)
		return false;
	//�����ж�ÿ�������Ƿ�����ƶ�����ת���λ��
	for(i = 0;i < 4;++i)
	{
		//���κ�һ�����鲻�����ƶ��򷵻�false
		if(!data[i].CanRotate(posX,posY))
		{
			return false;
		}		
	}
	
	//��ת��״���ƶ�ÿ�����鵽ָ��λ��
	for(i = 0;i < 4;++i)
	{
		data[i].Rotate(posX,posY);
	}
	return true;
}


//һ����״һ����λ��
bool Figure::Translate(const int offsetX, const int offsetY)
{
	int i;
	//�����ж�ÿ�������Ƿ�����ƶ���ָ��λ��
	for(i = 0;i < 4;++i)
	{
		if(!data[i].CanTranslate(offsetX,offsetY))
			return false;
	}
	//�ֱ��ƶ�ÿ������
	for(i = 0;i < 4;++i)
	{
		data[i].Translate(offsetX,offsetY);
	}
	//�����µ�λ��
	setPosX(posX + offsetX);
	setPosY(posY + offsetY);
	return true;
}




