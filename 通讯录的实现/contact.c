#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"

void check(struct cn* ps)
{
	struct peopleinfo* pp=NULL;
	if (ps->size == ps->capacity)
	{
		pp = (struct peopleinfo*)realloc(ps->con, (ps->capacity + 2) * sizeof(struct peopleinfo));
		if (pp == NULL)
			return;
		else
		{
			ps->con = pp;
			ps->capacity += 2;
			printf("增容成功\n");
		}
	}
}
static int find(const struct cn* ps,char* name)//加上static只能在contact.cpp内使用
{
	int i = 0;
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
		return -1;
	}
	else
	{
	
		while (strcmp(name, ps->con[i].name) != 0)
		{
			i++;

		}
		if (i == name_max)
		{
			printf("不存在\n");
			return -1;
		}
		return i;
	}
}
void init(struct cn* ps)
{
	ps->con = (struct peopleinfo*)malloc(DEFAULT_SZ*sizeof(struct peopleinfo));
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;
	loadcontact(ps);
}
void loadcontact(struct cn* ps)
{
	peopleinfo tmp = { 0 };
	FILE* pf = fopen("contact.dat", "rb");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	while (fread(&tmp, sizeof(peopleinfo), 1, pf))//fread的返回值是实际读取到元素个数，当返回值为0，表明读取完了。
	{                                              //将文件中的信息读取到程序中
		check(ps);
		ps->con[ps->size] = tmp;
		ps->size++;
	}
	fclose(pf);
	pf = NULL;
}
void add_info(struct cn* ps)
{
	    check(ps);
		printf("请输入名字\n");
		scanf("%s", ps->con[ps->size].name);
		printf("请输入地址\n");
		scanf("%s", ps->con[ps->size].addr);
		printf("请输入性别\n");
		scanf("%s", ps->con[ps->size].sex);
		printf("请输入电话号码\n");
		scanf("%s", ps->con[ps->size].tele);
		printf("请输入年龄\n");
		scanf("%d", &(ps->con[ps->size].age));
		(ps->size)++;
		printf("添加成功\n");
	
}
void show_info(const struct cn* ps)
{       int i = 0;
		printf("%-4s\t%-10s\t%-6s\t%-3s\t%-3s\t", "姓名", "电话", "地址", "年龄", "性别");
		printf("\n");
		for (i = 0; i < ps->size; i++)
		{
			if (ps->con[i].age == 0)
				break;
			printf("%-4s\t%-10s\t%-6s\t%-3d\t%-3s\t", ps->con[i].name
				, ps->con[i].tele
				, ps->con[i].addr
				, ps->con[i].age
				, ps->con[i].sex);
			printf("\n");
		}
		printf("\n");

}
void del_info(struct cn* ps)
{
	int i = 0;
	char arr[name_max] = { 0 };
	printf("请输入要删除的人员的姓名:>");
	scanf("%s", arr);
	i = find(ps, arr);
		if (i == -1)
			printf("查找失败\n");
		else
		{
		
			memmove(&(ps->con[i]), &(ps->con[i]) + 1, (ps->size - i-1) * sizeof(ps->con[i]));
			memset(&(ps->con[ps->size]), 0, sizeof(ps->con[ps->size]));
			(ps->size)--;
			printf("删除成功\n");
		}
}
void search_info(const struct cn* ps)
{
	int i = 0;
	char arr[name_max] = { 0 };
	printf("请输入要查找的人员的姓名:>");
	scanf("%s", arr);
	i = find(ps, arr);
   if (i == -1)
		printf("查找失败\n");
	else
	{
		printf("%-4s\t%-10s\t%-6s\t%-3s\t%-3s\t", "姓名", "电话", "地址", "年龄", "性别");
		printf("\n");
		printf("%-4s\t%-10s\t%-6s\t%-3d\t%-3s\t", ps->con[i].name
			, ps->con[i].tele
			, ps->con[i].addr
			, ps->con[i].age
			, ps->con[i].sex);
		printf("\n");
		printf("查找成功\n");
	}
}
void mod_info( struct cn* ps)
{

	int i = 0;
	char arr[name_max] = { 0 };
	printf("请输入要修改的人员的姓名:>");
	scanf("%s", arr);
	i = find(ps, arr);
	if (i == -1)
		printf("查找失败\n");
	else
	{	printf("请输入名字\n");
		scanf("%s", ps->con[i].name);
		printf("请输入地址\n");
		scanf("%s", ps->con[i].addr);
		printf("请输入性别\n");
		scanf("%s", ps->con[i].sex);
		printf("请输入电话号码\n");
		scanf("%s", ps->con[i].tele);
		printf("请输入年龄\n");
		scanf("%d", &(ps->con[i].age));
		printf("修改成功\n");
	}
}
void sort_info(struct cn* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int j = 0;
		struct peopleinfo tmp = { 0 };
		int i = 0;
		for (i = 0; i < (ps->size - 1); i++)
		{
			               j = 0;
			for (j = 0; j < (ps->size - 1 - i); j++)
				if (ps->con[j].age > ps->con[j + 1].age)
				{
					tmp = (ps->con[j]);
					ps->con[j] = ps->con[j + 1];
					ps->con[j + 1] = tmp;

				}
		}
		printf("分类成功\n");
	}

}
void destorycontact(struct cn* ps)
{
	free(ps->con);
	ps->con = NULL;
}
void savecontact(const struct cn* ps)
{
	int i = 0;
	FILE* pf = fopen("contact.dat", "wb");
	for(i=0;i<ps->size;i++)
	fwrite(&ps->con[i], sizeof(peopleinfo), 1, pf);//将通讯录中的内容存入到文件中
	fclose(pf);
	pf = NULL;
	printf("保存成功\n");
}