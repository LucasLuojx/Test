#define _CRT_SECURE_NO_WARNINGS 1
 
#define ROW 9//行
#define COL 9//列
 
#define ROWS ROW+2
#define COLS COL+2
 
#define EASY 10//雷的个数
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
void menu();//打印开始页面
 
void game();//
 
void inti_board(char board[ROWS][COLS], int row, int col, char set);//初始化布雷棋盘
 
void print(char board[ROWS][COLS], int row, int col);//打印函数
 
void Set_Mine(char arr[ROWS][COLS], int row, int col);//放雷
 
void Find_Mine(char arr1[ROWS][COLS], char arr2[ROWS][COLS], int row, int col);//找雷
 
int COUNT_MINE(char arr1[ROWS][COLS], int x, int y);
 
 
 