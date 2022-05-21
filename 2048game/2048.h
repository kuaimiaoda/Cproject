#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define size 4

//初始化游戏界面
int **init() {
    int **game;
    int ranx, rany, i, j;
    game = (int **) malloc(size * sizeof(int *));
    for (i = 0; i < size; i++)
        game[i] = (int *) malloc(size * sizeof(int));
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            game[i][j] = 0;
    // 给出初始的3个数据
    for (i = 0; i < 3; i++) {
        // 确保每次生成不同的x，y坐标
        srand((unsigned) time(NULL) + i * (i + 1)); // 自创蒯氏算法随机数种子（防止for循环时间过短导致种子相同）
        ranx = rand() % size;
        rany = rand() % size;
        game[ranx][rany] = 2;
    }
    return game;
}

// 每一步结果展示
void output(int **game)
{
    int i,j;
    printf("-----------------\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++)
            if(game[i][j]==0)
                printf("|\t");
            else
                printf("|%2d ", game[i][j]);
        printf("|\n");
        printf("-----------------\n");
    }
    printf("\n");
}

// 随机数生成
void random(int **game)
{
    int ranx,rany,rannum,i = 0;
    do
    {
        srand((unsigned) time(NULL) + i * (i + 1));
        ranx = rand()%size;
        rany = rand()%size;
        i++;
    }while(game[ranx][rany] != 0);
    rannum = rand()%2;
    game[ranx][rany] = rannum*2+2;// rannum为0时为2，为1时为4
}

// 向左合并
void a(int **game) {
    int i, j, k;
    // 向左合并相同数字
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (game[i][j] != 0) {
                for (k = j + 1; k < size; k++)
                    if (game[i][j] == game[i][k])
                    {
                        game[i][j] *= 2;
                        game[i][k] = 0;
                    }
                    else if(game[i][k] == 0)
                        continue;
                    else
                        break;
            }
        }
    }
    // 靠左存放数据
    for (i = 0; i < size; i++) {
        k = 0;
        for (j = 0; j < size; j++)
            if (game[i][j] != 0) {
                game[i][k] = game[i][j];
                k++;
            }
        for (; k < size; k++)
            game[i][k] = 0;
    }
}

// 向右合并
void d(int **game)
{
    int i,j,k,q;
    // 左右数据对称互换
    for(i = 0;i<size;i++)
        for (j = 0,k = size-1; j<k; j++,k--)
        {
            q = game[i][j];
            game[i][j] = game[i][k];
            game[i][k] = q;
        }
    a(game);
    // 左右数据换回来
    for(i = 0;i<4;i++)
        for (j = 0,k = size-1; j<k; j++,k--)
        {
            q = game[i][j];
            game[i][j] = game[i][k];
            game[i][k] = q;
        }
}

// 向上合并
void w(int **game)
{
    int i,j,q;
    // 沿主对角线对称数据
    for(i = 0;i<size;i++)
        for (j = i; j < size; j++)
        {
            q = game[i][j];
            game[i][j] = game[j][i];
            game[j][i] = q;
        }
    a(game);
    // 数据换回来
    for(i = 0;i<size;i++)
        for (j = i; j < size; j++)
        {
            q = game[i][j];
            game[i][j] = game[j][i];
            game[j][i] = q;
        }
}

// 向下合并
void s(int **game)
{
    int i,j,q;
    // 沿次对角线对称数据
    for(i = 0;i<size;i++)
        for (j = 0; j < size-i; j++)
        {
            q = game[i][j];
            game[i][j] = game[size-1-j][size-1-i];
            game[size-1-j][size-1-i] = q;
        }
    a(game);
    // 数据换回来
    for(i = 0;i<size;i++)
        for (j = 0; j < size-i; j++)
        {
            q = game[i][j];
            game[i][j] = game[size-1-j][size-1-i];
            game[size-1-j][size-1-i] = q;
        }
}

// 满格时失败条件
int defeat(int **game)
{
/*
    返回值对应状态
    0       失败
    1       继续游戏
*/
    int i,j;
    for(i = 0;i<size-1;i++)
    {
        for(j = 0;j<size-1;j++)
            if(game[i][j] == game[i][j+1]||game[i][j] == game[i+1][j])
                return 1;
        if(game[i][size-1] == game[i+1][size-1])
            return 1;
    }
    return 0;
}

// 游戏结束条件的判断
int over(int **game)
{
/*
    返回值对应状态
    0       失败
    1       胜利
    2       继续游戏
 */
    int i,j;
    for(i = 0;i<size;i++)
        for (j = 0; j < size; j++)
        {
            if (game[i][j] == 2048)
                return 1;
            else if (game[i][j] == 0)
                return 2;
        }
    if(defeat(game) == 1)
        return 2;
    return 0;
}