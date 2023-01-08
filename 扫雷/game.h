#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_count 10
#define HARD_count  50
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void initialboard(char board[ROWS][COLS], int row, int col, char set);
void displayboard(char board[ROWS][COLS], int row, int col);
void set_mine(char board[ROWS][COLS], int row, int col);
void find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
int search_mine(char mine[ROWS][COLS], int x, int y);
void convert(char mine[ROWS][COLS], char show[ROWS][COLS], int x,int y,int* count);