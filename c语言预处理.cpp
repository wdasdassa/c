#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//翻译环境，在该环境中源代码被转换为可执行的机器指令（exe文件）；可执行程序中（exe文件）是二进制文件
//执行环境用于实际执行代码
//每个源文件都会被编译器单独处理编译为目标文件（.obj文件）
//组成一个程序的每个源文件通过编译过程分别转换成目标代码 ( object code )。
//每个目标文件由链接器（linker ）捆绑在一起，形成一个单一而完整的可执行程序。
//链接器同时也会引入标准C函数库中任何被该程序所用到的函数，而且它可以搜索程序员个人的程序库，将其需要的函数也链接到程序中
// 
//编译又细分为预编译，编译，汇编三部分
//预编译（文本操作） 操作指令是gcc -E test.cpp      产生一个新的文件 test.i
//1.#include 头文件的包含
//2.注释的删除 ，用空格替代注释 
//3.#define 定义的变量替换  如#define MAX 100  就会把所有用到MAX的替换为100
//......
//编译（将c语言代码翻译为汇编代码） 操作指令  gcc -S test.i    产生以一个新的文件 test.s
//1.语法分析 2.词法分析 3.语义分析 4.符号汇总
//汇编（把汇编代码转换为二进制代码（指令）） 操作指令 gcc -c test.s      产生一个新的文件 test.o（window下产生test.obj）
//汇编过程中会形成符号表
// 例add.cpp会形成 
// 符号名      地址
//   add       0x102（假设）
// test.cpp会形成
// 符号名      地址
//  main       0x111（假设）
//  add        0x000（无意义的地址，因为add函数在test.cpp中无定义）
//以上操作指令和产生文件是Linus操作系统下的。
//链接过程
//1.合并段表
//每个目标文件都有一个相同的格式（elf文件格式）
//合并段表就是把每个目标文件合并在一起。（每个目标文件对应的部分合并在一起）
//最终生成的exe可执行程序也是elf的文件格式。
//2.符号表的合并和重定位
//就是把每个源文件的符号表合并（当文件之间有一个函数的多个地址，选用那个函数的有效地址）
// 如
//add.cpp和test.cpp的符号表合并后
// 符号名      地址
//  main       0x111
//  add        0x102（add函数的地址重定位）
//运行环境
//程序执行过程：
//1.程序必须载入内存中。在有操作系统的环境中：一般这个由操作系统完成。在独立的环境中，程序的载入必须由手工安排，也可能是通过可执行代码置入只读内存来完成。
//2.程序的执行便开始。接着便调用main函数。
//3.开始执行程序代码。这个时候程序将使用一个运行时堆栈(stack），存储函数的局部变量和返回地址。程序同时也可以使用静态（static）内存，存储于静态内存中的变量在程序的整个执行过程一直保留他们的值。
//4.终止程序。正常终止main函数；也有可能是意外终止。、
//预定义符号
//__FILE__     代码所在源文件的绝对地址
//__LINE__     __LINE__所在的行号。
//__DATE__     代码执行的日期
//__TIME__     代码执行的时间
//__FUNCTION__  代码执行的函数
//__STDC__ 如果编译器遵循ANSI C ，其值为1，否则是未定义
//int main()
//{
//	printf("%s\n", __FILE__);
//	printf("%d\n", __LINE__);
//	printf("%s\n", __TIME__);
//	printf("%s\n", __DATE__);
//	printf("%s\n", __FUNCTION__);
//	return 0;
//}
//预处理指令
//#define
//#include
//#pragma pack ()
//#if....
//
//
//#define
//1.定义标识符
//#define MAX 100
//#define df  "hehe"
//int main()
//{
//	printf("%s %d", df,MAX);
//	return 0;
//}
//2,定义宏
//#define允许把参数替换到文本
//#define name(parament-list) stuff 其中parament-list是一个由逗号隔开的符号表，它可能出现在stuff中
//注意 参数列表的左括号必须与name紧邻，如果两者之间有任何空白存在，参数列表就会被解释为stuff的一部分
//#define square(x) x*x
////宏是替换不是传参
//int main()
//{
//	int ret = square(5);
//	printf("%d", ret);
//	ret = square(5 + 1);
//	printf("%d", ret);//11,square(5+1)  5+1*5+1==11 不是传参是替换。要注意
//	return 0;
//}
//#define double(x) x+x
//#define double1(x) (x+x)
//int main()
//{
//	int a = 5;
//	printf("%d", 10 * double(a));//10*5+5
//	printf("%d", 10 * double1(a));//100
//	return 0;
//}
//#define 替换规则
//在程序中扩展#define定义符号和宏时，需要涉及几个步骤。
//1. 在调用宏时，首先对参数进行检查 ，看看是否包含任何由#define定义的符号。如果是，它们首先被替换。
//2. 替换文本随后被插入到程序中原来文本的位置。对于宏，参数名被他们的值替换。
//3. 最后，再次对结果文件进行扫描，看看它是否包含任何由#dlefine定义的符号。如果是，就重复上述处理过程。
//注意：
//1宏参数和#define 定义中可以出现其他#define定义的变量。但是对于宏，不能出现递归。
//2. 当预处理器搜索#define定义的符号的时候，字符串常量的内容并不被搜索。
//#define MAX 100
//#define double(x) x+x
//int main()
//{
//	int i = 10;
//	int c = double(MAX);//宏参数可以是#define定义的其他变量
//	printf("MAX=%d,c=%d", MAX,c);
//	//字符串中的内容不被替换
//	return 0;
//}
//#和##预处理指令
//#define PRINT(X) printf("the value of"" "#X" ""is %d\n",X)
////此时#X  会被替换为  X被替换后   X所对应的字符串  即"X"
// 把一个宏参数变为对应的字符串
//int main()
//{
//
//	printf("hello world\n");//hello world
//	printf("hell""o"" world\n");//hello world
//	printf("hel""lo world\n");//hello world
//	int a = 10;
//	int b = 20;
//	PRINT(a);// printf("the value of"" ""a"" ""is %d\n",X)
//	PRINT(b);// printf("the value of"" ""b"" ""is %d\n",X)
//	return 0;
//}
//##可以把位于它两边的符号合成为一个符号，它允许宏定义从分离的文本片段创建标识符
//这样的链接产生的必须是一个合法的标识符，否则是无定义的
//#define CAT(X ,Y)  X##Y
//int main()
//{
//	int Class89 = 2023;
//	printf("%d", CAT(Class, 89));
//	//printf("%d", Class##89));
//	//printf("%d", Class89));
//	return 0;
//}
//带有副作用的宏
//#define MAX(x,y) (x)>(y)?(x):(y)
//int main()
//{
//	int a = 10;
//	int b = 11;
//	int max = MAX(a++, b++);
//	//b==13，a==11
//	//a,b的值都会发生变化
//	//不是所要的值
//	return 0;
//}
//#define MAX(X,Y) (X)>(Y)?(X):(Y)
//int Max(int x, int y)
//{
//	return x > y ? x : y;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int max = MAX(a, b);
//	//宏在预处理阶段就完成了替换
//	//没有函数调用和返回的开销
//	printf("max=%d", max);
//	max = Max(a, b);
//	//函数在调用时，会产生函数调用和返回的开销
//	printf("max=%d", max);
//	return 0;
//}
//1.用于调用函数和从函数返回的代码可能比实际执行这个小型计算工作所需要的时间更多。所以宏比函数在程序的规模和速度方面更胜一筹。
//2. 更为重要的是函数的参数必须声明为特定的类型。所以函数只能在类型合适的表达式上使用。反之宏适用于整型、长整型、浮点型等可以用于>来比较的类型。宏是类型无关的。
//当然和宏相比函数也有劣势的地方：
//1 每次使用宏的时候，一份宏定义的代码将插入到程序中。除非宏比较短，否则可能大幅度增加程序的长度。
//2. 宏是没法调试的。
//3.宏由于类型无关，也就不够严谨。
//4.宏可能会带来运算符优先级的问题，导致程容易出现错。
//宏有时候可以做函数做不到的事情。比如：宏的参数可以出现类型，但是函数做不到。
//#define SIZEOF(type) sizeof(type)
//int main()
//{
//	int ret = SIZEOF(int);//宏可以传类型过去
//	printf("%d", ret);
//	return 0;
//}
//命名约定 宏定义全用大写，函数名不要全用大写
//#undef
//移除一个宏指令
//#define MAX(x,y) (x)>(y)?(x):(y)
//int main()
//{
//#undef MAX
//	int a = 10;
//	int b = 20;
//	int max = MAX(a, b);
//
//
//}
//条件编译
// 常见的条件编译
// 1. #if (常量表达式)  //表达式为真就执行 ，为假就不执行
//      语句
//    #endif
// 
// 
// 2.判断是否被定义
//  #if defined (name)(用户编写的名字)
//  #ifdef  name(用户编写的名字)    两种写法等价
//  语句      //如果name被定义过，就执行语句
// #endif
// 
//  #if ！defined(name)(用户编写的名字)
//  #ifndef name(用户编写的名字)  两种写法等价
//   语句      //如果name没定义过，就执行语句
//  #endif
//
//没有就不执行语句
//3.多分枝的条件编译
//  #if (常量表达式)
//       语句
//  #elif (常量表达式)
//     语句
//  #else
//       语句
// #endif
//
// 4.嵌套指令
// #ifdef OS_T
//    #if option1
//        语句;
//    #endif
//    #if option2
//      语句;
//    #elif option3
//       语句;
//    #else
//       语句;
//     #endif
//  #endif 
// 
//
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//		#ifdef XIAOGUO//如果XIAOGUO被定义就执行语句
//		printf("%d ", arr[i]);
//        #endif
//	}
//}
//头文件包含（就是把头文件拷贝进去）
//1.本地文件包含用""      #include "add.h"
// 查找策略，先在源文件所在目录下查找，如果该头文件未找到，编译器就会像查找库函数头文件一样在标准位置查找，如果找不到就编译错误
//2.库函数包含用<>    #include<stdio.h>
// 查找策略，在标准位置查找头文件，找不到提示编译错误
//
//嵌套文件包含
// 
// 如果同一个头文件被包含了多次，就会导致代码的冗余
// 通过以下方式可以避免
// #ifndef __ADD_H__
//   define __ADD_H__
//     语句；
// #endif
//
//#pragma once
//  语句
//
//这样的方式编写头文件就可以避免头文件被多次包含时造成的代码冗余。（头文件只会被拷贝一次）

