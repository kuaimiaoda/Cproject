#include <stdio.h>
#include <string.h>
#include "graph.h"


int main() {
    struct UndirectedGraph graph = {0,0,{'\0'},0};
    char point[10],p1[10],p2[10];
    int deg_point,sum,max;

    //无向图的输入
    input(&graph);

    //求某个顶点度数
    printf("请输入求度数的顶点：");
    scanf("%s",point);
    deg_point = deg(point,&graph);
    printf("%s度数为：%d\n",point,deg_point);

    //求度数之和
    sum = sum_deg(&graph);
    printf("各个结点度数之和为:%d\n",sum);

    //求最大度数
    max = max_deg(&graph);
    printf("结点度数最大值为:%d\n",max);

    //是否为邻接点
    printf("请输入要判断邻接点的两个点：");
    scanf("%s %s",p1,p2);
    AdjacencyPoints(p1,p2,&graph);
    return 0;
}
