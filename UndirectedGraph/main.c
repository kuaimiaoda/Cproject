#include <stdio.h>
#include <string.h>
#include "graph.h"

int main() {
    struct UndirectedGraph graph = {{'\0'},0};
    input(&graph);
    printf("%s\n",graph.point[0]);
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++)
            printf("%d ", graph.matrix[i][j]);
        printf("\n");
    }
    return 0;
}
