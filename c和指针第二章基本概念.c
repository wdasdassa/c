#define _CRT_SECURE_NO_WARNINGS
/*
在ANSI C的任何一个实现中存在两种不同的环境。1，是翻译环境，在这个环境中，源代码被转换为可执行的机器指令。2，是执行环境，它用于实际执行代码
这两种环境不必位于同一台机器上。例如 交叉编译器就是在一台机器上运行，但它所产生的可执行代码运行于不同类型的机器上。
独立环境是不存在操作系统的环境。
翻译过程由几个步骤组成，组成一个程序的每个（或多个）源文件通过编译过程分别转换为目标代码。然后每个目标文件再由链接器捆绑在一起，形成一个单一
而完整的可执行程序。链接器也会引入标准的C函数库中任何被该程序用到的函数。而且它也可以搜索程序员的个人程序库，将需要的函数也链接到程序中。
编译过程本身由几个阶段组成，首先是 预处理器 处理
预处理器在源代码上执行一些文本操作。比如实际值代替#define指令定义的符号以及读入由#include指令包含的文件的内容。
然后是 源代码解析
源代码通过解析，判断它语句的意思。随后产生目标代码。目标代码是机器指令的初步形式，用于实现程序的语句。如果我们在编译程序的命令行加入了要求进行优化的选项
优化器就会对目标代码进行进一步的处理，是它的效率更高。优化过程需要额外的时间。
编译和链接
1.编译并链接一个完全包含于一个源文件的C程序
   cc program.c
   这条命令产生一个a.out的可执行程序，中间会产生一个名叫program.o的目标文件，但它会在链接过程完成后会删除。
2.编译并链接几个C源文件
   cc main.c sort.c lookup.c
   当编译的源文件超过一个时，目标文件就不会被删除。这就允许你对程序进行修改后，只对那些修改过后的源文件进行重新编译。
3.编译一个C源文件，并将其和现存的目标文件链接在一起
   cc main.o lookup.o sort.c
4,编译一个C源文件，产生一个目标文件，以后在进行链接
   cc  -c program.c
5,编译几个C源文件，并为每个源文件产生一个目标文件
   cc  -c main.c lookup.c sort.c
6,链接几个目标文件
   cc  main.o sort.o lookup.o

MS_DOS和UNIX有以下几点不同
1，它的名字是bcc
2.目标文件的名字是file.obj
3，单个源文件被编译并链接时编译器不会删除目标文件
4.在缺省的情况下，可执行文件以命令行中的第一个源或目标文件名命名，不过可以使用"-ename"选项把可执行程序文件命名为"name.exe"

程序必须加载到内存中才能执行，在宿主环境中这个操作由操作系统完成。在自由式环境中，程序往往永久存储在ROM中。经过初始化的静态变量在程序执行前获得他们的值。

当头文件被修改时，所有包含它的文件都要被重新编译
当源文件被修改时，只需要将源文件重新编译。
*/
#include<stdio.h>
//int main()
//{
//	printf("hello\"world\"\n");//hello"world"//\"用于表示一个字符串常量内部的双引号
//	printf("hello\'world\'\n");//hello'world'//\'用于表示一个字符串常量内部的双引号
//	printf("\235\n");// \ddd ddd表示一个1--3个八进制数字。这个转义符表示的字符就是给定的八进制数值所代表的字符。
//	printf("\x061\n");// \xddd xddd表示一个1--3个十六进制数字。这个转义符表示的字符就是给定的十六进制数值所代表的字符。
//	//如果十六进制的数字过大超出了表示字符的范围，其结果就是未定义
//}
//int main()
//{
//	int x1 = 10;   /*  注释字符内部的所有东西都被都作为注释的内容，注释内部不能嵌套注释 从第一个/*开始，到第一个 */ 结束。
//	in4 x4 = 10;               
//    int x3 = 10;
//	int x2 = 10;    */
//}



//标识符，标识符就是函数，变量，类型的名字，它们由大小写字母，数字，下划线组成。不能用数字开头
int//可以将函数的返回类型放在单独的一行
ADD(int x, int y)
{
	return x * y;
}
//int main()
//{
//
//	printf("%d", ADD(3, 5));
//}
void 
squares(int limit)
{
/* comment out this entire function
    int i;/*loop counter */
/*
**print table of squares
*/
//	printf("%d", ; limit);*/
}
//int main()
//{
//	//int x/*bash bash*/y;
//	printf("%s", "\"Blunder??!??\"");
//	printf("\0123");
//}
#include<string.h>
#include<assert.h>
//int check(char* buff)
//{
//	assert(buff != NULL);
//	int i = 0;
//	int count1 = 0;
//	int count2 = 0;
//	int len = strlen(buff);
//	while (i < len)
//	{
//		if (buff[i] == (char)'{')
//		{
//			count1++;
//		}
//		if (buff[i] == (char)'}')
//		{
//			count2++;
//		}
//		i++;
//	}
//	if (count1 == count2)
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	int i = 0;
//	char buff[1000]="0";
//	fgets(buff, 1000, stdin);
//	i=check(buff);
//	if (i == 1)
//		printf("配对成功\n");
//	else
//		printf("不配对\n");
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//    int begin = 1;
//    int ch = 0;
//    int line = 1;
//    while ((ch = getchar()) != EOF)
//    {
//        if (begin == 1)
//        {
//            printf("%d ", line);
//                begin = 0;
//                line++;
//        }
//        putchar(ch);
//        if (ch == (char)'\n')
//            begin = 1;
//    }
//    return 0;
//}