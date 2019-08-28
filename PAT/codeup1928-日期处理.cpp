#include "stdio.h"
int dayOfYear[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int dayOfRYear[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
bool runJudge(int year)
{
    if((year%4==0&&year%100!=0)||(year%400==0))
        return true;
    return false;
}
int dateProc(int data1,int data2)
{
    if(data1>data2)
    {
        int temp;
        temp = data2;
        data2 = data1;
        data1 = temp;
    }
    int year1,month1,day1;
    int year2,month2,day2;
    year1 = data1/10000;
    month1 = data1/100%100;
    day1 = data1%100;

    year2 = data2/10000;
    month2 = data2/100%100;
    day2 = data2%100;
    int res = 1;
    while(true)
    {
        if((year1==year2)&&(month1==month2)&&(day1==day2))
            break;
        res++;
        day1++;
        if(runJudge(year1))
        {
            if(day1==dayOfRYear[month1-1]+1)
            {
                month1++;
                day1 = 1;
            }
            if(month1==13)
            {
                year1++;
                month1 = 1;
            }
        }
        else
        {
            if(day1==dayOfYear[month1-1]+1)
            {
                month1++;
                day1 = 1;
            }
            if(month1==13)
            {
                year1++;
                month1 = 1;
            }
        }
    }
    return res;
}

int main()
{
    int bg_year,ed_year;
    while(scanf("%d%d",&bg_year,&ed_year)!=EOF)
    {
        printf("%d\n",dateProc(bg_year,ed_year));
    }
    return 0;
}
