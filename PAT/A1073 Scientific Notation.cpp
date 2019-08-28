#include "cstdio"
#include "stdlib.h"
#include "algorithm"
#include "iostream"
#include <bits/stdc++.h>
using namespace std;

char sentence[10086];
/*未AC原因较为复杂，主要是没有分析清题目的特点，进而复杂化了问题*/
int main()
{
    memset(sentence,'\0',sizeof(sentence));
    while(scanf("%s",sentence)!=EOF)
    {
        int Epos = -1;
        int tempDir = 0;
        while(sentence[tempDir]!='E')
        {
            tempDir++;
        }
        Epos = tempDir;
        if(sentence[0]=='-')
            printf("-");
        char moveSig = sentence[Epos+1];
        int moveBit = 0;
        for(int i=Epos+2; i<strlen(sentence); i++)
        {
            moveBit = moveBit*10 + sentence[i] - '0';
        }
        if(moveSig=='+') //右移
        {
            for(int i=1; i<Epos; i++)
            {
                if(sentence[i]=='.')
                    continue;
                printf("%c",sentence[i]);
                if(i==moveBit+2&&i!=Epos-1)
                    printf(".");
                //+3.1425926535E+4;
            }
//            printf("\n%d %d\n",moveBit,strlen(sentence));
            for(int i=0; i<moveBit-(Epos-3); i++)
                printf("0");
        }
        else  //左移
        {
            printf("0.");
            for(int i=0; i<moveBit-1; i++)
                printf("0");
            for(int i=1; i<Epos; i++)
            {
                if(sentence[i]=='.')
                    continue;
                printf("%c",sentence[i]);
            }
        }
        printf("\n");
        memset(sentence,'\0',sizeof(sentence));
    }
    return 0;
}
