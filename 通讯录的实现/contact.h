#pragma once
#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<stdlib.h>
#include<errno.h>
#define name_max 20
#define addr_max 20
#define tele_max 20
//#define  con_max 1000
#define DEFAULT_SZ 3
#define sex_max 20
 typedef struct peopleinfo {
	char name[name_max];
	char addr[addr_max];
	char tele[tele_max];
	char sex[sex_max];
	int age;
}peopleinfo;
enum option
{   EXIT,
    ADD,
	DEL,
	MODIFY,
	SHOW,
	SORT,
	SEARCH,
};
struct cn {
	struct peopleinfo* con;
	int size;
	int capacity;
};
void init(struct cn* ps);
void add_info(struct cn* ps);
void del_info(struct cn* ps);
void show_info(const struct cn* ps);
void search_info(const struct cn* ps);
void mod_info( struct cn* ps);
void sort_info(struct cn* ps);
void destorycontact(struct cn* ps);
void savecontact(const struct cn* ps);
void loadcontact(struct cn* ps);