#ifndef TETRIS_H
#define TETRIS_H
#include"Common.h"

class Block
{
public:
	Block();
	virtual ~Block();
	//��ʾ����
	void Draw() const;
	// �жϷ����Ƿ���Ը�����״��ת��ָ��λ��
	// ����Ϊ�÷�����������״��λ��
	bool CanRotate(const int figureX,const int figureY) const;
	bool Rotate(const int figureX,const int figureY) ;
	bool CanTranslate(const int offsetX,const int offsetY) const;
	bool Translate(const int offsetX, const int offsetY);
	Block & operator = (Block & other)
	{
		if(this != & other)
		{
			SetPosX(other.GetPosX());
			SetPosY(other.GetPosY());
		}
		return *this;
	}
	int GetPosX() const {return posX};
	int GetPosY() const {return posY};
	void SetPosX(const int x) {posX = x;}
	void SetPosY(const int y) {poxY = y;}
private:
	int posX,posY;
};


//Figure�ࣺ��Ϸ��ʹ�õ���״����״��4���������
class Figure
{
public:
	Figure(int numFigure);
	Figure();
	virtual ~Figure();
	//�����µ���״
	void New(int numFigure);
	//��ʾ��״
	void Draw () const;
	//ѡת��״��������ת90��
	bool Rotate();
	//�ƶ���״
	bool Translate(const int offsetX,const int offsetY);
	//���ط����λ��
	int GetPosX() const {return posX;}
	int GetPosY() const {return posY;}

	//���÷����λ��
	void setPosX(const int x) {posX = x;}
	void setPosY(const int y) {posY = y;}
public:
	//�����״�ķ����б�
	Block data [NUM_FIGURE_BLOCK];
private:
	//��״��λ��
	int posX,posY;
	bool canRotate;
};

class Game
{
private:
	int num_row,num_col;
	int map[MAX_BLOCK_NUM][MAX_BLOCK_NUM];
	bool status;

public:
	Game();
	virtual ~Game();
	void Draw() const;
	void Update(const Figure &figure);
	bool RowIsFull(const int row) const;
	void ClearRow(const int row);
	void New();
	int GetMap(const int x, const int y) const;
	bool GetStatus() const {return status;}
	void SetStatus(const bool newstatus) {status = newstatus;}
};

#endif