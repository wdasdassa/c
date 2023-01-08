#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<stdlib.h>
//int main()
//{
//	int i = 1;
//	do
//	{
//		printf("%d\n", i);
//		i++;
//
//
//	} while (i <= 10);//循环体至少执行一次。
//
//
//
//	return 0;
//}
//int main()//求n的阶乘
//{
//	int accumulate = 1;
//	int i = 0;
//	int n = 0;
//	scanf("%d", &n);
//	for (i = 1; i < n + 1; i++)
//	{
//		accumulate = i * accumulate;
//		
//
//	}
//	printf("%d", accumulate);
//
//
//	return 0;
//}
//int main()//计算1！+2！+3!+....+10!
//{
//	int sum = 0;
//	int accumulate = 1;
//	int i = 0;
//	for (i = 1; i < 11; i++)
//	{
//		accumulate = i * accumulate;
//		
//		sum = accumulate + sum;
//
//	}
//	printf("%d", sum);
//	return 0;
//
//}
//int main()//计算1！+2！+3!+....+10!
//{
//	int n = 0;
//	int sum = 0;
//	int accumulate = 1;
//	int i = 0;
//	for (n = 1; n < 11; n++)
//	{
//		
//		for (i = 1,accumulate = 1; i < n + 1; i++)
//		{
//			
//			accumulate = i * accumulate;//此处需要把accumulate初始化，不然accumulate会积累。
//		}                               //当accumulate算出1的阶乘后，没有初始化再进入循环
//		sum = accumulate + sum;         //如此就会积累起来1*1，1*1*1*2，1*1*1*2*1*2*3就不是需要的阶乘了
//	}                                   //for语句的嵌套要注意初始化问题。
//	printf("%d", sum);
//	return 0;
//
//}int类型自动向下取整4.4=4，4.9=4.
//int main()
//{
//	
//	int arr[] = { 0,1,2,3,4,5,6,7,8,9,11,12,13,14,15,16,17};
//	int x1 = 0;
//	int x2 = 16;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[1]);
//	for (i = 0;x1<=x2;)
//	{
//		i = (x1 + x2) / 2;
//		if (arr[i] == 10)
//		{
//			printf("找到了下标为%d\n", i);
//			break;
//		}
//		if (arr[i] > 10)
//			x2 = i-1;
//		else
//			x1 = i+1;
//		if (x2 < x1)
//		{
//			printf("找不到\n");
//			break;
//		}
//	 }
//	
//
//	return 0;
//}
//int main()
//{
//	int m = 0;
//	char arr1[] = "welcome to henan";
//	char arr2[] = "################";
//	int left = 0;
//	//int right = sizeof(arr1) / sizeof(arr1[1]) - 2;//因为字符串的末尾隐藏了一个'\n'
//	int right = 0;
//	m=	strlen(arr1)-1;// 需要将其减掉。而且元素个数比下标大一所以要减2.strlen函数计算不包括'\n',所以只需减1.
//	for (left = -1, right = m + 1; left<=right; left++, right--)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(1000);//休息一秒单位毫秒，要引用头文件#include<Windows.h>
//		system("cls");//执行系统命令的一个函数，cls清空屏幕。要引用头文件#include<stdlib.h>
//		if (left > right)
//			break;
//	}
//	return 0;
//}
//strcmp函数规定左边大于右边返回正数，左边等于右边返回0，左边小于右边返回负数。对应头文件为string.h
int main()
{
	char password[20];
	int i = 0;
	for (; i < 3; i++)
	{
		printf("请输入密码：\n");
		scanf("%s", &password);
		if (strcmp(password, "123456789wang")==0)//strcmp函数规定左边大于右边返回正数，左边等于右边返回0，左边小于右边返回负数。对应头文件为string.h
		{                                       //不能用=来比较字符串是否相等。
			printf("登陆成功\n");                //用strcmp比较字符串是否相同。
			break;
		}
		else
		{		printf("登陆失败\n");
		printf("请重新输入密码\n");
	}

	}
	if(i==3)
	printf("登陆失败，退出程序\n");


	return 0;
}