#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"

void menu()
{
	printf("******************************\n");
	printf("*****1.add         2.del *****\n");
	printf("*****3.mod         4.show ****\n");
	printf("*****5.sort        6.search **\n");
	printf("********* 0.exit *************\n");
}
int main()
{
	int input = 0;
	struct cn con;
	init(&con);
	do
	{
		menu();
		printf("请输入您的选择：\n");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			add_info(&con);
			break;
		case DEL:
			del_info(&con);
			break;
		case MODIFY:
			mod_info(&con);
			break;
		case SHOW:
			show_info(&con);
			break;
		case SORT:
			sort_info(&con);
			break;
		case SEARCH:
			search_info(&con);
			break;
		case EXIT:
			savecontact(&con);
			destorycontact(&con);
			printf("退出程序\n");
			break;
		default:
			printf("输入错误，请重新选择\n");
			break;
	    }
	} while (input);

	return 0;
}