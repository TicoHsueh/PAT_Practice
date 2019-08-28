#include "cstdio"
#include "algorithm"
#include "math.h"
#include "iostream"
using namespace std;


int main()
{
    long long int a,b,sum,c;
    int T,dir = 1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        sum = a+b;
        if(a>0&&b>0)
        {
            if(sum<0)//说明有溢出 肯定比C大
                printf("Case #%d: true\n",dir++);
            else if(sum>c)
                printf("Case #%d: true\n",dir++);
            else
                printf("Case #%d: false\n",dir++);
        }
        else if((a>0&&b<0)||(a<0&&b>0))
        {
            if(sum>c)
                printf("Case #%d: true\n",dir++);
            else
                printf("Case #%d: false\n",dir++);
        }
        else if(a<0&&b<0)
        {
            if(sum>=0)
                printf("Case #%d: false\n",dir++);
            else if(sum>c)
                printf("Case #%d: true\n",dir++);
            else
                printf("Case #%d: false\n",dir++);
        }
    }
    return 0;
}
