#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//int main()
//{
//	char arr[] = "abcdef";
//	char* p = arr;
//	printf("%s\n", arr);//abcdef
//	printf("%s\n", p);//abcdef
//	return 0;
//}
//int main()
//{
//	const char* p ="abcdef";//"abcdef"是常量字符串,
//	*p = 'w';         //常量字符串,无法被修改。
//	printf("%c\n", *p);//a，p中存入的是首元素的地址/
//	printf("%s\n", p);//abcdef
//
//	return 0;
//}
//int main()
//{
//	char arr1[] = "abcd";
//	char arr2[] = "abcd";
//	const char* p1 = "abcd";
//	const char* p2 = "abcd";
//	printf("%p\n", arr1);//0000009BF48FFBE4
//	printf("%p\n", arr2);//0000009BF48FFC04
//	printf("%p\n", &p1);//0000001D021EF8D8 p1的地址
//	printf("%p\n", &p2);//0000001D021EF8F8 p2的地址
//	printf("%p\n", p1);//0000000000000061  p1存放的地址 
//	printf("%p\n", p2);//0000000000000061  p2存放的地址
//	因为"abcd"是常量字符串，所以为了节省空间，p1存放的地址和p2存放的地址是相同的
//	arr1和arr2的地址不同，p1和p2的地址不相同，p1和p2存放的地址也相同
//	return 0;
//}
//指针数组，存放指针的数组
//int main()
//{
//	int j = 0;
//	int i = 0;
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//	int* parr[] = { arr1,arr2,arr3 };//指针数组
//	for (i = 0; i < 3; i++)
//	{
//		j = 0;
//		for (j = 0; j < 5; j++)
//			printf("%d ", *(parr[i] + j));
//		printf("\n");
//	}
//	return 0;
//}
//数组指针；指向数组的指针
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int (* p)[10]= & arr;//&arr是整个数组的地址。*p是指针，int[10]是数组，就是指向数组的指针。数组指针。
//	//int *p[10]//[]的优先级高于*，p先和[10]结合，是一个数组，int*p[10]是指针数组
//
//
//
//	return 0;
//}
//int main()
//{
//	char* arr[5];
//	char*(* pa)[5] = &arr;
//
//	return 0;
//}
//void print1(int arr[3][5], int x, int y)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < x; i++)
//	{
//		for (j = 0; j < y; j++)
//			printf("%d", arr[i][j]);
//		printf("\n");
//	}
//}
//void print2(int(*p)[5], int x, int y)
//{
//	int j = 0;
//	int i = 0;
//	for (i = 0; i < x; i++)
//	{
//		for (j = 0; j < y; j++)
//		{
//			////printf("%d ", (*(p + i))[j]);
//			printf("%d ", p[i][j]);//p存入的是第一行一维数组的地址，p[i]相当于p+i；即从第一个数组跳过i个数组,即第i+1行的一维数组
//		}                          //p存入的是第一行一维数组的地址，将p看成一个数组，p[0]是第一行一维数组的地址,p[1]是第二行一维数组的地址,以此类推
//		printf("\n");              //p[i][j],就是第i+1行，第j+1个元素
//	}                              //将arr存入p中，p就相当于arr，将arr看成一维数组，p[i]相当于arr[i]，就是第i+1行的一维数组，arr[i]是数组名，arr[i][j],就是数组arr[i]中的第j+1的元素。
//}
//void print3(int(*p)[5], int x, int y)
//{
//	int j = 0;
//	int i = 0;
//	for (i = 0; i < x; i++)
//	{
//		for (j = 0; j < y; j++)
//			printf("%d ", *(*(p + i) + j));//p是arr[3][5]的第1行一维数组的地址，p+1，跳过一个数组。*(p+i)相当于arr[3][5]的第(i+1)行一维数组，数组名又是首元素的地址。
//		                                   //数组名+j，是找数组的j+1元素的地址。*(*(p+i)+j),是*(数组名+j)
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
//	//print1(arr, 3, 5);//arr是数组名，数组名是首元素的地址，对于二维数组来说，先将二维数组想像为一维数组，即每行是一个元素，arr[3][5]就有三个元素。
//	                  //那么首元素地址就是，第一行的地址即第一行一维数组的地址。而不是第一行第一个元素的地址。
//	                  //二维数组的首元素地址就是第一行一维数组的地址。 
//	//print2(arr, 3, 5);
//	//print3(arr, 3, 5);
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = arr;
//	int(*pd)[10] = &arr;
//	for (i = 0; i < 10; i++)
//	{
//		//printf("%d ", arr[i]);
//		//printf("%d ", p[i]);
//		//printf("%d ", *(*pd + i));
//		//printf("%d ", (*pd)[i]);
//		//printf("%d ", *(p+i)); 
//		//五种方法都相同 *(p+i)相当于p[i].
//	}
//
//	return 0;
//}
//int main()
//{
//	int arr[5];//arr一个数组，数组中有五个元素，每个元素的类型是int
//	int* parr; //parr一个指针，指向的元素的类型是int
//	int(*parr1)[5];//parr1一个数组指针，指向的一个数组有五个元素，每个元素的类型是int
//	int(* parr2[10])[5];//parr2一个有10个元素的数组，每个元素都是一个数组指针，指向的一个数组有5个元素，每个元素的类型是int
//	//除去数组名和[],其余的是数组中元素的类型。例int(*parr2[10])[5];元素的类型是int(*)[5];//数组指针指向一个有5个int类型元素的数组 
//
//	return 0;
//}
//一维数组传参。
//void test1(int arr1[5])//传入的是数组，用一个数组来接收。[]内可以不写，可以写与传入数组相同的元素个数，也可以写错（避免写错）。
//{}
//void test1(int* arr)//数组名是首元素的地址，可以用int* 来接收。
//{}
//void test2(int* arr[10])//传入的是数组，用数组接收。
//{}
//void test2(int* *arr)//数组名是首元素的地址，可以用int** 来接收。元素的类型是int*
//{}
//int main()
//{
//	int arr1[5]={0};
//	int* arr[10] = { 0 };
//	test1(arr1);
//	test2(arr);
//
//
//	return 0;
//}
//二维数组传参，
//void test(int arr[3][5])//传入的一个二维数组，用一个二维数组来接收。
//{}
//void test(int arr[][5])//行可以省略，列不可省略
//{}
//void test(int(*p)[5])
//{}
//int main()
//{
//	int arr[3][5] = { 0 };
//	test(arr);//二维数组的首元素的地址是第一行一维数组的地址。
//	return 0;
//}
//一级指针传参
//void test(int* p)//参数类型是int*，一级指针，可以接收以及指针，地址，数组名
//{}
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 9;
//	int* p = &i;
//	    test(&i);
//		test(p);
//		test(arr);
//	return 0;
//}
//二级指针传参
//void test(int** p)//参数类型是二级指针，可以接收二级指针，一级指针的地址，一维指针数组的数组名（首元素的地址）
//{}
//int main()
//{
//	int a = 9;
//	int* p = &a;
//	int** p1 = &p;
//	int* arr[10] = { 0 };
//	test(p1);
//	test(&p);
//	test(arr);
//	return 0;
//}
//函数指针，指向函数的指针。
//int add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int a = 1;
//	int b = 9;
//	printf("%p\n", add);// 00007FF6869413E8
//	printf("%p\n", &add);//00007FF6869413E8
//	//add和&add都是函数的地址
//	int(*p)(int, int) = add;//将函数的地址存入指针中；
//	//(*p)告诉p是一个指针，（int，int）告诉你指向的是函数，和函数的参数类型。int是函数的返回类型。（int，int）的优先级高于*。
//	printf("%d", (*p)(2, 3));//*p相当于add函数，（2，3）是传参，p存的是add的地址，解引用得到add函数
//  printf("%d", (p)(2, 3));//不解引用直接使用p也可以使用函数，把add传给p，p和add是一回事
//	return 0;
//}
//void print(const char* str)
//{
//	printf("%s", str);
//}
//int main()
//{
//	void (* p)(const char*) = print;
//	(*p)("hello wortld");
//
//	return 0;
//}
//int main()
//{
//	typedef void(*fun)(int);//fun是重新定义的名字。void(*)(int)是要被定义部分。
//	(*(void(*)())0)();//(void(*)())将0强制转换为一个函数指针。函数的参数是NULL；返回类型是void。*0是调用这个函数，最后面的括号是参数
//	void(* signal(int, void(*)(int)))(int);//函数名要紧挨这*。
//	//signal是一个函数，函数的参数是一个整型，一个函数指针（指向的函数参数是int，返回类型是void），signal的返回类型是函数指针（指向的函数参数是int，返回类型是void）
//	//除去函数名和函数参数，剩下的是函数的返回类型void(*)(int).
//	//可以将void(*)(int)重新定义为fun，进行简化。
//	   fun signal(int, fun);
//
//	return 0;
//}
//void print(int(* p)[10])
//{
//	printf("%d", ( * p)[5]);
//}
//int main()
//{ 
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	int(*p)[10] = &arr;
//	print(p);
//	return 0;
//}
//函数指针的数组，存放函数指针的数组。
//int add(int x, int y)
//{
//	return x + y;
//}
//int sub(int x, int y)
//{
//	return x - y;
//}
//int mul(int x, int y)
//{
//	return x * y;
//}
//int div(int x, int y)
//{
//	return x / y;
//}
//int main()
//{
//	int i = 0;
//	int (*arr[4])(int, int)={add,sub,mul,div};//arr[4]表示一个数组有四个元素，除去arr[4],剩下的是元素的类型int(*)(int,int),每个元素都是函数指针，指向的函数的返回值是int，参数是（int，int）
//	for (i = 0; i < 4; i++)
//		printf("%d ", arr[i](2, 1));//arr[i]调用函数。（2,1）是参数。
//	//i==1,arr[i]相当于add
//	//i==2,arr[i]相当于sub
//	//i==3,arr[i]相当于mul
//	//i==4,arr[i]相当于div
//	return 0;
//}
//char* my_strcpy(char* des, const char* sou)
//{
//
//}
//int main()
//{
//	char* (*p)(char*, const char*);
//	char* (*arr[4])(char*, const char*) = { my_strcpy };
//
//	return 0;
//}
//函数指针的用途；计算机
//int add(int x, int y)
//{
//	return x + y;
//}
//int sub(int x, int y)
//{
//	return x - y;
//}
//int mul(int x, int y)
//{
//	return x * y;
//}
//int div(int x, int y)
//{
//	return x / y;
//}
//void menu()
//{
//	printf("****************************\n");
//	printf("***1.add         2.sub   ***\n");
//	printf("***3.mul         4.div   ***\n");
//	printf("********** 0.exit **********\n");
//	printf("****************************\n");
//}
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int	(*parr[5])(int, int) = { 0,add,sub,mul,div };
//	do
//	{
//		menu();
//		printf("请输入选择:\n");
//		scanf("%d", &input);
//		if (input >= 1 && input <= 4)
//		{
//			printf("请输入两个操作数:\n");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", parr[input](x, y));
//		}
//		else if (input == 0)
//			printf("退出程序\n");
//		else
//			printf("选择错误\n请重新选择\n");
//	} while (input);
//	return 0;
//}
//回调函数就是一个通过函数指针调用的函数。如果你把函数的指针（地址）作为参数传递给另一
//个函数，当这个指针被用来调用其所指向的函数时 ，我们就说这是回调函数。回调函数不是由该
//函数的实现方直接调用，而是在特定的事件或条件发生时由另外的一方调用的，用于对该事件或
//条件进行响应。
//
//void cal(int (*p)(int, int))
//{
//	int x = 0;
//	int y = 0;
//	printf("请输入两个操作数:\n");
//	scanf("%d%d", &x, &y);
//	printf("%d \n", p(x, y));
//}
//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("请选择：\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			cal(add);
//			break;
//		case 2:
//			cal(sub);
//			break;
//		case 3:
//			cal(mul);
//			break;
//		case 4:
//			cal(div);
//			break;
//		case 0:
//			printf("程序退出\n");
//			break;
//		default:
//			printf("选择错误\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}
//int add(int x, int y)
//{
//	return x + y;
//}
//int sub(int x, int y)
//{
//	return x - y;
//}
//int main()
//{
//	int(*parr[2])(int, int) = { add,sub };
//	int(*(*p)[2])(int, int)=&parr;//指向函数指针数组的指针，
//	//(*p)表示p是一个指针，[2]表示指向的是一个有两元素的数组，数组的元素类型是int(*)(int,int),函数指针。
//
//	return 0;
//}
//void print( const char*  str)
//{
//	printf("%s", str);
//}
//void test(void (*p)( const char* ))
//{
//	printf("1\n");
//	p("hello world\n");
//}
//int main()
//{
//	test(print);
//
//
//	return 0;
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int arr[10]={0};//数组
//	int* p = arr;//指针
//	int* arr1[] = { &arr[1],&arr[2] };//指针数组，*的优先性低于[]。arr1先和[]结合，arr1[]表示一个数组，除去arr1[],就是数组中元素的类型
//	int(*p1)[10] = &arr;//数组指针//*p1，表示p1是一个指针，除去*p1，剩下的是指针指向的物质的类型，int [10]，指向的是一个数组，有10个元素，每个元素的类型是int
//	int (*p2)(int, int) = Add;//函数指针*p2，表示p2是一个指针，int (int,int),表示指向的是一个函数，函数的参数是(int,int),返回类型是int
//	int* (*p3)[2] = &arr1;//指针数组的指针。*p3表示一个指针，int* [2]，表示指向的是一个数组，有2个元素，元素类型是int*.int*是指针，指向的是int
//	int(*arr2[])[10] = { p1 };//数组指针的数组；arr2[]表示一个数组，int(*) [10]，表示数组中元素的类型，是数组指针，指向的是一个数组，数组中有10个元素，元素类型是int
//	int  (*arr3[])(int, int) = { Add };//函数指针的数组，arr3[]表示一个数组,int(*)(int,int),表示数组中元素的类型,是函数指针，指向的是一个函数，函数的参数是(int .int)，返回类型是int
//	int (*(*p4)[1])(int, int) = &arr3;//指向函数指针的数组的指针。*p4，表示一个指针，int(*()[1])(int,int),表示指向的是一个数组有一个元素，数组中元素的类型是int(*)(int,int)，是函数指针，指向的是一个函数，函数的参数是(int .int)，返回类型是int
//	return 0;
//}