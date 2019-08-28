#include "cstdio"
#include "algorithm"
#include "iostream"
using namespace std;

typedef struct people
{
    char name[20];
    int year,month,day;
};
people peo[10086];
/*ÉñÆæµÄ¶Î´íÎó*/
int valiedNum = 0;
void peopleSort()
{
    int n = valiedNum;
    for(int i=0; i<n; i++)
        for(int j=i; j<n; j++)
        {
            if(peo[i].year>peo[j].year)
                swap(peo[i],peo[j]);
            else if(peo[i].year==peo[j].year)
            {
                if(peo[i].month>peo[j].month)
                    swap(peo[i],peo[j]);
                else if(peo[i].month==peo[j].month)
                    if(peo[i].day>peo[j].day)
                        swap(peo[i],peo[j]);
            }
        }
    if(valiedNum!=0)
        printf("%d %s %s\n",valiedNum,peo[0].name,peo[valiedNum-1].name);
    else
        printf("0\n");
//    printf("\n");
//    for(int i=0; i<valiedNum; i++)
//        printf("%s %d/%d/%d\n",peo[i].name,peo[i].year,peo[i].month,peo[i].day);
}

void peopleInfoInit(int n)
{
    int dir = 0;
    people p;
    while(n--)
    {
        scanf("%s %d/%d/%d",p.name,&p.year,&p.month,&p.day);
        if(p.year>1814&&p.year<2014)
        {
            peo[dir] = p;
            dir++;
        }
        else if(p.year==1814)
        {
            if(p.month==9)
            {
                if(p.day>=6)
                {
                    peo[dir] = p;
                    dir++;
                }
            }
            else if(p.month>9)
            {
                peo[dir] = p;
                dir++;
            }
        }
        else if(p.year==2014)
        {
            if(p.month==9)
            {
                if(p.day<=6)
                {
                    peo[dir] = p;
                    dir++;
                }
            }
            else if(p.month<9)
            {
                peo[dir] = p;
                dir++;
            }
        }
    }
    valiedNum = dir;
}


int main()
{
    int n;
    scanf("%d",&n);
    peopleInfoInit(n);
    peopleSort();
    return 0;
}

//#include "cstdio"
//#include "algorithm"
//#include "iostream"
//using namespace std;
//
//typedef struct people
//{
//    char name[20];
//    int year,month,day;
//};
//people peo[10086];
//int valiedNum = 0;
//void peopleSort()
//{
//    int n = valiedNum;
//    for(int i=0; i<n; i++)
//        for(int j=i; j<n; j++)
//        {
//            if(peo[i].year>peo[j].year)
//                swap(peo[i],peo[j]);
//            else if(peo[i].year==peo[j].year)
//            {
//                if(peo[i].month>peo[j].month)
//                    swap(peo[i],peo[j]);
//                else if(peo[i].month==peo[j].month)
//                    if(peo[i].day>peo[j].day)
//                        swap(peo[i],peo[j]);
//            }
//        }
//    if(valiedNum!=0)
//        printf("%d %s %s\n",valiedNum,peo[0].name,peo[valiedNum-1].name);
//    else
//        printf("0\n");
////    printf("\n");
////    for(int i=0; i<valiedNum; i++)
////        printf("%s %d/%d/%d\n",peo[i].name,peo[i].year,peo[i].month,peo[i].day);
//}
//
//void peopleInfoInit(int n)
//{
//    int dir = 0;
//    people p;
//    while(n--)
//    {
//        scanf("%s %d/%d/%d",p.name,&p.year,&p.month,&p.day);
//        if(p.year>1814&&p.year<2014)
//        {
//            peo[dir] = p;
//            dir++;
//        }
//        else if(p.year==1814)
//        {
//            if(p.month==9)
//            {
//                if(p.day>=6)
//                {
//                    peo[dir] = p;
//                    dir++;
//                }
//            }
//            else if(p.month>9)
//            {
//                peo[dir] = p;
//                dir++;
//            }
//        }
//        else if(p.year==2014)
//        {
//            if(p.month==9)
//            {
//                if(p.day<=6)
//                {
//                    peo[dir] = p;
//                    dir++;
//                }
//            }
//            else if(p.month<9)
//            {
//                peo[dir] = p;
//                dir++;
//            }
//        }
//    }
//    valiedNum = dir;
//}
//
//
//int main()
//{
//    int n;
//    scanf("%d",&n);
//    peopleInfoInit(n);
//    peopleSort();
//    return 0;
//}



/*
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

struct person
{
    char name[8];
    int year,month,day;
} per[10086];

bool cmp(person p1,person p2)
{
    if(p1.year!=p2.year)
        return p1.year<p2.year;
    else if(p1.month!=p2.month)
        return p1.month<p2.month;
    else
        return p1.day<p2.day;
}

bool isValid(person P)
{
    if(P.year>1814&&P.year<2014)
        return true;
    else if(P.year==1814)
    {
        if(P.month>8)
            if(P.day>5)
                return true;
            else
                return false;
        else
            return false;
    }
    else if(P.year==2014)
    {
        if(P.month<10)
            if(P.day>7)
                return true;
            else
                return false;
        else
            return false;
    }
    else
        return false;
}

int main()
{
    int T,iter;
    iter = 0;
    cin>>T;
    while(T--)
    {
        scanf("%s",&per[iter].name);
        scanf("%d/%d/%d",&per[iter].year,&per[iter].month,&per[iter].day);
        if(isValid(per[iter]))
            iter++;
        else
            continue;
    }
    if(iter==0)
        cout<<"0"<<endl;
    else
    {
        sort(per,per+iter+1,cmp);
        printf("%d %s %s\n",iter,per[0].name,per[iter-1].name);
    }
    return 0;
}

*/
