#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EASY_COUNT 10
#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

void Menu();

//初始化棋盘的
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col);

//布置雷
void SetMine(char mine[ROWS][COLS], int row, int col);

//排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

//统计周围雷
int Getmine(char mine[ROWS][COLS], int x, int y);


//优化：
	//不是雷且周围没有雷展开周围以此类推且判断无雷的不重复判断
	//int A = a;
	//int B = b;
	//char count;
	//for (int i = -1; i <= 1; i++)
	//{
	//	for (int j = -1; j <= 1; j++)
	//	{
	//		count = Getmine(mine, x + i, y + j) + '0'; //转换此处的int类型为字符类型
	//		if (mine[x + i][y + j] == '0')
	//		{
	//			
	//			if (count == '0' &&  x+i>1 && x+i<ROWS-2 && y+j>1 && y+j < COLS-2)
	//			{
	//				show[x + i][y + j] = ' ';
	//				DisplayBoard(show, ROW, COL);
	//				if (!(x + i == A && y + j == B))
	//				{
	//					spread(mine, show, x + i, y + j, A, B);
	//				}
	//				
	//			}
	//			else
	//			{
	//				show[x + i][y + j] = count;
	//			}
	//		}
	//	}
	//}
	//标记雷
