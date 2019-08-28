/*
https://pintia.cn/problem-sets/994805342720868352/problems/994805435700199424
*/

//#include "cstdio"
//#include "algorithm"
//using namespace std;
//
//const int MAXN = 100005;
//int dis[MAXN],e;
//int main()
//{
//    int sum = 0,query,n,left,right;
//    scanf("%d",&n);
//    for(int i=1;i<=n;i++){
//        scanf("%d",&e);
//        sum += e;
//        dis[i] = sum;
//    }
//    scanf("%d",&query);
//    for(int i=0;i<query;i++){
//        scanf("%d%d",&left,&right);
//        if(left>right) swap(left,right);
//        int temp = dis[right-1]-dis[left-1];
//        printf("%d\n",min(temp,sum-temp));
//    }
//    return 0;
//}
#include "iostream"
#include "stdio.h"
#include "memory.h"
#define MAXN 100000+5
using namespace std;

int disCost[MAXN];

int main()
{
    int T,dir = 2,nT;
    int tempCost,tempTotal = 0;
    scanf("%d",&T);
    nT = T;
    memset(disCost,0,sizeof(disCost));
    while(T--)
    {
        scanf("%d",&tempCost);
        tempTotal += tempCost;
        disCost[dir] = tempTotal;
        dir++;
    }
    disCost[0] = tempTotal;
    int askNum = 0;
    int dis1,dis2;
    scanf("%d",&askNum);
    while(askNum--)
    {
        int st,ed;
        scanf("%d %d",&st,&ed);
        if(ed<st)
            swap(st,ed);
        dis1 = disCost[st];
        dis2 = disCost[ed];
        printf("%d\n",min(dis2-dis1,disCost[0]-(dis2-dis1)));
    }
    return 0;
}
/*

#include <stdio.h>
#include <iostream>
using namespace std;
int graph[100086];
//1 2 3 4  5
//1 2 4 14 9 total = 30
//3
//1 3
//2 5
//4 1
//
//3
//10
//7

int main()
{
    int T,ask,start,endp,ans,dis;
    long long int total;
    int half;
    total = 0,ans = 0;
    cin>>T;
    for(int i=1; i<=T; i++)
    {
        cin>>graph[i];
        total += graph[i];
    }
    half = total/2;
    cin>>ask;
    for(int i=0; i<ask; i++)
    {
        cin>>start>>endp;
        if(start>endp)
        {
            swap(start,endp);
        }
        dis = endp - start;
        for(int i=start; i<endp; i++)
        {
            ans += graph[i];
            if(ans>half)
            {
                goto
                BACK;
            }
        }
        goto
        RES;
BACK:
        ans = 0;
        for(int i=endp-1; i>=endp-dis; i--)
        {
            ans += graph[i];
        }
RES:
        if(ans>half)
            ans = total - ans;
        cout<<ans<<endl;
        ans = 0;
    }
    return 0;
}
*/
