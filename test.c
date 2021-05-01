#define _CRT_SECURE_NO_WARNINGS 1
#include "header.h"

void Menu()
{
	printf("**********************************\n");
	printf("**********  扫雷 简单版 **********\n");
	printf("********* 1.play  0.exit *********\n");
	printf("**********************************\n");
}

//初始化棋盘的
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	for ( i = 0; i < rows; i++)
	{
		int j = 0;
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}

	}
}

//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	printf("---------扫雷----------\n");
	int i = 0;
	for (i = 0; i <=col; i++)
	{
		printf("%d-", i);
	}
	printf("\n");
	for ( i = 1; i <= row; i++)
	{
		int j = 0;
		printf("%d|", i);
		for ( j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);

		}
		printf("\n");
	}
	printf("---------扫雷----------\n");
}

//布置雷
void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}
//统计周围雷个数只在内部使用，不在头文件声明
static int Getmine(char mine[ROWS][COLS], int x, int y)
{
	/*return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] +
		mine[x][y - 1] + mine[x][y + 1] + mine[x + 1][y - 1] + mine[x + 1][y] +
		mine[x + 1][y + 1]-8*'0';*/
	//外围八个位置的字符加起来ASCII计算 '0'-'0'=int的0 ；ASCII计算 '1'-'0'=int的1
	int count = 0;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (mine[x + i][y + j] == '1')
			{
				count++;
			}
		}
	}
	return count;
}
void spread(char mine[ROWS][COLS],char show[ROWS][COLS], int x, int y)
{
	char count;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			count = Getmine(mine, x + i, y + j) + '0'; //转换此处的int类型为字符类型
			if (mine[x + i][y + j] == '0')
			{
				
				if (count == '0' &&  x+i>0 && x+i<ROWS-1 && y+j>0 && y+j < COLS-1)
				{
					mine[x + i][y + j] = '@';//判断后要标记 以免陷入死循环
					show[x + i][y + j] = ' ';
					//DisplayBoard(show, ROW, COL);
					spread(mine, show, x + i, y + j);
				}
				else
				{
					show[x + i][y + j] = count;
				}
			}
		}
	}
}
//排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int count_for_star;
	while (1)
	{
		int x, y;
		int choice;
		while(1)
		{
			printf("1:标记雷 2:排查雷，请选择(错误输入会重新输入):>");
			scanf("%d", &choice);
			switch (choice)
			{
				case 1:
					do {
						printf("标记雷，输入坐标(错误输入会重新输入):>");
						scanf("%d %d", &x, &y);
					} while (x > 9 || y > 9);
					show[x][y] = '!';
					DisplayBoard(show, row, col);
					break;
				case 2:
					//////////////////////////////////
					do{
						printf("排查雷，输入坐标(错误输入会重新输入):>");
						scanf("%d %d", &x, &y);
					}while (x > 9 || y > 9);
					if (mine[x][y] == '1')
					{
						printf("此处为雷，失败\n");
						goto flag;
					}
					else
					{
						spread(mine, show, x, y);
						DisplayBoard(show, ROW, COL);
						count_for_star = 0;
						for (int i = 1; i <= row; i++)
						{
							for (int j = 1; j <= col; j++)
							{
								if (show[i][j] == '*'|| show[i][j] == '!')
								{
									count_for_star++;
									//printf("%d", count_for_star);
								}
							}
						}
						if (count_for_star == EASY_COUNT)
						{
							goto flag;
						}
						break;
					}
			}
		}

		
	}
	flag:printf("\n");
	if(count_for_star == EASY_COUNT)
	{
		printf("!!!!!!胜利!!!!!!\n");
	}
}