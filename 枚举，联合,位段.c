#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//结构体实现位段
//位段的成员必须是int，unsigned int 或signed int，char(属于整型家族)(一般位段成员都是其中的一种)
//位段的成员名后边都有一个冒号和一个数字。数字表示成员所占用的bit位个数,数字不能超过类型所占的bit位个数。
//存放内容是，申请一个存放一个（从右向左使用，剩下的bit位不能存放下一个成员时直接舍弃再次开辟空间）。
//位段-二进制位
//位段的空间是按照需要以4个字节（int）或1个字节（char）的方式开辟的
//位段涉及很多不确定因素，位段是不跨平台的，注意可移植程序避免使用位段
//位段的跨平台问题
//1.int 位段被当成有符号数还是无符号数是不确定的。
//2.位段中最大位的数目不能确定（16位机器最大16，32位机器最大32，写成27，在16位机器会出问题）。
//3.位段中的成员在内存中从左向右分配，还是从右向左分配标准尚末定义。
//4. 当一个结构包含两个位段，第二个位段成员比较大 ，无法容纳于第一个位段剩余的位时，是舍弃剩余的位还是利用，这是不确定的。
//总结：
//跟结构相比，位段可以达到同样的效果，但是可以很好的节省空间，但是有跨平台的问题存在。
//struct S
//{
//	int a : 2;//a只占用2个bit位
//	int b : 5;//b占用5个bit位
//	int c : 10;//c占用10个bit位
//	int d : 30;//d占用30个bit位
//};//先申请四个字节空间存放a，b，c（空间从右向左使用），剩下的空间无法存放d（空间舍弃），再申请四个字节的空间（从右向左使用）存放d。一共是8个字节
//  //也可以先申请两个int类型的空间，先使用低地址的int类型的空间（每个空间是从右向左使用）。
//int main()
//{
//	printf("%d", sizeof(struct S));
//
//	return 0;
//}
//枚举类型 
// 枚举类型的大小是4（整型大小）
//enum  sex
//{//枚举常量,枚举常量之间用','隔开
//	      //默认初始值是
//	man,  //0
//	woman,//1
//	secret//2
//};
//enum color
//{//可以枚举常量赋一个初始值
//	blue=2,//2
//   green=3,//3
//	red=4,//4
//};
//enum ca
//{
//	c1=3,
//    c2,//4对于没有赋初始值的枚举常量它的默认初始值是前一个枚举常量的值+1
//    c3=1,
//};
//int main()
//{
//	enum color f = (enum color)2;
//	//enum color f = 2;//2是int类型无法将其赋值给一个枚举类型的变量
//	enum color c = red;
//	//red = 2;red是一个枚举常量无法被赋值
//	printf("%d %d %d", c1,c2,c3);
//
//
//	return 0;
//}
//我们可以使用#define 定义常量，为什么非要使用枚举？枚举的优点
//1.增加代码的可读性和可维护性
//2, 和#define定义的标识符比较枚举有类型检查，更加严谨。
//3.防止了命名污染（封装）
//4. 便于调试
//5. 使用方便，一次可以定义多个常量
//联合（共用体）
//联合是一种特殊的自定义类型，这类类型的变量包含一系列成员，特征是这些成员共用一块空间。
//一个联合变量的大小至少是最大成员（空间占用）的大小
//当最大成员的大小不是最大对齐数的整数倍时，要对齐到最大对齐数的整数倍。
//联合体成员不能同时使用（只能使用一个成员）
//测试电脑的存储模式
//int check_sys()
//{
//	union un
//	{
//		char a;
//		int i;
//	}s;
//	s.i = 1;
//	return s.a;
//
//}
////a的地址与i的地址相同，&a是char*类型 只会访问一个字节
////&i中存放的是0x 01 00 00 00
////&a中存放的撒0x 01
//int main()
//{
//	int ret = check_sys();
//	if (ret == 1)
//		printf("小端\n");
//	else
//		printf("大端\n");
//
//
//}
union mn
{
	char a;//大小1，对齐数1
	int c;//大小4，对齐数是4
	char arr[9];//大小是9，对齐数是1（数组元素的类型的对齐数）
};//9不是4的整数倍，所以是12
int main()
{

    union mn s;
	printf("%d", sizeof(s));//12

	return 0;
}