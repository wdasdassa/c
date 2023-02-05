#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<stdio.h>
//局部变量，函数形参在栈区开辟空间
//动态内存分配在堆区分配空间malloc，free ，calloc，realloc
//全局变量，static修饰的变量（静态变量）在静态区开辟空间。
//malloc函数是申请动态内存空间,开辟size个字节大小的内存
// 如果开辟成功返回开辟空间的初始地址，如果开辟失败返回NULL
// malloc并不知道使用者开辟的空间类型，所以返回的void*，需要使用者自行调试决定
// size不能是0
//void* malloc(size_t size)
//void  free(void* ptr) 释放和回收开辟的  动态内存空间
//如果*ptr指向的空间不是动态开辟的空间那么free的行为是未定义的
//*ptr如果是NULL，那么函数将什么也不做
//int main()
//{
//	int* p = (int*)malloc(4 * sizeof(int));//开辟10个int空间
//	if (p == NULL)
//		printf("%s", strerror(errno));//打印失败原因
//
//	free(p);//在开辟的空间使用结束后要及时释放开辟的空间。但是释放后p内存放的仍是开辟空间的起始地址，
//	p = NULL;//所以令p为空指针，以防出现p被使用，造成错误
//
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	scanf("%d", &i);
//	int* p=(int*)malloc(i);
//	free(p);
//	p = NULL;
//	return 0;
//}
//calloc 函数   void* calloc(size_t num,size_t size),num是元素个数，size 是每个元素的大小（单位字节）
//为num个size大小的元素开辟空间并将内存中每个字节初始化为0
//与malloc相比效率低，但是会进行初始化
//开辟成功返回开辟空间的起始地址，开辟失败返回NULL
//int main()
//{
//	int* p = (int*)calloc(10, sizeof(int));
//	free(p);
//	p = NULL;
//	return 0;
//}
//realloc 函数可以调节内存空间开辟的大小
// void* realloc(*ptr,size_t size)，ptr是要调整的动态内存空间的地址，size是调整之后的新大小；
// 当realloc调整失败后，返回NULL；不影响已经开辟的内存空间。
//当realloc调整成功后会有两种情况：
// 1，当原来的动态内存空间有足够的内存可以让realloc调整时，调整后返回原来的内存地址。
// 2，当原来的动态内存空间没有足够的内存可以让realloc调整时，realloc会重新开辟一个新的内存空间，并将原来内存空间的数据拷贝到新的内存空间中。
// 返回新的内存空间的起始地址。并将原来的内存空间释放。
// 最好用一个新的指针接受realloc的返回值。
//    此时realloc(NULL,size)相当于malloc。
//int main()
//{
//	int* p = (int*)malloc(40);
//	int* p1 = (int*)realloc(p, 80);
//	if (p1 != NULL)//开辟成功
//	{
//		p = p1;//让原来开辟空间的初始地址改为新开辟空间的地址。
//		p1 = NULL;
//		free(p);
//		p = NULL;
//	}
//	else//开辟失败
//	{
//		printf("%s\n", strerror(errno));
//		free(p);
//		p = NULL;
//	}
//	return 0;
//}
//常见错误
//1，未判断动态空间开辟函数是否成功；直接对函数返回值进行解引用，容易造成对NULL指针进行解引用
//2. 动态内存越界访问
//3. 对非动态内存开辟的空间进行释放 
//4，使用free释放开辟内存空间的一部分
//5. 对同一块动态内存多次释放//释放后令指针为NULL，即可避免
//6，动态开辟内存忘记释放（内存泄露）
//void getmemory(char* p)//p时str的一个临时拷贝
//{
//	p = (char*)malloc(40);//p的值被修改为动态开辟内存的初始地址
//}                         //但str未发生改变，p是形参，出函数被销毁，所以动态内存也没有释放（内存泄漏）
//void test(void)
//{
//	char* str = NULL;
//	getmemory(str);//此处为传值
//	strcpy(str, "hello world");//str是空指针，此处无法进行拷贝，导致程序崩溃
//	printf(str);
//}
//int main()
//{
//	test();
//	return 0;
//}
//void getmemory(char** p)
//{
//	*p = (char*)malloc(40);
//}                       
//void test(void)
//{
//	char* str = NULL;
//	getmemory(&str);
//	strcpy(str, "hello world");
// printf(str);
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	test();
//	return 0;
//}
//char* getmemory(char* p)
//{
//	p = (char*)malloc(40);
//	return p;
//}
//void test(void)
//{
//	char* str = NULL;
//	str=getmemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	test();
//	return 0;
//}
//int main()
//{
//    const	char* p = "hello";//00007FF6DE839BE8
//    char arr[] = "hello";//0000007A438FF954
//    //两次的地址并不相同。
//    //p中存放的是常量字符串"hello"的首元素地址，常量字符串"hello"在栈上的地址是固定的 。常量字符串"hello"的地址是固定的
//    //arr中存放的是首元素的地址，先在栈上开辟空间，再放入"hello"，此时是数组变量arr的首元素地址。
//    printf("%p\n%p", p, arr);
//	return 0;
//}
//char*  getmemory()
//{
//    char arr[] = "hello";//在栈上申请了一个空间数组arr来存放"hello"；
//	return arr;//arr是首元素的地址,arr是临时变量，函数结束，arr就被销毁了，此时其存放的"hello",也发生改变。
//}
//void test(void)
//{
//	char* str = NULL;
//	str = getmemory();//str接收的是arr数组的首元素地址，但arr数组已经被销毁，内容也消失了。
//	printf(str);//打印str导致非法访问。
//}//返回栈区地址导致的问题
//int main()
//{
//	test();
//	return 0;
//}
//
//
//
//
//char* getmemory()
//{
//	char* arr =(char*) "hello";
//	return arr;
//}
//void test(void)
//{
//	char* str = NULL;
//	str = getmemory();
//	printf(str);
//}
//int main()
//{
//	test();
//	return 0;
//}
//C / C++程序内存分配的几个区域：
//  1.栈区(stack）：在执行函数时，函数内局部变量的存储单元都可以在栈上创建，函数执行结束时这些存储单元自动被释放。栈内存分配运算内置于处理器的指令集中，效率很高，但是分配的内存容量有
//	栈区主要存放运行函数而分配的局部变量、函数参数、返回数据、返回地址等。
//	2.堆区(heap）：一般由程序员分配释放，若程序员不释放，程序结束时可能由OS回收。分配方式类似于链表。
//	3.数据段（静态区）（static ）存放全局変量、静态数据。程序结束后由系统释放。
//	4.代码段：存放函数体（类成员函数和全局函数）的二进制代码。
//	实际上普通的局部变量是在栈区分配空间的，栈区的特点是在上面创建的变量出了作用域就销毀。
//	但是被sttic修饰的变量存放在数据段（静态区），数据段的特点是在上面创建的变量，直到程序结束才销毀	，所以生命周期变长。


