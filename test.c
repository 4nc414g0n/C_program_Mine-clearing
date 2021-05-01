#define _CRT_SECURE_NO_WARNINGS 1
#include "header.h"

void Menu()
{
	printf("**********************************\n");
	printf("**********  ɨ�� �򵥰� **********\n");
	printf("********* 1.play  0.exit *********\n");
	printf("**********************************\n");
}

//��ʼ�����̵�
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

//��ӡ����
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	printf("---------ɨ��----------\n");
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
	printf("---------ɨ��----------\n");
}

//������
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
//ͳ����Χ�׸���ֻ���ڲ�ʹ�ã�����ͷ�ļ�����
static int Getmine(char mine[ROWS][COLS], int x, int y)
{
	/*return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] +
		mine[x][y - 1] + mine[x][y + 1] + mine[x + 1][y - 1] + mine[x + 1][y] +
		mine[x + 1][y + 1]-8*'0';*/
	//��Χ�˸�λ�õ��ַ�������ASCII���� '0'-'0'=int��0 ��ASCII���� '1'-'0'=int��1
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
			count = Getmine(mine, x + i, y + j) + '0'; //ת���˴���int����Ϊ�ַ�����
			if (mine[x + i][y + j] == '0')
			{
				
				if (count == '0' &&  x+i>0 && x+i<ROWS-1 && y+j>0 && y+j < COLS-1)
				{
					mine[x + i][y + j] = '@';//�жϺ�Ҫ��� ����������ѭ��
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
//�Ų���
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int count_for_star;
	while (1)
	{
		int x, y;
		int choice;
		while(1)
		{
			printf("1:����� 2:�Ų��ף���ѡ��(�����������������):>");
			scanf("%d", &choice);
			switch (choice)
			{
				case 1:
					do {
						printf("����ף���������(�����������������):>");
						scanf("%d %d", &x, &y);
					} while (x > 9 || y > 9);
					show[x][y] = '!';
					DisplayBoard(show, row, col);
					break;
				case 2:
					//////////////////////////////////
					do{
						printf("�Ų��ף���������(�����������������):>");
						scanf("%d %d", &x, &y);
					}while (x > 9 || y > 9);
					if (mine[x][y] == '1')
					{
						printf("�˴�Ϊ�ף�ʧ��\n");
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
		printf("!!!!!!ʤ��!!!!!!\n");
	}
}