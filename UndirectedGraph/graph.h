
struct UndirectedGraph {
    char point[20][10];//顶点
    int matrix[20][20];//矩阵
};

void input(struct UndirectedGraph *g) {
    int point_num, road_num, i, j, k;
    char b[10] = {0};
    char a[10] = {0};
    printf("请输入顶点数量和边的数量：");
    setvbuf(stdout,NULL,_IONBF,0);
    scanf("%d %d", &point_num, &road_num);
    for (i = 0; i < point_num; i++)
    {
        printf("请输入第%d个顶点：",i+1);
        setvbuf(stdout,NULL,_IONBF,0);
        scanf("%s",g->point[i]);
    }
    for (i = 0; i < road_num; i++)
    {
        printf("请输入第%d条边：", i + 1);
        setvbuf(stdout,NULL,_IONBF,0);
        scanf("%s %s", a, b);
        //顶点与数组下标绑定
        for (j = 0; j < point_num; j++)
            if (strcmp(g->point[j], a) == 0)
                break;
        for (k = 0; k < point_num; k++)
            if (strcmp(g->point[k], b) == 0)
                break;
        g->matrix[j][k] = 1;
        g->matrix[k][j] = 1;
    }
}
