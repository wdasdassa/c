#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

void game()
{
	int ret = 0;
	char board[ROW][COL] = {0};//创建一个二维数组。
	initboard(board, ROW, COL);//初始化数组。
	displayboard(board, ROW, COL);//打印棋盘。

	while (1)
	{
		playermove(board, ROW, COL);//玩家移动
		displayboard(board, ROW, COL);
		ret = iswin(board, ROW, COL);//判断输赢
		if (ret != 'c')
			break;
		computermove(board, ROW, COL);//电脑移动
		displayboard(board, ROW, COL);
		ret = iswin(board, ROW, COL);
		if (ret != 'c')
			break;
	}
	if (ret == '#')
		printf("电脑赢\n");
	if(ret=='*')
		printf("玩家赢\n");
	if (ret == 'p')
		printf("平局\n");
}

void menu()
{
	printf("****************\n");
	printf("****1.PLAY******\n");
	printf("****0.EXIT******\n");
	printf("****************\n");
}
void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do 
	{
		menu();
		printf("请输入您的选择：\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("程序退出\n");
			break;
		default:
			printf("输入错误，请重新选择\n");
			break;

		}
	} while (input);


}
int main()
{
	test();

	return 0;
}