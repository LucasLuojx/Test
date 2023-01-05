#define _CRT_SECURE_NO_WARNINGS 1
 
#include "game.h"
 
void menu(void)
{
    printf("***********************************\n");
    printf("******    1.paly       ************\n");
    printf("******    0.exit       ************\n");
    printf("***********************************\n");
 
}
 
void inti_board(char board[ROWS][COLS], int row, int col, char set)//初始化布雷棋盘
{
    int i = 0;
    int j = 0;
    for (i = 1; i <= row; i++)
    {
        for (j = 1; j <= col; j++)
        {
            board[i][j] = set;
        }
    }
}
 
void print(char board[ROWS][COLS], int row, int col)
{
    int i = 0;
    int j = 0;
    for (i = 0; i <= row; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 1; i <= row; i++)
    {
        printf("%d ", i);
        for (j = 1; j <= col; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
 
void Set_Mine(char arr[ROWS][COLS], int row, int col)//放雷
{
    int x = 0;
    int y = 0;
    int sz = EASY;
    while (sz)
    {
        x = rand() % row + 1;
        y = rand() % col + 1;
        if (arr[x][y] == '0')
        {
            arr[x][y] = '1';
            sz--;
        }
    }
 
 
}
 
int COUNT_MINE(char arr1[ROWS][COLS], int x, int y)
{
    return arr1[x - 1][y - 1] + arr1[x - 1][y] + arr1[x - 1][y + 1] +
        arr1[x][y - 1] + arr1[x][y + 1] +
        arr1[x + 1][y - 1] + arr1[x + 1][y] + arr1[x + 1][y + 1] - 8 * '0';
}
 
void Find_Mine(char arr1[ROWS][COLS], char arr2[ROWS][COLS], int row, int col)
{
    int x = 0;
    int y = 0;
    int sz = ROW * COL - EASY;//排除次数
 
    while (sz)
    {
        printf("请输入坐标->\n");
        scanf("%d %d", &x, &y);
        if (arr2[x][y] =='*')
        {
            if (arr1[x][y] == '1')
            {
                printf("你被炸死了，游戏结束！\n");
                 break;
            }
            else
            {
                int n = COUNT_MINE(arr1, x, y);
                arr2[x][y] =n+'0';
                sz--;
                print(arr2, ROW, COL);//打印人们看到的排雷盘*
            }
        }
        else
        {
            printf("坐标错误，请重新输入！\n");
        }
    }
        
 
    if (sz == 0)
    {
        printf("恭喜你成功通关!\n");
    }
    
}
 
void game()
{
    srand((unsigned int)time(NULL));
    char arr1[ROWS][COLS];//放雷0是安全，1是雷
    char arr2[ROWS][COLS];//表现出来让人们排雷的棋盘用*表示
 
    inti_board(arr1, ROW, COL, '0');//初始化雷盘
    inti_board(arr2, ROW, COL, '*');//初始化排雷界面
 
    Set_Mine(arr1, ROW, COL);//放雷
 
    //print(arr1, ROW, COL);//打印雷盘
    print(arr2, ROW, COL);//打印人们看到的排雷盘*
 
    Find_Mine(arr1,arr2, ROW, COL);//找雷
 
}
 