//struct S
//{
//	int a;
//	int b;
//	char c;
//
//};
//
//#define OFFSETOF(struct_name,member_name)     (int)&(((struct_name*)0)->member_name)
//
////结构体中每个成员的地址减去结构体的初始地址就是每个成员的偏移量
////将0强制转换为结构体指针（结构体的初始地址），再通过0去找到每个成员的地址，再将其转换为int，便是每个成员的偏移量
//int main()
//{
//	printf("%d \n", OFFSETOF(struct S, a));
//	printf("%d \n", OFFSETOF(struct S, b));
//	printf("%d \n", OFFSETOF(struct S, c));
//	return 0;
//}
int cal(int x, int n)
{
	if (x == 1)
		return x;
	if (n == 0)
		return 1;
	return x * cal(x, n - 1);
}


void find(int arr[],int* x,int* y,int size)
{
	int count = 1;
	int sum = 0;
	int i = 0;
	for (i = 0; i < size; i++)
	{
		sum = arr[i] ^ sum;
	}
	while (sum % 2 != 1)
	{
		sum /= 2;
		count++;
	}
        i = 0;
		while (i < size)
		{
			if ((arr[i] / cal(2, count - 1)) % 2 == 1)
			{
				*x = *x ^ arr[i];
				i++;
			}
			else
			{
				*y = *y ^ arr[i];
				i++;
			}

		}
}
//一个数组中只有两个数字出现一次
//其他的数都出现两次
//找到这两个数
int main()
{
	int x = 0;
	int y = 0;
	int arr[] = { 1,2,3,4,5,6,1,2,3,4,5,6,11,10 };
	int size = sizeof(arr)/sizeof(arr[1]);
	find(arr,&x,&y,size);
	printf("%d  %d", x, y);
	return 0;
}
