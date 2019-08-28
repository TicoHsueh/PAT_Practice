#include "iostream"
#include "cstdio"
using namespace std;

void colorConvert(int n)
{
    int high = n/13;
    switch(high)
    {
    case 10:
        printf("A");
        break;
    case 11:
        printf("B");
        break;
    case 12:
        printf("C");
        break;
    default:
        printf("%d",high);
        break;
    }
    int low = n%13;
    switch(low)
    {
    case 10:
        printf("A");
        break;
    case 11:
        printf("B");
        break;
    case 12:
        printf("C");
        break;
    default:
        printf("%d",low);
        break;
    }
}

int main()
{
    int red,green,blue;
    while(scanf("%d%d%d",&red,&green,&blue)!=EOF)
    {
        printf("#");
        colorConvert(red);
        colorConvert(green);
        colorConvert(blue);
        printf("\n");
    }
    return 0;
}
