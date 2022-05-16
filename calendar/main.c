#include <stdio.h>
#include <string.h>
#include "time.h"
int main()
{
    int year,month;
    scanf("%d %d",&year,&month);
    output_month(year,month);
    output_year(year);
    return 0;
}
