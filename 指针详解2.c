#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//void bubble_sort(int arr[], int sz)
//{
//	int tmp = 0;
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		j = 0;
//		for (j = 0; j < sz - i - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//
//	}
//}
//int main()
//{
//	int i = 0;
//	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//		printf("%d ", arr[i]);
//	printf("\n");
//	bubble_sort(arr,sz);
//	for (i = 0; i < sz; i++)
//		printf("%d ", arr[i]);
//
//
//
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	void* p = &a;//void*类型的指针可以接收任意类型的元素地址。
//	   p = p + 1;//void*类型的指针不能进行+-整数的运算
//		* p = 10;//void*类型的指针不能解引用。
//
//	return 0;
//}
//void qsort (void* base, size_t num, size_t size, int (*compar)(const void*,const void*));库函数qsort声明
//void* base:Pointer to the first object of the array to be sorted, converted to a void*.是需要排序的数组。
//num:Number of elements in the array pointed to by base，数组中的元素个数
//size：Size in bytes of each element in the array.数组中每个元素的大小（字节）。
//*compar:     Pointer to a function that compares two elements.//函数指针指向一个可以比较两个元素的函数
//This function is called repeatedly by qsort to compare two elements.It shall follow the following prototype。
//int compar(const void* p1, const void* p2);//比较函数的声明
//Taking two pointers as arguments(both converted to const void*).The function defines the order of the elements by returning(in a stableand transitive manner) :
//	return valuemeaning
//	< 0	The element pointed to by p1 goes before the element pointed to by p2，//p1<p2,返回<0
//	0	The element pointed to by p1 is equivalent to the element pointed to by p2,//p1==p2,返回0
//	>0	The element pointed to by p1 goes after the element pointed to by p2,//p1>p2,返回>0
#include<string.h>
//typedef struct Stu
//{
//char name[10];
//	int age;
//}Stu;
//int sort_int(const void* p1, const void* p2)
//{
//	return (*(int*)p1) - (*(int*)p2);//p1-p2,是由大到小
//	                                 //p2-p1,是由小到大
//}                                    //void*，不能解引用，所以要强制类型转换为需要的类型。
//int sort_float(const void* p1, const void* p2)
//{
//	/*if (((*(float*)p1) - (*(float*)p2)) > 0)
//		return 1;
//	else if (((*(float*)p1) - (*(float*)p2)) < 0)
//		return -1;
//	else
//		return 0;*/
//	return (int)((*(int*)p1) - (*(int*)p2));//float相减是得到的是float，但函数的返回类型是int，会丢失数据，所以要把float相减的结果强制转换为int
//}
//int sort_age(const void* p1, const void* p2)
//{
//	return ((Stu*)p1)->age - ((Stu*)p2)->age;
//
//}
//int sort_name(const void* p1, const void* p2)
//{    //p1，p2都指向的是一个字符数组，还要匹配strcmp的参数类型。
//	return strcmp(((Stu*)p1)->name, ((Stu*)p2)->name);
//	return  strcmp(*(const char(*)[])p1, *(const char(*)[])p2);
//	//int strcmp(const char* str1,const char * str2)
//	 //比较字符串用strcmp，str1的第一个字符和str2的第一个字符不相同，而且str1的第一个字符的值（ASCII）大于str2的第一个字符的值（ASCII）,返回>0
//    //两个字符串的字符完全相同，返回0
//	//str1的第一个字符和str2的第一个字符不相同，而且str1的第一个字符的值（ASCII）小于str2的第一个字符的值（ASCII）,返回<0
//}
//int main()
//{
//	int i = 0;
//	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	float f[5] = { 9.0,7.0,5.0,3.0,1.0 };
//	Stu s[3] = { {"zhangsan",20},{"lisi",10},{"wangwu",30} };
//	int (*compar)(const void*, const void*) = sort_int;
//	int (*compar1)(const void*, const void*) = sort_float;
//	int (*compar2)(const void*, const void*) = sort_age;
//	int (*compar3)(const void*, const void*) = sort_name;
//	qsort(arr, 10, sizeof(arr[0]),compar);
//	qsort(f, 5, sizeof(f[0]), compar1);
//	qsort(s, 3, sizeof(s[0]), compar2);
//	qsort(s, 3, sizeof(s[0]), compar3);
//	for (i = 0; i < 10; i++)
//		printf("%d ", arr[i]);
//	printf("\n");
//	for (i = 0; i < 5; i++)
//		printf("%f ", f[i]);
//	printf("\n");
//	for (i = 0; i < 3; i++)
//		printf("%d ", s[i].age);
//	printf("\n");
//	for (i = 0; i < 3; i++)
//		printf("%s ", s[i].name);
//
//	return 0;
//}
//typedef struct Stu
//{
//	char name[10];
//	int age;
//}Stu;
//int compare_int(void* x, void* y)
//{
//	return *(int*)x - *(int*)y;
// }
//void swap(char* x, char* y,int width)
//{
//	int i = 0;
//	char tmp = 0;//x，y的类型都是char*，每次访问一个字节，如果要交换int类型元素的值，每次访问一个字节，需要访问4次即元素的字节大小，知道元素的字节大小，就可以交换元素的值。
//	for (i = 0; i < width; i++)
//	{
//		tmp = *x;
//		*x = *y;
//		*y = tmp;
//		x++;//
//		y++;//得到下一个地址。
//	}
//}
//void bubble_sort(void* base, int sz, int width, int (*compare)(void* , void* ))//不知道要排序的数组，数组中的元素类型，所以都用void*，来放置它们的地址
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (compare((char*)base+j*width,(char*)base+(j+1)*width)> 0)//因为不知道要排序数组的类型，但知道里要数组里元素所占的字节大小，所以把base强制转换为char*，char*每次访问一个字节，步长为一个字节，每次加上元素所占用字节大小就可得到下一个元素的地址。base+width,得到第二个元素的地址。
//				swap((char*)base + j * width, (char*)base + (j+ 1) * width,width);//交换元素的值。
//		}
//	}
//}
//void test1()
//{
//	int i = 0;
//	int arr[5] = { 5,4,3,2,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr,sz,sizeof(arr[0]),compare_int);
//	for (i = 0; i < sz; i++)
//		printf("%d ", arr[i]);
//}
//int compare_float(void* x, void* y)
//{
//	return (int)(*(float*)x - *(float*)y);
//}
//void test2()
//{
//	int i = 0;
//	float f[5] = { 9.0,7.0,5.0,3.0,1.0 };
//	int sz = sizeof(f) / sizeof(f[0]);
//	bubble_sort(f, sz, sizeof(f[0]), compare_float);
//	for (i = 0; i < sz; i++)
//		printf("%f ", f[i]);
//}
//int compare_age(void* x, void* y)
//{
//
//	return (((Stu*)x)->age - ((Stu*)y)->age);
//}
//void test3()
//{
//	int i = 0;
//	Stu s[3] = { {"zhangsan",20},{"lisi",10},{"wangwu",30} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	bubble_sort(s, sz, sizeof(s[0]), compare_age);
//	for (i = 0; i < sz; i++)
//		printf("%d  ", s[i].age);
//}
//int compare_name(void* x, void* y)
//{
//	//return strcmp(((Stu*)x)->name, ((Stu*)y)->name);//运用指针
//	//return strcmp((char*)x, (char*)y);//参数是const char*
//	return strcmp(*(char(*)[])x, *(char(*)[])y);//参数是字符数组指针，解引用
//	//三种方法都行
//}
//void test4()
//{
//	int i = 0;
//	Stu s[3] = { {"zhangsan",20},{"lisi",10},{"wangwu",30} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	bubble_sort(s, sz, sizeof(s[0]), compare_name);
//	for (i = 0; i < sz; i++)
//		printf("%s  ", s[i].name);
//}
//
//int main()
//{
//	//test1();
//	//test2();
//	//test3();
//	test4();
//	
//	return 0;
//}
//数组名是整个数组的情况
//sizeof(数组名)。sizeof(数组名+1),此处的数组名表示首元素地址。
//&数组名。
//int main()
//{
//	int a[4] = { 0 };
//	printf("%d\n", sizeof(a));//16，a表示整个数组
//	printf("%d\n", sizeof(a+0));//4/8，a表示首元素地址
//	printf("%d\n", sizeof(*a));//4，a表示首元素地址，*a==a[0]
//	printf("%d\n", sizeof(a+1));//4/8，a表示首元素地址，a+1==&a[1]
//	printf("%d\n", sizeof(a[1]));//4
//	printf("%d\n", sizeof(&a));//&a,表示整个数组的地址，地址的大小是4/8
//	printf("%d\n", sizeof(*&a));//16，&a,表示整个数组的地址，*&a表示整个数组
//	printf("%d\n", sizeof(&a+1));//&a+1,表示跳过整个数组的地址（&a[5]），地址的大小是4/8
//	printf("%d\n", sizeof(&a[0]));//4/8
//	printf("%d\n", sizeof(&a[0]+1));//4/8
//	return 0;
//}
void main()
{
	char arr[] = { 'a','b','c','d','f' };
	printf("%d\n", strlen(arr));//随机值;arr是首元素的地址，strlen计算'\0'之前的字符串长度。
	printf("%d\n", strlen(arr+0));//随机值;arr是首元素的地址，arr+0还是首元素的地址
	//printf("%d\n", strlen((char*)*arr));//error，*arr是'a'(ASCII： 97),将97看作地址，去访问，越界访问
	//printf("%d\n", strlen((char*)arr[1]));//error，arr[1]是'b'(ASCII： 98),将98看作地址，去访问，越界访问
	printf("%d\n", strlen((char*)&arr));//随机值 ；&arr,是整个数组的地址，但整个数组的地址还是从arr开始的，
	printf("%d\n", strlen((char*) & arr + 1));//随机值-5；&arr+1是arr[5]的地址.
	printf("%d\n", strlen(&arr[0]+1));//随机值-1；&arr[0]+1是arr[1]的地址。
}