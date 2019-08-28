#include "bits/stdc++.h"
using namespace std;

typedef struct people
{
    char name[20];
    int year,month,day;
};
int valiedCnt;
people myleft,myright;
people oldest,youngest;
// 2014/9/6 1814/09/06
bool lessThan(people p1,people p2)
{
    //true:p1<p2
    if(p1.year>p2.year)
        return true;
    else if(p1.year<p2.year)
        return false;
    else if(p1.year==p2.year)
    {
        if(p1.month>p2.month)
            return true;
        else if(p1.month<p2.month)
            return false;
        else if(p1.month==p2.month)
        {
            if(p1.day>=p2.day)
                return true;
            else if(p1.day<p2.day)
                return false;
        }
    }
}
bool greaterThan(people p1,people p2)
{
    //true:p1<p2
    if(p1.year<p2.year)
        return true;
    else if(p1.year>p2.year)
        return false;
    else if(p1.year==p2.year)
    {
        if(p1.month<p2.month)
            return true;
        else if(p1.month>p2.month)
            return false;
        else if(p1.month==p2.month)
        {
            if(p1.day<=p2.day)
                return true;
            else if(p1.day>p2.day)
                return false;
        }
    }
}
void init()
{
    myleft.year = 1814;
    myleft.month = 9;
    myleft.day = 6;
    myright.year = 2014;
    myright.month = 9;
    myright.day = 6;
    youngest = myleft;
    oldest = myright;
}
int main()
{
    init();
    people Ptemp;
    int T;
    cin>>T;
    valiedCnt = 0;
    while(T--)
    {
        scanf("%s %d/%d/%d",Ptemp.name,\
              &Ptemp.year,&Ptemp.month,&Ptemp.day);
//        printf("%d\n",lessThan(Ptemp,myleft));
//        printf("%d\n",greaterThan(Ptemp,myright));
        if(lessThan(Ptemp,myleft)&&greaterThan(Ptemp,myright))
        {
            valiedCnt++;
            //printf("%s\n",Ptemp.name);
            if(lessThan(Ptemp,youngest))
            {
                //printf("Y:%s\n",Ptemp.name);
                youngest = Ptemp;
            }
            if(greaterThan(Ptemp,oldest))
            {
                //printf("O:%s\n",Ptemp.name);
                oldest = Ptemp;
            }
        }
    }
    if(valiedCnt!=0)
        printf("%d %s %s\n",valiedCnt,oldest.name,youngest.name);
    else
        printf("0\n");
    return 0;
}
