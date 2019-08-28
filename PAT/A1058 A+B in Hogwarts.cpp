#include "iostream"
#include "cstdio"
using namespace std;

int main()
{
    int a1,b1,c1,a2,b2,c2;
    while(scanf("%d.%d.%d %d.%d.%d",&a1,&b1,&c1,&a2,&b2,&c2)!=EOF)
    {
        int r1 = 0,r2 = 0,r3 = 0;
        int carry = 0;
        r3 = (c1+c2)%29;
        carry = (c1+c2)/29;
        r2 = (b1+b2+carry)%17;
        carry = (b1+b2+carry)/17;
        r1 = a1+a2+carry;
        printf("%d.%d.%d\n",r1,r2,r3);
    }
    return 0;
}
