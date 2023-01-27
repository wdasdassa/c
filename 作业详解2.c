#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//void reverse(char* p)
//{
//	char tmp = 0;
//	int sz = strlen(p);
//	if (sz == 1)
//		return ;
//	tmp = p[0];
//	p[0] = p[sz - 1];
//	p[sz - 1] = '\0';
//	reverse(p + 1);
//	p[sz - 1] = tmp;
//}
//void reverse1(char* p,int sz)
//{
//	int i = 0;
//	char p1[12] = { 0 };
//	for (i = 0; i < sz-1 ; i++)
//		p1[i] = p[sz-2-i];
//	for (i = 0; i < sz ; i++)
//		p[i] = p1[i];
//}
//void reverse(char* str)
//{
//	char tmp = 0;
//	int sz = strlen(str);
//	int left = 0;
//	int right =sz;
//	while (left <= right)
//	{
//		tmp = str[right - 1];
//		str[right - 1] = str[left];
//		str[left] = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char p[] = "hello world";
//	//int sz = sizeof(p) / sizeof(p[0]);
//	scanf("%s", p);
//	reverse(p);
//	printf("%s\n", p);
//	//reverse1(p,sz);
//	//printf("%s", p);
//	return 0;
//}
//求2+22+222+2222+22222
//int main()
//{
//	int sum = 0;
//	int a = 0;
//	int n = 0;
//	int i = 0;
//	int ret = 2;
//	scanf("%d%d", &a, &n);
//	for (i = 0; i < n; i++)
//	{
//		sum = sum + a;
//		a = a * 10 + ret;
//
//    }
//	printf("%d", sum);
//
//	return 0;
//}
//int compare(int u, int arr[],int count)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < count; i++)
//	{
//		if (arr[i] == u)
//			j++;
//	}
//	return j;
//}
//
//int mul(int num, int n)
//{
//	if (num == 0)
//		return 0;
//	if (n == 1)
//		return num;
//	return num * mul(num, n - 1);
//}
//int cal(int i)
//{
//	if (i / 10 == 0)
//		return 1;
//	else
//		return 1 + cal(i / 10);
//}
//int compute(int i, int n)
//{
//	int sum = 0;
//	int ret = n;
//	while (n)
//	{
//		sum = sum + mul(i % 10, ret);
//		i = i / 10;
//		n--;
//	}
//	return sum;
//}
//
//int main()
//{
//	int i = 0;
//	int n = 0;
//	int re = 0;
//	int  u = 0;
//	int count = 0;
//	int arr[20] = { 0 };
//	printf("please imput your num:\n");
//	scanf("%d", &u);
//	for (i = 0; i <= 100000; i++)
//	{
//		n = cal(i);
//		re = compute(i, n);
//
//		if (re == i)
//		{
//			arr[count] = i;
//			//printf("%d ", i);
//			count++;
//		}
//	}
//	if (compare(u,arr,count) == 1)
//		printf("YES\n");
//	else
//		printf("NO\n");
//
//	return 0;
//}
//#include<math.h>
//int main()
//{
//	int sum = 0;
//	int tmp = 0;
//	int n = 0;
//	int i = 0;
//	for (i = 0; i <= 100000; i++)
//	{
//		n = 1;
//		sum = 0;
//		tmp = i;
//		while (tmp/=10)
//		{
//			n++;
//		}
//		tmp = i;
//		while (tmp)
//		{
//			sum +=(int) pow(tmp % 10, n);
//			tmp /= 10;
//		}
//		if (sum == i)
//			printf("%d ", i);
//		
//	}
//	return 0;
//}
//int main()
//{
//	int left = 6;
//	int right = 6;
//	int i = 0;
//	char arr[14] = "             ";
//	while (left>=0)
//	{
//		arr[left] = '*';
//		arr[right] ='*';
//		printf("%s\n", arr);
//		if (left == 0)
//			break;
//		left--;
//		right++;
//	}
//	while (left < 6)
//	{
//		arr[left] = ' ';
//		arr[right] = ' ';
//		left++;
//		right--;
//		printf("%s\n", arr);
//	}
//	return 0;
//}
//int main()
//{
//	int j = 0;
//	int i = 0;
//	int line = 0;
//	scanf("%d", &line);
//	for (i = 0; i < line; i++)
//	{
//		j = 0;
//		for (j = 0; j < line - 1 - i; j++)
//			printf(" ");
//		for (j = 0; j < 2 * i + 1; j++)
//			printf("*");
//		printf("\n");
//	}
//	for (i = 0; i < line - 1; i++)
//	{
//		j = 0;
//		for (j = 0; j < i + 1; j++)
//			printf(" ");
//		for (j = 0; j < 2 * (line - 1 - i) - 1; j++)
//			printf("*");
//		printf("\n");
//	}
//	return 0;
//}
//int main()
//{
//	int total=0;
//	int empty = 0;
//	int money = 0;
//	scanf("%d", &money);
//	total = 2 * money - 1;
//	/*total = money;
//	empty = money;
//	money = 0;
//	while (empty > 1)
//	{
//		total += empty / 2;
//		empty = empty / 2 + empty % 2;
//	}*/
//	printf("total==%d", total);
//	return 0;
//}
//void adjust(int arr[],int sz)
//{
//	int tmp = 0;
//	int i = 0;
//	int right = sz - 1;
//	int left = 0;
//	while (left <right)
//	{
//		while ((left <= right)&&arr[left] % 2 == 1)//条件不满足找到偶数。如果不加(left <= right)数组是全奇数,left最终大于right，造成错误。
//			left++;//从左边查找偶数
//		while ((left <= right) && arr[right] % 2 == 0)
//			right--;//从右边查找奇数
//		tmp = arr[right];
//		arr[right] = arr[left];
//		arr[left] = tmp;//交换
//		
//	}
//}
////让一个整数数组的偶数放在数组的后半部分。奇数放在数组的前半部分。
//int main()
//{
//	int i = 0;
//	int arr[] = { 1,3,5,7,9 };
//    int sz = sizeof(arr) / sizeof(arr[0]);
//	adjust(arr,sz);
//	for (i = 0; i < sz; i++)
//		printf("%d ", arr[i]);
//	return 0;
//}
//int main()
//{
//	unsigned char a = 200;//11001000
//	unsigned char b = 100;//01100100
//	unsigned char c = 0; //100101100
//	c = a + b;//00101100 44
//	printf("%d ,%d", a + b, c);
//	//a+b,无符号高位补0
//	// 00000000000000000000000011001000
//	// 00000000000000000000000001100100
//	// 00000000000000000000000100101100
//	//300
//	return 0;
//}
//0x00001234   00 00 12 34
//打印杨辉三角形
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int arr[10][10] = { 0 };
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j < 100; j++)
//		{
//			if (j == 0)
//				arr[i][j] = 1;
//			if (i == j)
//				arr[i][j] = 1;
//		}
//	}
//	for (i = 2; i < 10; i++)
//	{
//		for (j = 1; j < i; j++)
//		{
//			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//
//		}
//
//	}
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j < 10; j++)
//		{
//			if (arr[i][j] == 0)
//				break;
//			printf("%-3d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//int main()
//{
//	char terror= 'A';
//	int i = 0;
//	int count = 0;
//	for (i = 0; i < 4; i++)
//	{
//		count = 0;
//		terror = 'A';
//		terror = terror +i;
//		if (terror != 'A')
//			count++;
//		if (terror == 'C')
//			count++;
//		if (terror == 'D')
//			count++;
//		if (terror != 'D')
//			count++;
//		if (count == 3)
//			break;
//	}
//	printf("凶手是%c", terror);
//
//	return 0;
//}
//int main()
//{
//	char killer = 'A';
//	for(killer='A';killer<='D';killer++)
//		if((killer!='A')+(killer=='D')+(killer=='C')+(killer!='D')==3)
//			printf("凶手是%c", killer);
//
//	return 0;
//}
//赛马问题
//一共有36匹马，6个跑道，没有计算器，如何找到36匹马的前三名
//把36匹马分为6组，进行6次比赛；
//得到6组中各个马的名次
//1 1 1 1 1 1
//2 2 2 2 2 2
//3 3 3 3 3 3 
//4 4 4 4 4 4
//5 5 5 5 5 5
//6 6 6 6 6 6
//让每组的第一名组成一组进行比赛；
//再次得到这一组的各个马名次 1 2 3 4 5 6；
//再让 第一名马的这一组的前三名，第二名这一组的前两名，第三名组成一组进行比赛。（第一名已经确定，可以只比较5匹马）
//一共需要进行8次；
//第一名这一组的第二和第三可能比第二名和第三名跑的快；
//第二名这一组的第二可能比第三名跑的快；
//所以需要进行比较一次。
//有一种香，材质不均匀。一根这样的香，燃烧完恰好是一个小时，
//现在有两根这样的香，确定15分钟的时间；
//先点燃一个香的两端，并点燃另一根香的一段；
// 当点燃两段的香燃烧结束（燃烧半个小时）后，另一个香燃烧半个小时。
// 此时把另一支香的另一端点燃，这支香燃烧的时间便是15分钟。
//#include<string.h>
//char* revolve(char* arr,int k,int sz)
//{
//	int i = 0;
//	char arr2[20] = "0";
//	for (i = k; i < sz; i++)
//	{
//		arr2[i - k] = arr[i];
//
//	}
//	for (i = 0; i < k; i++)
//	{
//		arr2[sz - k+i] = arr[i];
//	}
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = arr2[i];
//	}
//	return arr;
//}
//
//int main()
//{
//	char arr[20] = "0";
//	int k = 0;
//	scanf("%d%s", &k, &arr);
//	int sz = strlen(arr);
//	printf("%s", revolve(arr, k,sz));
//
//	return 0;
//}
//#include<assert.h>
//void left_move(char* arr, int k,int sz)
//{
//	assert(arr != NULL);
//	int i = 0;
//	char tmp = 0;
//	if (k == 0)
//		return ;
//	tmp = arr[0];
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = arr[i + 1];
//
//
//	}
//	arr[sz - 1] = tmp;
//	left_move(arr, k - 1,sz);
//	//arr[sz-k]=tmp;
//}
//int main()
//{
//	char arr[] = "abcdefg";
//	int sz = strlen(arr);
//	left_move(arr,2,sz);
//	printf("%s", arr);
//
//
//}
//void left_move(char* arr, int k)
//{
//	int j = 0;
//	int len = strlen(arr);
//	int i = 0;
//	char tmp = '0';
//	for (i = 0; i < k; i++)
//	{
//		tmp = arr[0];
//		for (j = 0; j < len-1; j++)
//		{
//			arr[j] = arr[j + 1];
//		}
//		arr[len - 1] = tmp;
//	}
//
//}
//int main()
//{
//	char arr[] = "abcdefg";
//	int sz = strlen(arr);
//	left_move(arr, 2);
//	printf("%s", arr);
//
//
//}
//三步逆序法
//ab  cde
//ba  edc第一步逆序ab，cde
//baedc 第二步逆序bacde
//cdeab  第三步得到结果
void reverse(char* arr)
{
	char tmp = '0';
	int len =strlen(arr);
	tmp = arr[0];
	if (strlen(arr) == 0 || strlen(arr) == 1)
		return ;
	arr[0] = arr[len - 1];
	arr[len - 1] = '\0';
	reverse(arr+1);
	arr[len - 1] = tmp;
}
#include<assert.h>
void left_move(char* arr, int k)
{
	assert(k <= strlen(arr));
	char tmp = arr[k];
	arr[k] = '\0';
	reverse(arr);
		arr[k] = tmp;
	reverse(arr + k);
	reverse(arr);
}
//int main()
//{
//	int k = 4;
//	char arr[] = "abcdef";
//	left_move(arr, k);
//	printf("%s", arr);
//	return 0;
//}
//int is_left_move(char* s1, char* s2)
//{
//	int len = strlen(s1);
//	int k = 0;
//	 char* m = 0;
//	for (k = 0; k <= len; k++)
//	{
//		left_move(s1, 1);//left_move(s1, k);//每次进入函数s1的值都会改变，每次旋转一个，都进行比较。
//		if (strcmp(s1, s2) == 0)
//			return 1;
//		         //left_move(s1, len-k);改变后再旋转回来
//	}
//		return 0;
//
//}
//int main()
//{
//	 char s1[] = "abcdefg";
//	 char s2[] = "fgabcde";
//	int m=is_left_move(s1, s2);
//	if (m == 1)
//		printf("YES\n");
//	else
//		printf("NO\n");
//
//
//	return 0;
//}
//int is_left_move(char* arr1,char* arr2)
//{
//	int len1 = strlen(arr1);
//	int len2 = strlen(arr2);
//	if (len1 != len2)
//		return 0;
//	//strcat(char* destination,const char* resource);追加字符串
//	//例
//	//arr1="abc\0" 
//	//arr2="def\0" 
//	//将arr2追加到arr1的后面
//	// 将d放在\0,ef放在d的后面，最后将\0放在f的后面，结束；结束标志是找到'\0'，并追加到目标字符串的后面 
//	//对于追加自身字符串无法使用，
//	//arr1后面追加arr1
//	//将a放在\0,bc放在a的后面，此时arr1="abc('\0'被修改为'a')abc",arr1字符串的结尾没有\0，所以函数不会停止，直至找到'\0'，并将其追加到目标函数的后面
//	strncat(arr1, arr1, len1);//strncat可用于追加自身字符串，arr1是目标字符串，arr1是要追加的字符串，len1是追加的长度。
//	//strncat(char* destination,const char* resource,int size_t)
//	char* p=strstr(arr1, arr2);//strstr是在arr1中寻找子串，与arr2比较
//	                          //如果arr2是子串的话就返回子串的首元素的地址。
//	                          //不是就返回空指针（NULL）
//	if (p == NULL)
//		return 0;
//	else
//		return 1;
//}
//int main()
//{
//	char arr1[90] = "abcdef";
//	char arr2[] = "cdefab";
//	int ret=is_left_move(arr1, arr2);
//	if (ret == 1)
//		printf("YES\n");
//	else
//		printf("NO\n");
//	return 0;
//}
int fandnum(int arr[3][3], int k, int* px, int* py)
{
	int y = 0;
	int x = *py - 1;
	while (x>=0&&y<=2)
	{
		if (arr[x][y] > k)
			x--;
		else if (arr[x][y] < k)
			y++;
		else
		{
			*px = x;
			*py = y;
			return 1;

		}
	}
	return 0;
}
//1 3 5
//2 4 6
//8 9 10,用左下角（右上角）的数字来进行比较，来缩小范围。
int main()
{
	int arr[3][3] = { {1,3,5},{2,4,6},{8,9,10} };
	int k = 4;
	int x = 3;
	int y = 3;
	int ret = fandnum(arr,k,&x,&y);//返回式参数，传址参数
	if (ret == 1)
	{
		printf("找到了\n");
		printf("%d %d", x, y);
	}
	else
		printf("没找到\n");

	return 0;
}