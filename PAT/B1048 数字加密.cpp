#include "bits/stdc++.h"
using namespace std;
char lockNum[10086],Num[10086];
/*
1234567 368782971 => 3695Q8118
   A        B
奇:相加对13取余
对:B-A若结果负,加10.个位为第1位.
*/
/*未AC原因：没想到逆序这种操作，
可以匹配两个字符串不等的问题*/
char res[10086];
void init()
{
    memset(lockNum,'\0',sizeof(lockNum));
    memset(Num,'\0',sizeof(Num));
    memset(res,'\0',sizeof(res));
}
int main()
{
    init();
    while(scanf("%s%s",lockNum,Num)!=EOF)
    {
        reverse(lockNum,lockNum+strlen(lockNum));
        reverse(Num,Num+strlen(Num));
        int t = max(strlen(lockNum),strlen(Num));
        int dir = 1;
        for(int i=0; i<t; i++)
        {
            int a = i>strlen(lockNum)-1?0:lockNum[i]-'0';
            int b = i>strlen(Num)-1?0:Num[i]-'0';
           // printf("\n%d %d %d\n",i,a,b);
            if(dir%2==1)
            {
                int tempRes = a+b;
                tempRes %= 13;
                if(tempRes==10)
                    res[dir-1] = 'J';
                else if(tempRes==11)
                    res[dir-1] = 'Q';
                else if(tempRes==12)
                    res[dir-1] = 'K';
                else
                    res[dir-1] = tempRes + '0';
                }
            else
            {
                int tempRes = b-a;
                if(tempRes<0)
                    tempRes += 10;
                res[dir-1] = tempRes + '0';
            }
            dir++;
        }
        reverse(res,res+strlen(res));
        puts(res);
        init();
    }
    return 0;
}
