#include <stdio.h>
#include "2048.h"

int main() {
    int b = 2;
    char keyboard;
    int **game;
    game = init();
    output(game);
    fflush(stdout);
    for(;b==2;)
   {
       keyboard = getchar();
       if(keyboard=='W'||keyboard=='w')
       {
           w(game);
           fflush(stdin);
       }
       else if(keyboard=='A'||keyboard=='a')
       {
           a(game);
           fflush(stdin);
       }
       else if(keyboard=='S'||keyboard=='s')
       {
           s(game);
           fflush(stdin);
       }
       else if(keyboard=='D'||keyboard=='d')
       {
           d(game);
           fflush(stdin);
       }
       else
           printf("输入有误，请重新输入！\n");
       b = over(game);
       output(game);
       fflush(stdout);
       random(game);
   }
    if(b == 1)
        printf("游戏胜利！");
    else
        printf("游戏失败！");
    return 0;
}
