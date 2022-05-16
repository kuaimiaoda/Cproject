#include <stdio.h>
#include "111.h"
int main() {
    int a1[1000] = {0},a2[1000] = {0};
    int *he,*cha,*er,*ba,*shiliu;
    input(a1);
    input(a2);
    he = add(a1,a2);
    printf("和为：");
    output(he);
    cha = subduction(a1,a2);
    printf("差为：");
    output(cha);
    er = change(a1,10,2);
    printf("a1的二进制为：");
    output(er);
    ba = change(a1,10,8);
    printf("a1的八进制为：");
    output(ba);
    shiliu = change(a1,10,16);
    printf("a1的十六进制为：");
    output(shiliu);
    return 0;
}
