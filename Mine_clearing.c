#define _CRT_SECURE_NO_WARNINGS 1
#include "header.h"
void game()
{
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	DisplayBoard(show, ROW, COL);
	SetMine(mine, ROW, COL);
	DisplayBoard(mine, ROW, COL);
	FindMine(mine, show, ROW, COL);
}
int main()
{
	srand((unsigned int)time(NULL));//随机布雷
	int input = 0;
	do
	{
		Menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
		case 0:
			break;
		default:
			printf("输入无效，请重新输入:>");
		}
	} while (input);
}