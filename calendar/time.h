#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//以1900年1月1日星期一作为标准

//判断是否为闰年
int leap(int year)
{
    if((year%4==0&&year%100!=0)||(year%400==0))
        return 1;
    else
        return 0;
}

//判断某年某月有多少天
int DaysInMonth(int year,int month)
{
    //创建个数组用于存储平年各月天数
    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int a = leap(year);
    //闰年2月为29天
    if(month!=2)
        return days[month-1];
    else
    if(a==1)
        return 29;
    else
        return 28;
}

//判断某年第一天是星期几
int WeekOfFirstdayInYear(int year)
{
    int i,b,week,dur_days = (year - 1900)*365; //相对1900年经过的天数
    for(i = 1900;i<=year;i++)
        if(leap(i) == 1)
            dur_days+=1;//加上闰年中多出的一天
    week = (dur_days+1)%7;
    return week;
}

//判断某年某月第一天是星期几
int WeekOfFirstdayInMonth(int year,int month)
{
    int a = WeekOfFirstdayInYear(year);
    int i,week,dur_days = 0;
    for(i = 1;i<month;i++)
        dur_days += DaysInMonth(year,i);
    week = (dur_days+a)%7;
    return week;
}

//存储某年某月日历（二维数组）
int **save_month(int year,int month)
{
    int i,j,k = 1,z,**m,week = WeekOfFirstdayInMonth(year,month),days = DaysInMonth(year,month);
    m = (int**) malloc(6*sizeof(int *));
    for(i = 0;i<6;i++)
        m[i] = (int*) malloc(7*sizeof(int));
    for(i = 0;i<6;i++)
        for(j = 0;j<7;j++)
        {
            z = 7*i+j;
            if(z>=week&&z<week+days)
                m[i][j] = k++;
            else
                m[i][j] = 0;
        }
    return m;
}

//输出某年某月日历
void output_month(int year,int month)
{
    int **m,i,j;
    m = save_month(year,month);
    printf("*****************************\n");
    printf("\t\t %d年%d月\n",year,month);
    printf("SUN\tMON\tTUE\tWED\tTUR\tFRI\tSAT\n");
    for(i = 0;i<6;i++)
    {
        for(j = 0;j<7;j++)
        {
            if(m[i][j]==0)
                printf("\t");
            else
                printf("%3d\t",m[i][j]);
        }
        printf("\n");
    }
    printf("*****************************\n");
}

//存储某年日历
int ***save_year(int year)
{
    int i,j,***y;
    y = (int***) malloc(12*sizeof(int **));
    for(i = 0;i<12;i++)
    {
        y[i] = (int**) malloc(6*sizeof(int *));
        for(j = 0;j<6;j++)
            y[i][j] = (int*) malloc(7*sizeof(int));
    }
    for(i = 0;i<12;i++)
        y[i] = save_month(year,i+1);
    return y;
}

//输出某年日历
void output_year(int year)
{
    int ***y,i,j,k;
    y = save_year(year);
    printf(":=====================\t\t\t%d年的日历\t\t\t =====================:\n",year);
    for(i = 0;i<6;i++)
    {
        printf(":\t%d\tSUN\tMON\tTUE\tWED\tTUR\tFRI\tSAT\t\t%d\tSUN\tMON\tTUE\tWED\tTUR\tFRI\tSAT\t  :\n",i+1,i+7);
        for(j = 0;j<6;j++)
        {
            printf(":\t\t");
            for(k = 0;k<7;k++)
            {
                if(y[i][j][k]==0)
                    printf("\t");
                else
                    printf("%3d\t",y[i][j][k]);
            }
            printf("\t\t");
            for(k = 0;k<7;k++)
            {
                if(y[i+6][j][k]==0)
                    printf("\t");
                else
                    printf("%3d\t",y[i+6][j][k]);
            }
            printf("  :\n");
        }
    }
    printf(":=========================================================================:\n");
}