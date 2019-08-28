#include "iostream"
#include "stdio.h"
#include "memory.h"
#define MAXN 3000
using namespace std;
double tokenA[MAXN],tokenB[MAXN],res[MAXN];
int main()
{
    int t,cnt = 0;
    scanf("%d",&t);
    memset(tokenA,0,sizeof(tokenA));
    memset(tokenB,0,sizeof(tokenB));
    memset(res,0,sizeof(res));
    while(t--)
    {
        int index;
        scanf("%d",&index);
        scanf("%lf",&tokenA[index]);
    }
    scanf("%d",&t);
    while(t--)
    {
        int index;
        scanf("%d",&index);
        scanf("%lf",&tokenB[index]);
    }
    cnt = 0;
    for(int i=1005; i>=0; i--)
    {
        res[i] = tokenA[i]+tokenB[i];
        if(res[i]!=0)
            cnt++;
    }
    printf("%d",cnt);
    for(int i=1005; i>=0; i--)
    {
        if(res[i]!=0)
            printf(" %d %.1lf",i,res[i]);
    }
    printf("\n");
    return 0;
}
