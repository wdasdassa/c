#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void initialboard(char board[ROWS][COLS], int row, int col, char set)
{
	int j = 0;
	int m = 0;
	
	for (j = 0; j < ROWS; j++)
		for (m = 0; m < COLS; m++)
			board[j][m] = set;

}
void displayboard(char board[ROWS][COLS], int row, int col)
{
	int j = 0;
	int m = 0;
	
	for (j = 0; j <= row; j++)
		printf("%d ", j);
	
	printf("\n");
	for (j = 1; j <= row; j++)
	{
		printf("%d ", j);
		for (m = 1; m <= col; m++)
		{
			printf("%c ", board[j][m]);	
		}
		printf("\n");
	}

}
void set_mine(char board[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = EASY_count;
	while (count)
	{
		x = rand() % row + 1;//  1<=x<=row
		y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}

}
void find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int count = 0;//最多查找的次数。
	int x = 0;
	int y = 0;
	while (count < row * col - EASY_count)//
	{
		printf("请输入要查找的坐标：");
		scanf("%d%d", &x, &y);
		if (x >= 1 && y >= 1 && x <= row && y <= col)//判断合法性。
		{

			if (mine[x][y] == '1')
			{
				printf("你被炸死了，游戏结束！\n");
				displayboard(mine, ROW, COL);
				break;
			}
			else
			{
				show[x][y] = search_mine(mine, x, y) + '0';
				displayboard(show, ROW, COL);
				count++;
			}

		}
	}
	if (count == row * col - EASY_count)
	{
		printf("恭喜扫雷成功\n");
		displayboard(mine, ROW, COL);
	}
}

