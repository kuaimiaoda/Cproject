#include <stdio.h>
#include <string.h>
//输入数据，存到数组中
void input(int a[]) {
    char s[1000];
    int i, len;
    gets(s);
    len = strlen(s);
    for (i = 0; i <= len; i++) {
        a[len - i] = s[i] - 48;
    }
    a[0] = len;//记录数据长度
}


//数组数据输出
void output(int a[]) {
    int i;
    char alp[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
    if (a[a[0] + 1] == 1)
        printf("-");
    for (i = a[0]; i > 0; i--) {
        if (a[i] >= 10)
            printf("%c", alp[a[i] - 10]);//输出16进制时，需要用字母代替大于10的数
        else
            printf("%d", a[i]);
    }
    printf("\n");
}


//加法运算
int *add(int a1[], int a2[]) {
    int max, i, cc[1000] = {0};
    static int a3[1000] = {0};
    //符号相同
    if (a1[0] > a2[0])
        max = a1[0];
    else
        max = a2[0];
    a3[0] = max;
    for (i = 1; i <= max + 1; i++) {
        a3[i] = a1[i] + a2[i] + cc[i];
        if (a3[i] >= 10) {
            cc[i + 1] += a3[i] / 10;
            a3[i] = a3[i] % 10;
        }
    }
    if (a3[max + 1] != 0)
        a3[0]++;
    return a3;
}

//两个个位整数比大小
int compare(int n1, int n2) {
    int b = 0;
    if (n1 > n2)
        b = 1;
    else if (n1 < n2)
        b = 2;
    return b;
}

//两个长整数比大小 返回b值
int CompareArray(int a1[], int a2[]) {
    int i, b = 0, c;
    if (a1[0] > a2[0])
        b = 1;
    else if (a1[0] < a2[0])
        b = 2;
    else {
        for (i = a1[0]; i > 0; i--) {
            b = compare(a1[i], a2[i]);
            if (b != 0)
                break;
        }
    }
    return b;
}

//数组 大数减去小数
void bjs(int a1[], int a2[], int a3[]) {
    int i;
    int *p1 = a1;
    a3[0] = a1[0];
    for (i = 1; i <= a1[0]; i++) {
        a3[i] = *(p1 + i) - a2[i];
        if (a3[i] < 0) {
            *(p1 + 2) -= 1;
            a3[i] += 10;
        }
    }
    while (a3[a3[0]] == 0 && a3[0] > 1)//删除有效数字前的0，测出真实有效长度
        a3[0]--;
}


//减法运算
int *subduction(int a1[], int a2[]) //两个参数(被减数，减数)
{
    int b, c;
    static int a3[1000] = {0};
    b = CompareArray(a1, a2);
    if (b == 1 || b == 0)
        bjs(a1, a2, a3);
    else {
        bjs(a2, a1, a3);
        c = a3[0] + 1;  // 数据最后一位的下一位用于储存结果的正负，1表示负。
        a3[c] = 1;
    }
    return a3;
}


//进制转换
int *change(int start[], int oldBase, int newBase)//三个参数（待转化数组，待转化数组进制，目标数组进制）
{
    int i, j, y;
    static int res[1000];
    int ans[1000], b[1000];
    b[0] = start[0];
    for (i = start[0], j = 1; i >= 1; i--, j++)
        b[j] = start[i];
    memset(res, 0, sizeof(res)); //余数初始化为空
    //模n取余法，(总体规律是先余为低位，后余为高位)
    while (b[0] >= 1) {
        //只要被除数仍然大于等于1，那就继续“模2取余”
        y = 0;
        i = 1;
        ans[0] = b[0];
        while (i <= b[0])//从最高位开始除
        {
            y = y * oldBase + b[i];
            ans[i] = y / newBase; //商
            y %= newBase;
            i++;
        }
        //y是最后一位的余数
        res[++res[0]] = y; //这一轮运算得到的余数
        //res[0]存的是余数的长度，其他元素为余数的每一位
        i = 1;
        //找到下一轮商的起始处
        while ((i <= ans[0]) && (ans[i] == 0))
            i++;
        //清除这一轮使用的被除数
        memset(b, 0, sizeof(*b));

        //本轮得到的商变为下一轮的被除数
        for (j = i; j <= ans[0]; j++)
            b[++b[0]] = ans[j]; //++b[0]，当前位数加1，即为下一位的被除数下标位置
        memset(ans, 0, sizeof(ans));    //清除这一轮的商，为下一轮运算做准备
    }
    return res;
}