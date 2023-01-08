#define _CRT_SECURE_NO_WARNINGS
#include "game.h" 

void initboard(char board[ROW][COL], int row, int col)
{
	int a = 0;
	int b = 0;
	for (a = 0; a < row; a++)
	{
		for (b = 0; b < col; b++)
			board[a][b] = ' ';//棋盘初始化为空格。空格打印是空白，美观。

	}

 
}
void displayboard(char board[ROW][COL], int row, int col)
{
	int j = 0;
	int k = 0;
	for (j = 0; j < row; j++)
	{
		for (k = 0; k < col; k++)
		{
			printf(" %c ", board[j][k]);
			if (k < col - 1)
				printf("|");
		}
		printf("\n");
		if (j < row-1)
		{
			for (k = 0; k < col; k++)
			{
				printf("___");
				if (k < col - 1)
				printf("|");

			}
		}
		printf("\n");
	}
	
}//棋盘构建。
void playermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家落子\n");
	printf("请选择落子位置\n");
	while(1)
	{
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row &&y>=1&&y<=col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
		}
		else
			printf("落子不合法,请重新输入\n");

	}

}
void computermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
//char iswin(char board[ROW][COL], int row, int col)
//{
//	
//	int d = 0;
//	for (d = 0; d < row; d++)
//	{ 
//		if (board[d][0] == board[d][1] && board[d][1] == board[d][2] && board[d][0] != ' ')
//			return board[d][0];
//
//		if (board[0][d] == board[1][d] && board[1][d] == board[2][d] && board[0][d] != ' ')
//			return board[0][d];
//	}
//	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
//		return board[0][0];
//	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
//		return board[0][d];
//	full(board, row, col);//最后再判断是否平局或棋盘是否已满。
//}
char iswin(char board[ROW][COL], int row, int col)
{
	int count = 0;
	int m = 0;
	int d = 0;
	for (d = 0; d < row; d++)
	{
		
		for (m = 0; m < col-1; m++)
		{
			if (board[d][m] != board[d][m + 1])
				break;
			
		}
		if (m == col - 1&&board[d][m]!=' ')
			return board[d][m];
	}
	for (d = 0; d < row; d++)
	{
		
		for (m = 0; m < col - 1; m++)
		{
			if (board[m][d] != board[m+1][d])
				break;
		}
		if ((m== col - 1) && board[d][m] != ' ')
			return board[m][d];
	}
	for (d = 0, m = 0; d < row - 1 && m < col - 1; d++, m++)
	{
		if (board[d][m] != board[d + 1][m + 1])
			break;
	}
	if (d == row - 1 && m == col - 1&& board[d][m] != ' ')
		return board[d][m];
	for (d = row, m = col; d > 0 && m > 0; d--, m--)
	{
		if (board[d][m] != board[d - 1][m - 1])
			break;
	}
	if (d == 1&& m == 1 && board[d][m] != ' ')
		return board[d][m];
	full(board, row, col);//最后再判断是否平局或棋盘是否已满。
}
char full(char board[ROW][COL], int row, int col)
{
	int a = 0;
	int u = 0;
	for (u = 0; u < row; u++)
	{
		for (a = 0; a < col; a++)
		{
			if (board[u][a] == ' ')
				return  'c';
		}
	}
	return 'p';
  }