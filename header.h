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

//��ʼ�����̵�
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

//��ӡ����
void DisplayBoard(char board[ROWS][COLS], int row, int col);

//������
void SetMine(char mine[ROWS][COLS], int row, int col);

//�Ų���
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

//ͳ����Χ��
int Getmine(char mine[ROWS][COLS], int x, int y);


//�Ż���
	//����������Χû����չ����Χ�Դ��������ж����׵Ĳ��ظ��ж�
	//int A = a;
	//int B = b;
	//char count;
	//for (int i = -1; i <= 1; i++)
	//{
	//	for (int j = -1; j <= 1; j++)
	//	{
	//		count = Getmine(mine, x + i, y + j) + '0'; //ת���˴���int����Ϊ�ַ�����
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
	//�����
