#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//strlen以'\0'为结束标准，计算字符串中'\0'之前的出现的字符个数（不包括'\0'）
// 参数指向的字符串必须以'\0'结尾
// 函数的返回值是size_t（unsigned int ），无符号数（易错）
// 
//int main()
//{
//	//strlen     size_t strlen(char const* _Str);
//	//strlen的返回类型是size_t,也就是无符号的整型 unsigned int .
//	if (strlen("abc") - strlen("abcde") >= 0)
//	{
//		printf("hehe\n");//3-6.此处的3和6都是无符号数，无符号数相减肯定是无符号数一定大于等于0
//	}
//	else
//		printf("haha\n");
//
//
//
//		return 0;
//}
//size_t mystrlen(const char* str)
//{
//	const char* str1 = str;
//	while (*str)
//	{
//		str++;
//	}
//	return str - str1;
//}
//int main()
//{
//	int len = mystrlen("abcde");
//	printf("%d ", len);
//
//
//	return 0;
//}
//int mystrlen(const char* str)
//{
//	if (*str == '\0')
//		return 0;
//	else
//		return 1 + mystrlen(str + 1);
//}
//int main()
//{
//		int len = mystrlen("abcde");
//		printf("%d ", len);
//		return 0;
//}
//  char* strcpy(char* destination ,const char* source)
// 源字符串必须以'\0'结尾；源字符串的长度不能大于目标字符串的长度
// 会将源字符串的'\0'拷贝到目标字符串；
// 目标字符串必须可以修改；
// 目标字符串的空间足够大可以放下源字符串。
#include<assert.h>
//char* mystrcpy(char* dest, const char* src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* ret = dest;
//	while (*dest++ = *src++)
//	{
//		;
//	}//拷贝src的内容到dest
//	return ret;//返回dest的首元素的地址
//
//
//}
//int main()
//{
//	char arr1[] = "hello world";
//	char arr2[] = "hello  bit";
//	mystrcpy(arr1, arr2);
//	printf("%s", arr1);
//
//	return 0;
//}
//char*  strcat(char* destination,const char* source)
// 在目的字符串后追加源字符串（包括'\0'）；
// 源字符串必须以'\0'结尾；
// 目标字符串必须足够大以容纳下追加的字符串
// 目标字符串中必须含有'\0',源字符串追加在目标字符串的第一个'\0'处，并且覆盖第一个'\0'。
//例 "abcdefg\0xxxxx\0"    "qwe\0"
//   "abcdefgqwe\0xx\0"
//int main()
//{
//	char arr1[90] = "abcdefg\0xxxxx\0";
//	char arr2[] = "qwe";
//	strcat(arr1, arr2);
//	return 0;
//}
//char* mystrcat(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* ret = dest;
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return dest;
//}
//int main()
//{
//	char arr1[20] = "hello ";
//	char arr2[] = "world";
//	mystrcat(arr1, arr2);
//	printf("%s", arr1);
//	return 0;
//}
//  int strcmp(const char* str1,const char* str2)
// 当第一个字符串等于第二个字符串时 返回0
// 当第一个字符串大于第二个字符串时 返回大于0的数
// 当第一个字符串小于第二个字符串时 返回小于0的数
// 进行比较时是两个字符串相同位置的字符ASCII码值进行比较 如果相等就比较下一个直至'\0'
//  1"abce"   
//  2"bcd"
//a 的ASCII值小于b，所以返回值小于0
// 1"abc"
// 2"ade"
// d的ASCII码值大于b返回值小于0
// 并且比较在进行到第一个'\0’时结束
// "abcd\0abc"
// "abcd"
//  结果是0；

//int main()
//{
//	int ret = 0;
//	ret = strcmp("abcd\0abc", "abcd");
//	printf("%d", ret);//0
//	return 0;
//}
//int mystrcmp(const char* str1,const  char* str2)
//{
//	assert(str1 && str2);
//    while (*str1 != '\0' || *str2 != '\0')
//	{
//		if (*str1 == *str2)
//		{
//			str1++;
//			str2++;
//		}
//		else
//			return *str1 - *str2;
//    }
//	return 0;
//
//
//}
//int mystrcmp(const char* str1, const  char* str2)
//{
//	while (*str1++ == *str2++)
//	{
//		if (*str1 == '\0')
//			return 0;
//	}
//	if (*str1 > *str2)
//		return 1;
//	else
//		return -1;
//
//
//
//}
//int main()
//{
//
//	char arr1[] = "abcdefg";
//	char arr2[] = "abcd";
//	int ret=mystrcmp(arr1, arr2);
//	printf("%d ", ret);
//	return 0;
//}
//char* strncpy(char* destination,const char* source, size_t num(单位是字节)) 
// 
// 拷贝num的字节从源字符串到目标字符串
// 如果源字符串小于num则拷贝完源字符串后，在目标的后面追加0；
// 不一定拷贝'\0'
// 例
//   "abcde\0"   "bit\0"  2
//    "bicde\0"
//  "abcde\0"   "bit\0"  5
//  "bit\0\0\0"
//int main()
//{
//	char arr1[7] = "mn";
//	char arr2[] = "ab";
//	strncpy(arr1, arr2,5 );
//	printf("%s", arr1);
//
//}
//char* mystrncpy(char* dest, const char* src, size_t num)
//{
//	assert(src && dest);
//    int len = strlen(src);
//	char* ret = dest;
//	int i = 0;
//	if (len + 1 >= num)
//	{
//		for (i = 0; i < num; i++)
//		{
//			*dest++ = *src++;
//
//		}
//	}
//	else
//	{
//		for (i=0;i<len+1;i++)
//			*dest++ = *src++;
//		while (i < num)
//		{
//			*dest = '\0';
//			i++;
//		}
//	}
//	return ret;
//}
//char* mystrncpy(char* dest, const char* src, size_t num)
//{
//	char* start = dest;
//	while (num && (*dest++ = *src++))
//		num--;//当*dest=f，*src='\0'时，num==2；然后进行判断条件，f被改为'\0'，并且dest++，src++，没有进入循环num==2
//	if (num)
//		while (--num)//num先减1（前面少减了一个一）
//			*dest++ = '\0';//g被改为'\0'，num再减一，跳出循环结束。
//	return start;
//}
//int main()
//{
//	char arr1[20] = "abcdefg";
//	char arr2[] =   "hello";
//	mystrncpy(arr1,arr2,7);
//	printf("%s", arr1);
//
//
//
//	return 0;
//}
////char* strncat(char* destination,const char* source, size_t num(单位是字节))
// 追加num个字符，追加在目的字符串的第一个\0处，（覆盖'\0'）
// 无论追加多少个字符，在追加的字符串末尾追加上'\0'（如果追加完源字符串的num（num小于strlen（源字符串））个字符后，在目的字符串的追加字符后面已有'\0',便不再补'\0'）;
// 如果追加的字符，大于源字符串的字符个数，只把源字符串追加上去（不补'\0',源字符串中已有'\0'）（相当与追加'\0'）
// 源字符串最多追加到第一个'\0'处
//char arr1[36] = "abcdef";
//char arr2[] = "abcd\0abc";
//strncat(arr1, arr2, 6);
//此时只追加abcd\0;
//"abcdef\0\0\0\0\0\0\0"    "abc"
// "abcdefabc\0\0\0\0"，追加字符串的末尾已有'\0',便不在追加'\0'（也相当与追加'\0'）。
//
//char* mystrncat(char* dest, const char* src, size_t num)
//{
//	char* start = dest;
//	while (*dest != '\0')
//		dest++;
//	while (num && (*dest++ = *src++))
//		num--;
//	if (num == 0)
//		*dest = '\0';
//	return dest;
//}
//char* mystrncat(char* dest, const char* src, size_t num)
//{
//	char* start = dest;
//	while (*dest++)
//		;
//	dest--;
//	while (num--)
//		if (!(*dest++ = *src++))
//			return start;
//	*dest = '\0';
//	return start;
//}
//int main()
//{
//	char arr1[15] = "abcde\0xxxxxf";
//	char arr2[] =   "abcd\0";
//	mystrncat(arr1, arr2, 2);
//	printf("%s", arr1);
//	return 0;
//}
//NULL是空指针；NUL/Null是'\0'
// char*  strstr(const char* p1,const char* p2)
//  在字符串p1中查找p2，如果没找到返回NULL
//   如果找到了返回p1中查找到p2的字符串首元素地址
//   如果p1中出现多次p2，则返回第一次出现p2的字符串的首元素地址。

//const char* mystrstr(const char* p1, const char* p2)
//{
//	assert(p1 && p2);
//	const 	char* a1 = 0;
//	const   char* a2 = p2;
//	if (*p2 == '\0')
//		return p1;
//	while (*p1)
//	{
//		while (*p1 != *p2)
//		{
//			if (*p1 == '\0')
//				return NULL;
//				p1++;
//		}
//		a1 = p1;
//		while (*p1== *p2)
//		{
//			if (*p2=='\0')
//				return a1;
//			p1++;
//			p2++;
//		}	
//		if (*p1 == '\0')
//			return NULL;
//		if (*p2=='\0')
//			return a1;
//		p1 = a1 + 1;
//		p2 = a2;
//
//	}
//	return NULL;
//}
//const char* mystrstr(const char* p1, const char* p2)
//{
//	assert(p1 && p2);
//	const char* a1 = p1;
//	const char* a2 = p2;
//	if (!(*p2))
//		return p1;
//	while (*p1)
//	{	a1 = p1;
//		p2 = a2;
//		while (*p1 && *p2 && !(*p1 - *p2))
//		{
//			p1++;
//			p2++;
//		}
//		if (!(*p2))
//			return a1;
//		if (!(*p1))
//			return NULL;
//		p1 = a1;
//		p1++;
//	}
//	return NULL;
//}
//int main()
//{
//	const char* p1 = "abbbcccss";
//	const char* p2 = "ss";
//	const char* ret = mystrstr(p1, p2);
//	if (ret == NULL)
//		printf("no\n");
//	else
//		printf("%s\n", ret);
//
//	return 0;
//}
//char* strtok( char* str ,const char* sep)
//第一个参数指定一个字符串，它包含了O个或者多个由sep字符串中一个或者多个分隔符分割的标记。
//strtok函数找到str 中的下一个标记，并将其用\0结尾，返回一个指向这个标记的指针。（注：strtok函数会改变被操作的字符串，所以在使用strtok函数切分的字符串一般都是临时拷贝的内容并目可修改。〕
//strtok函数的第一个参数不为 NULL，函数将找到str中第一个标记，strtok函数将保存它在字符串中的位置。
//strtok函数的第一个参数为 NULL，函数将在同一个字符串中被保存的位置开始，查找下一个标记。
//如果字行串中不存在更多的标记，则返回 NULL指针
//int main()
//{
//	char arr[] = "2824497907@QQ.com";
//	const  char* p = "@.";
//	char buf[20] = "0";
//	strcpy(buf, arr);
//	char* ret = strtok(buf, p);//只传入一次buf，下一次调用直接传NULL，函数会记住buf第一个标记的地址。
//	                           //下一次调用直接从第一个标记开始向后寻找标记（如果之后没有标记返回NULL）。
//	                           //第一次调用返回字符串首元素地址，之后的调用返回上一个标记的地址
//	while (ret != NULL)
//	{
//		printf("%s\n", ret);
//		ret = strtok(NULL, p);
//	}
//
//	return 0;
//}
//char* strerror(int errnum)
//返回错误码所对应的错误信息
//errno是一个全局错误码的变量。需要头文件<errno.h>
//当c语言的库函数在执行过程中发生了错误，就会把对应的错误码赋值到errno中
//#include<errno.h>
//int main()
//{
//	FILE* p = fopen("text.c", "r");//fopen打开文件的函数，text.c是文件名，r是阅读。打开失败返回NULL
//	if (p == NULL)
//		printf("%s\n", strerror(errno));
//	return 0;
//}
//typedef struct Stu {
//	char name[20];
//	int age;
//
//}Stu;
//
//void* mymemcpy(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//	char* src1 = (char*)dest;
//	char* src2 = (char*)src;
//	while (num--)
//	{
//		*src1++ = *src2++;
//	
//	}
//	return dest;
//}
//void* mymemmove(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//	char* src1 = (char*)dest;
//	char* src2 = (char*)src;
//	if (src2 < src1)//当dest和src重叠时，src的地址小于dest，则从后向前拷贝
//	{
//		while (num--)
//		{
//			*(src1+num) = *(src2+num);
//			
//		}
//	}
//	if (src2 > src1)//当dest和src重叠时，src的地址大于dest，则从后向前拷贝
//	{
//		while (num--)
//		{
//			*src1++ = *src2++;
//		}
//	}
//	return dest;
//
//}
//int main()
//{
//	int i = 0;
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[5] = { 0 };
//	Stu s1[] = { {"只能",20},{"上课",123} };
//	Stu s2[3] = { 0 };
//	mymemmove(arr1, arr1+2, 20);
//	for (i = 0; i < 10; i++)
//		printf("%d\n", arr1[i]);
//	//mymemcpy(arr2, arr1, sizeof(arr2));
//	//mymemcpy(s2, s1, sizeof(s1));
//	return 0;
//}
// c语言标准memcpy只需要完成不重叠的内存拷贝即可；
// memmove既可以完成重叠的内存拷贝，也可以完成不重叠的内存拷贝
// void* memcpy(void* dest, const void* src, size_t num)
// 先将dest，和src强制转换为char*类型在进行一个一个字节拷贝
// 从src中复制num个字节的内容到dest中（遇到\0不会停止）
// src和dest尽量不重叠
// void* memmove(void* dest, const void* src, size_t num)
//在memcpy的基础上可以进行重叠的内存拷贝
//
//int memcmp(const void* ptr1,const void* ptr2,size_t num)
//比较从ptr1和ptr2开始的num个字节。
//返回类型与strcmp一致
//void* memset（void* destination，int character，size_t count）(要存放的地址，存放的字符的ASCII值，设置多少个字符（单位字节）)
int main()
{
	int arr[10] = {0};
	char arr1[20] = "";
	memset(arr1, '&', 10);
	printf("%s\n", arr1);
	memset(arr, 1, 10);//本质是设置10个字节的1，01 01 01 01 01 01 01 01 01 01 00 00 00..... 并不是设置10个整型1；
   return 0;
}

