#include "Common.h"
#include "Tetris.h"
extern Game tetrisGame;
Block::Block()
{
	posX = NUM_BLOCKS_X/2;
	posY = NUM_BLOCKS_Y-1;
}
Block::~Block()
{

}

void Block::Draw() const
{
	int leftPos = posX * (BLOCK_SIZE + BLOCK_SPACING) - BLOCK_SPACING;
	int rightPos = leftPos + BLOCK_SIZE;
	int bottomPos = posY * (BLOCK_SIZE + BLOCK_SPACING) - BLOCK_SPACING;
	int topPos = bottomPos + BLOCK_SIZE;

	//����OpenGL�⺯����ʾ����
	glBegin(GL_QUADS);
	glColor3d(1,1,1);
	glVertex3f(left, top, 0);
	glVertex3f(right, top, 0);
	glVertex3f(right, bottom, 0);
	glVertex3f(left, bottom, 0);
	glEnd();
}

//�жϷ����Ƿ���Ը�����״��ת��ָ��λ��
bool Block::CanRotate(const int figureX,const int figureY) const
{
	// ����λ������״λ�õ�λ��
	int offsetX = posX - figureX;
	int offsetY = posY - figureY;
	// �������λ�ü�Ϊ��״λ�ã�����ת��״����Ҫ��������λ��
	if(!offsetX && !offsetY)
	{
		return true;
	}
	// ������ת90�ȵ���λ��
	int nextPosX = figureX -offsetY;
	int nextPoxY = figureY +offsetX;
    // Ŀ��λ���Ѿ��з��飬�򷵻�False
	if (Game::GetMap(nextPosX,nextPoxY) != EMPTY)
	{
		return false;
	}
	// ��ʱ�����洢��ת�����о���������
	int tmpX[3],tmpY[3];
	// �ֱ�Բ�ͬ�������ת��������������ж�
	// ��Ҫ��֤��Щ����û�з���ſ�����ת
	// tmpX[0]��tmpY[0]�ֱ�Ϊ��ת��������߼��ϱ����ﵽ����Զ����
	tmpX[0] = figureX + offsetX - offsetY;
	tmpY[0] = figureY + offsetX + offsetY;
	if(abs(offsetX) > 1 || abs(offsetY > 1))
	{
		// �����ת��ΪI����״����Ϊ����״λ�þ�����Զ�ķ���
		// (tmpX[1], tmpY[1])��(tmpX[2], tmpY[2])Ϊ������ת�����о���������
		tmpX[1]=(tmpX[0]+posX)/2;
		tmpX[2]=(tmpX[0]+figureX-offsetY)/2;
		tmpY[1]=(tmpY[0]+posY)/2;
		tmpY[2]=(tmpY[0]+figureY+offsetX)/2;

		// �������������λ���з������޷���ת
		if(tetrisGame.GetMap(tmpX[1],tmpY[1])!=EMPTY || 
			tetrisGame.GetMap(tmpX[2], tmpY[2])!=EMPTY)
			return false;
	} else if(abs(offsetX)==1 && abs(offsetY)==1) {
		// �����������״λ��45������
		// (tmpX[1], tmpY[1])Ϊ������ת�����о���������
		tmpX[1]=(tmpX[0]+posX)/2;
		tmpY[1]=(tmpY[0]+posY)/2;

		// ���(tmpX[1], tmpY[1])����λ���з������޷���ת
		if(tetrisGame.GetMap(tmpX[1],tmpY[1])!=EMPTY)
			return false;
	} else if(tetrisGame.GetMap(tmpX[0], tmpY[0])!=EMPTY)
		// �����������״����
		// tmpX[0], tmpY[0]Ϊ������ת�����о���������
		return false;

	return true;

}

// ��ת��״�������ƶ���Ŀ��λ��
bool Block::Rotate(const int figureX,const int figureY)
{
	int offsetX = posX - figureX;
	int offsetY = posY - figureY;
	// ����������ƶ����򷵻�False
	if(!CanRotate(figureX, figureY))
	{
		return false;
	}
	// ���Ŀ��λ�ò��ƶ����鵽Ŀ��λ��
	int nextPosX,nextPosY;
	nextPosX = figureX - offsetY;
	nextPosY = figureY + offsetX;
	SetPosX(nextPosX);
	SetPosY(nextPosY);
	return true;
}
// �ƶ�����λ��
bool Block::Translate(const int offsetX, const int offsetY)
{
	// ���Ŀ��λ��
	int nextPosX = posX + offsetX;
	int nextPosY = posY + offsetY;
	// Ŀ��λ���Ѿ��з��飬�򷵻�False
	if(Game::GetMap(nextPosX,nextPosY) != EMPTY)
	{
		return false;
	}
	SetPosX(nextPosX);
	SetPosY(nextPosY);
	// �ƶ����鵽Ŀ��λ��
	return true;
}
// �жϷ����Ƿ�����ƶ�
bool Block::CanTranslate(const int offsetX,const int offsetY) const
{
	// ���Ŀ��λ��
	int nextPosX = posX + offsetX;
	int nextPosY = posY + offsetY;
	// Ŀ��λ���Ѿ��з��飬�򷵻�False
	if(Game::GetMap(nextPosX,nextPosY) != EMPTY)
		return false;
	return true;
}

