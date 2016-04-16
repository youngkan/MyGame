#include<iostream>
#include <string>
#include "Common.h"
#include"Tetris.h"

Game::Game()
{
	num_col = (WINDOW_WIDTH)/(BLOCK_SIZE+BLOCK_SPACING);
	num_row = (WINDOW_HEIGHT)/(BLOCK_SIZE+BLOCK_SPACING);
	status = true;
}

Game::~Game()
{

}

void Game::Draw() const
{
	int i,j;
	//使用OpenGL库函数
	//draw border
	glBegin(GL_LINE_LOOP);
	glColor3f(0.5,0.2,0.1);
	glVetex3f(0,0,0);
	glVertex3f(WINDOW_WIDTH-BLOCK_SIZE/2,0,0);
	glVertex3f(WINDOW_WIDTH-BLOCK_SIZE/2,WINDOW_HEIGHT,0);
	glVertex3f(0,WINDOW_HEIGHT,0);
	glEnd();
	// draw game
	if(loseFlag==FALSE){
		struct Rectangle rect;
		for(i=0; i<num_row; ++i){
			for(j=0; j<num_col; ++j){
				if(map[i][j]){
					rect.left=j*(BLOCK_SIZE+BLOCK_SPACING)-BLOCK_SPACING;
					rect.right=rect.left+BLOCK_SIZE;
					rect.bottom=i*(BLOCK_SIZE+BLOCK_SPACING)-BLOCK_SPACING;
					rect.top=rect.bottom+BLOCK_SIZE;       
					glBegin(GL_QUADS);
					glColor3d(1,1,1);
					glVertex3f(rect.left, rect.top, 0);
					glVertex3f(rect.right, rect.top,0);
					glVertex3f(rect.right, rect.bottom, 0);
					glVertex3f(rect.left, rect.bottom, 0);
					glEnd();
				}
			}
		}
	}
	else{
		char string[]="GAME OVER";
		int len;
		glRasterPos2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
		len = (int) strlen(string);
		for (i = 0; i < len; i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
		}
	}
}

void Game::New()
{
	int i,j;
	for(i = 0;i < num_row;++i)
		for(j = 0;j < num_col;++j)
			map[i][j] = EMPTY; //empty 尚未在common头文件定义
	tetrisFigure.New(rand()%NUM_FIGURE);
	status = true;
}

void Game::Update(Figure &figure)
{
	Block *tem;
	int i,num;
	tem = figure.date;
	for(i = 0;i < 4;++i)
	{
		map[tem[i]->GetPosY()][tem[i].GetPosX()] = 1;
	}

	num = figure.GetPosY();
	for(i = num + 2;i >= num - 2;--i)
	{
		if (RowIsFull(i))
		{
			ClearRow(i);
		}
	}
}

int Game::GetMap(const int x, const int y) const
{
	if((x < 0) || ( y <0) || (x >= num_col) 
		|| (y >= num_row))
		return -1;
	else
		return map[y][x];
}

int Game::RowIsFull(int row)
{
	int i;
	if(i == 0 || row > num_row)
		return FALSE;
	for(i = 0;i < num_col;++i)
	{
		if (map[row][i] == FALSE)
		{
			return FALSE;
		}
	}
	return TRUE;
}



