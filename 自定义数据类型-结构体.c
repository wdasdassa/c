#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//struct Stu
//{
//	int age;
//	char name[20];
//}s1,s2,s3;
//struct Stu s4;//s1,s2,s3,s4是全局变量
//int main()
//{
//	struct Stu s5;//s5是局部变量
//
//
//	return 0;
//}
//struct
//{
//	int a;
//	char c;
//
//}x;//匿名结构体只能在结构体声明处直接创建全局变量（其他位置无法创建）
//struct
//{
//	int a;
//	char c;
//}*p;
//int main()
//{
//
//	p = &x;//此处虽然两个结构体的成员变量一样也都是匿名结构体，但是编译器在编译过程中会把上面两个结构体类型看作是不同的，所以不能用p存放x的地址。
//
//
//
//	return 0;
//}
//结构体的自引用
//struct node
//{
//	int data;//存放数据的数据域
//	struct node* p;//存放下一个相同结构体类型的指针，存放地址的区域是指针域
//};
//结构体内存对齐
//第一个成员在结构体变量偏移量为0的地址处（变量的起始地址）
//其他成员要对齐到某个数字（对齐数）的整数倍的地址(偏移量)处（每一个成员都有一个对齐数）
//对齐数=编译器默认的一个对齐数与该成员大小的较小值  vs默认是8
//结构体总大小是最大对齐数的整数倍
//如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍，结构体整体的大小就是所有最大对齐数（含嵌套结构体的对齐数）的整数倍
//struct S1 
//{
//	char a;//a存放到偏移量为0的地址处，占据一个字节。
//	int b;//b存放到偏移量为4的地址处，并向下占据四个字节。
//	char c;//c存放到偏移量为8的地址处，占据一个字节。
//};//一共是9的字节大小，又因为结构体大小是最大对齐数（4）的整数倍所以是12.
//struct S2
//{
//	char a;//a存放到偏移量为0的地址处，占据一个字节。
//	char c;//c存放到偏移量为1的地址处，占据一个字节。
//	int b;//b存放到偏移量为4的地址处，并向下占据四个字节。
//};//一共是8的字节大小（有是最大偏移量4的整数倍）。
//////int main()
//////{
//////	printf("%d ", sizeof(struct S1));//12
//////	printf("%d ", sizeof(struct S2));//8
//////
//////	return 0;
//////}
//struct S3
//{
//	double a;//a存放到偏移量为0的地址，向下占据8个字节
//	struct S2 e;//e的最大对齐数是4，存放到偏移量为8的地址，向下占据8个字节
//	int b;//b存放到偏移量为16的地址，向下占据4个字节
//};//一共是20个字节但S3的最大对齐数是8，所以结构体大小是24个字节
////int main()
////{
////
////
////
////	printf("%d", sizeof(struct S3));
////}
////在设计结构体，既要满足对齐，又要节省空间。
////让占用空间小的变量尽量集中在一起
////#pragma pack(num)设置默认对齐数为num
////#pragma pack()取消设置默认对齐数为num（返回原来的默认值）
////size_t offsetof(structname ,name)可以计算结构体变量的偏移量。是宏。引用头文件<stddef.h>
//#include<stddef.h>
//int main()
//{
//
//
//	printf("%d ", offsetof(struct S3, b));//直接计算最后一个成员变量的偏移量加上成员大小再与最大对齐数的整数倍比较即可得出结构体大小
//}
//结构体传参是传结构体的地址。
//struct S
//{
//	int age;
//    char name;
//};
//void init(struct S* p)
//{
//	p->age = 20;
//	p->name='w';
//}
//void print(struct S* p)
//{
//	printf("%d\n", p->age);
//	printf("%c\n", p->name);
//}
//int main()
//{
//	struct S s1;
//	init(&s1);
//	print(&s1);
//
//
//	return 0;
//}
#include<string.h>
