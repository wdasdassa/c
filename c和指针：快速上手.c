#define _CRT_SECURE_NO_WARNINGS
//int cal(int n)
//{
//	int j = 0;
//	int i = 0;
//	int sum = 0;
//	if (n == 2)//1不是素数.
//		return 2;
//	for (i = 2; i <= n; i++)//此处i<n+1,效果和i<=n效果一样
//	{
//		for (j = 2; j < i; j++)
//		{
//			if (i % j == 0)//如果i被整除证明i不是素数
//				break;//跳出循环
//		}
//		if (j == i)//如果j最后等于i，证明i不能被2--i-1之间的数整除，表示i是素数
//			sum =sum+i;
//	}
//	return sum;
//}
//int main()
//{
//	int sum = 0;
//	int n = 0;
//	printf("请输入一个整数n\n"); 
//	scanf("%d", &n);
//	sum=cal(n);//分装一个函数计算不大于n的素数之和
//	printf("%d", sum);
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#define MAX_COLUMNS 20
//#define MAX_NUMS 1000
//int read_colnums(int n_colums[], int max)
//{
//	int tmp = 0;
//	int i = 0;
//	int j = 0;
//	int num = 0;
//	int ch = 0;
//	while (num < max && scanf("%d", &n_colums[num]) == 1 && n_colums[num] >= 0)
//		num++;
//	if (num % 2 != 0)
//	{
//		n_colums[num] = 999;
//	}
//	while ((ch = getchar()) != EOF && ch != '\n')
//		;//会将最后一个数字小于0的数据丢弃；
//	for (i = 0; i < num; i++)
//	{
//		for(j=0;j<num-i;j++)
//			if (n_colums[j] > n_colums[j + 1])
//			{
//				tmp = n_colums[j + 1];
//				n_colums[j + 1] = n_colums[j];
//				n_colums[j] = tmp;
//			}
//	}
//
//		return num+1;
//}
//void rearrange(char* input, char* output, int n_columns[], int n_column)
//{
//	int nchars = 0;//每次复制的列数
//	int col = 0;//n_colums数组的下标
//	int output_column = 0;//计数器，计算每次开始复制的位置。
//	int len = 0;//输入字符串的长度
//	len = strlen(input);
//	for (col = 0; col < n_column; col += 2)
//	{
//		nchars = n_columns[col + 1] - n_columns[col]+1;
//		if (n_columns[col] >= len || output_column == MAX_NUMS - 1)//当output_column==MAX_NUMS-1时output+output_column此时为'\0',
//			break;//输入行结束或输出行已满就结束任务
//		if (output_column + nchars >MAX_NUMS - 1)
//			nchars = MAX_NUMS - 1 - output_column;//留下一行给'\0'
//		strncpy(output + output_column, input + n_columns[col], nchars);
//		output_column += nchars;
//
//	}
//	output[output_column] = '\0';
//}//整个程序中必须在output输出数组的最后一位修改为'\0'
//int main()
//{
//	int n_columns[MAX_COLUMNS] = { 0 };
//	char output[MAX_NUMS] = "0";
//	char input[MAX_NUMS] = "0";
//	int n_column = 0;
//	n_column = read_colnums(n_columns,MAX_COLUMNS);
//	while (fgets( input,MAX_NUMS,stdin))//用fgets函数来接收标准输入流（键盘）中输入的字符串（接收的最大数量是MAX_NUMS），存放到input，
//	{
//		printf("original :%s\n", input);
//		rearrange(input,output,n_columns,n_column);
//		printf("rearrange:%s", output);
//	}
//	return EXIT_SUCCESS;
//}

//功能是从标准输入读取几行输入，并打印到标准输出上，前面加上行号，让输入行没有长度限制
//int main()
//{
//	int ch = 0;
//	int begin =1;//记录每行的开始
//	int line = 0;
//	while ((ch = getchar() )!= EOF)
//	{
//		if (begin == 1)//如果处于每行的开始就打印行号
//		{
//			begin = 0;
//			line++;
//			printf("%d: ", line);//打印行数
//		}
//		putchar(ch);
//		if (ch=='\n')//换行
//			begin = 1;//下一个字符是这一行的开始。
//	}
//	return 0;
//}
//功能是从标准输入读取几行输入，并打印到标准输出上，前面加上行号，让输入行没有长度限制
//int main()
//{
//	int ch = 0;
//	int begin = 1;//记录每行的开始
//	int line = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		if (begin == 1)//如果处于每行的开始就打印行号
//		{
//			begin = 0;
//			line++;
//			printf("%d: ", line);//打印行数
//		}
//
//		if (!putchar(ch))//换行\n的ASCII码值是10
//			begin = 1;//下一个字符是这一行的开始。
//	}
//	return 0;
//}
//int main()
//{
//	int ch = 0;
//	signed char checksum = -1;
//	do
//	{
//		ch = getchar();
//		checksum += ch;
//
//	} while (ch != '\n');
//	printf("%d\n", checksum);
//}

//int main()
//{
//	int len1 = 0;
//	int len2 = 0;
//	char buff[1000] = "0";
//	char buff2[1000] = "0";
//	while (fgets(buff, 1000, stdin) != NULL)
//	{
//		len1 = strlen(buff);
//		len2 = strlen(buff2);
//		if (len1 >= len2)
//			strcpy(buff2, buff);
//	}
//	printf("%s", buff2);
//
//}
//int main()
//{
//	int n = 1010;
//	char* ps = (char*)malloc(n);
//
//
//}