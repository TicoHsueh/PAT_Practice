#include "cstdio"
#include "iostream"
#include "algorithm"
#define MAXN 10006
using namespace std;
int data[MAXN];
int main()
{
    int xs,index,dir=0;
    while(scanf("%d%d",&xs,&index)!=EOF)
    {
        data[dir++] = xs;
        data[dir++] = index;
    }
    for(int i=0; i<dir; i+=2)
    {
        if(data[i+1]==0)
        {
            data[i] = 0;
            if(dir>2)
                dir-=2;
            else
                dir = 2;
            break;
        }
        data[i] = data[i+1]*data[i];
        data[i+1]--;
    }
    printf("%d",data[0]);
    for(int i=1; i<dir; i++)
        printf(" %d",data[i]);
    printf("\n");
    return 0;
}
