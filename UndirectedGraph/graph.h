//建立一个结构体 存储一个无向图（顶点数，边数，顶点名，矩阵）
struct UndirectedGraph {
    int point_num;
    int road_num;
    char point[20][10];//顶点
    int matrix[20][20];//矩阵
    const int *d;
};

//求各个顶点度数之和，结果存到数组中
int *deg_all(struct UndirectedGraph *g)
{
    int i ,j ;
    static int deg[20] = {0};
    for(i = 0;i<g->point_num;i++) //在第i行统计度数,输入到列表对应位置上
        for(j = 0;j<g->point_num;j++)
            if(g->matrix[i][j] != 0)
                deg[i]+=g->matrix[i][j];
    return deg;
}

//顶点与边的输入
void input(struct UndirectedGraph *g) {
    int i, j, k;
    char b[10] = {0};
    char a[10] = {0};
    printf("请输入顶点数量和边的数量：");
    setvbuf(stdout,NULL,_IONBF,0); //清楚缓存，使提示语先输出在输入数据
    scanf("%d %d", &g->point_num, &g->road_num);
    for (i = 0; i < g->point_num; i++)
    {
        printf("请输入第%d个顶点：",i+1);
        setvbuf(stdout,NULL,_IONBF,0);
        scanf("%s",g->point[i]);
    }
    for (i = 0; i < g->road_num; i++)
    {
        printf("请输入第%d条边：", i + 1);
        setvbuf(stdout,NULL,_IONBF,0);
        scanf("%s %s", a, b);
        //顶点与数组下标绑定
        for (j = 0; j < g->point_num; j++)
            if (strcmp(g->point[j], a) == 0)
                break;
        for (k = 0; k < g->point_num; k++)
            if (strcmp(g->point[k], b) == 0)
                break;
        if(j != k)
            g->matrix[j][k] = g->matrix[k][j] = 1;
        else
            g->matrix[j][j] = 2;
    }
    g->d = deg_all(g);
}


//计算指定顶点的度数
int deg(char point[],struct UndirectedGraph *g)
{
    int i;
    for (i = 0; i < g->point_num; i++) //找到该点在矩阵对应行
        if(strcmp(point,g->point[i])==0)
            break;
    return g->d[i];
}

//求图中结点结点度数之和
int sum_deg(struct UndirectedGraph *g)
{
    int i,sum = 0;
    for(i = 0;i<g->point_num;i++)
        sum += *(g->d+i);
    return sum;
}

//求图中结点的最大度数
int max_deg(struct UndirectedGraph *g)
{
    int i,max;
    max= *g->d;
    for(i = 0;i<g->point_num;i++)
        if(*(g->d+i)>max)
            max = *(g->d+i);
    return max;
}

//判断两个点是否是邻接点
void AdjacencyPoints(char p1[],char p2[],struct UndirectedGraph *g)
{
    int j,k;
    for (j = 0; j < g->point_num; j++)
        if (strcmp(g->point[j], p1) == 0)
            break;
    for (k = 0; k < g->point_num; k++)
        if (strcmp(g->point[k], p2) == 0)
            break;
    if(g->matrix[j][k] == 0)
        printf("%s与%s不是邻接点。",p1,p2);
    else
        printf("%s与%s是邻接点。",p1,p2);
}
