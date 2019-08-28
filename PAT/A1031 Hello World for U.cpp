#include "cstdio"
#include "algorithm"
#include "iostream"
#include "memory.h"
#define MAXN 10086
using namespace std;
char Ustr[MAXN];
int main()
{
    int str_len = 0;
    int side,bottom;
    while(scanf("%s",Ustr)!=EOF)
    {
        str_len = strlen(Ustr);
        side=1;
        bottom = str_len;
        while(bottom>=side)
        {
            side++;
            bottom -= 2;
        }
        side-=2;
        bottom = str_len - 2*side;
        for(int i=0;i<side;i++){
            printf("%c",Ustr[i]);
            for(int j=0;j<bottom-2;j++)
                printf(" ");
            printf("%c\n",Ustr[str_len-1-i]);
        }
        for(int i=0;i<bottom;i++){
            printf("%c",Ustr[side+i]);
        }
        printf("\n");
        memset(Ustr,'\0',sizeof(Ustr));
    }
    return 0;
}