// 柔性数组，结构中最后一个元素允许是未知大小的数组，这就叫作柔性数组成员
// 在计算含有柔性数组的结构大小时结构成员不包括柔性数组。即柔性数组不加入进行计算。
// 使用malloc进行内存分配是时要大于结构的大小，以适应柔性数组的大小
// 方便内存释放
// 有利于访问速度 ，减少内存碎片。
//struct S1
//{
//	int i : 2;
//	int arr[];//此时结构体的大小是4
//};//位段
//union s1
//{
//	int i;
//	char arr[];
//};//联合体
//
//struct S
//{
//	int i;
//	int arr[0];//int arr[];两种写法都可以
//};//结构体
//int main()
//{//含有柔性数组的结构使用
//	int i = 0;
//	struct S* p = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
//	if(p==NULL)
//	{
//		printf("%s", strerror(errno));
//		return 0;
//	}
//	p->i = 100;
//	for (i = 0; i < 5; i++)
//		p->arr[i] = i;
//	struct S* p1 = (struct S*)realloc(p, sizeof(struct S) + 10 * sizeof(int));
//	if (p1 == NULL)
//	{
//		printf("%s", strerror(errno));
//	}
//	else
//	p = p1;
//	for (i = 5; i < 10; i++)
//		p->arr[i] = i;
//	free(p);
//	p = NULL;
//	return 0;
//}

//下面这个方法也可以实现和柔性数组类型的功能
struct S
{
	int i;
	int* p;//p指向的数组可以调整。
};
int main()
{
	struct S* ps = (struct S*)malloc(sizeof(struct S));
	if (ps == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	ps->p = (int*)malloc(5 * sizeof(int));
	if (ps->p == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		ps->p[i] = i;
	}
	int* pp = (int*)realloc(ps->p, 40);
	if (pp == NULL)
		printf("%s\n", strerror(errno));
	else
		ps->p = pp;
	for (i = 5; i < 10; i++)
		ps->p[i] = i;
	for (i = 0; i < 10; i++)
		printf("%d ", ps->p[i]);
	free(ps->p);
	ps->p = NULL;
	free(ps);
	ps = NULL;
	return 0;
}