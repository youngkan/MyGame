#ifndef TETRIS_H
#define TETRIS_H
#include"Common.h"

class Block
{
public:
	Block();
	virtual ~Block();
	//显示方块
	void Draw() const;
	// 判断方块是否可以跟着形状旋转到指定位置
	// 参数为该方块所属的形状的位置
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


//Figure类：游戏中使用的形状，形状由4个方块组成
class Figure
{
public:
	Figure(int numFigure);
	Figure();
	virtual ~Figure();
	//创建新的形状
	void New(int numFigure);
	//显示形状
	void Draw () const;
	//选转形状：向左旋转90度
	bool Rotate();
	//移动形状
	bool Translate(const int offsetX,const int offsetY);
	//返回方块的位置
	int GetPosX() const {return posX;}
	int GetPosY() const {return posY;}

	//设置方块的位置
	void setPosX(const int x) {posX = x;}
	void setPosY(const int y) {posY = y;}
public:
	//组成形状的方块列表
	Block data [NUM_FIGURE_BLOCK];
private:
	//形状的位置
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