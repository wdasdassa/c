#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

void menu()
{
	printf("**************************\n");
	printf("**********1.PLAY**********\n");
	printf("**********0.EXIT**********\n");
	printf("**************************\n");
	printf("**************************\n");
}
//创建9*9的棋盘，需要11*11的棋盘，避免读取边缘地区的地雷信息时溢出。
void game()
{   
	char mine[ROWS][COLS] = { 0 };//放置地雷。
	char show[ROWS][COLS] = { 0 };//放置计算地雷的信息。
	initialboard(mine,ROWS,COLS,'0');//初始化棋盘。
	initialboard(show, ROWS, COLS, '*');
	//displayboard(mine,ROW,COL);//打印棋盘时只需要打印9*9的大小。
	displayboard(show, ROW, COL);
	set_mine(mine,ROW,COL);//放置地雷。
	/*displayboard(mine, ROW, COL);*/
	find_mine(mine,show,ROW,COL);//找雷。在mine中找雷，并把信息传递到show中。
}
void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请输入您的选择:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("程序关闭\n");
			break;
		default:
			printf("选择无效，请重新选择！\n");
			break;
		}

			
	} while (input);
}
int main()
{
	test();
	return 0;
}