#include "cstdio"
#include "algorithm"
#include "ctype.h"
#include "memory.h"
using namespace std;
char WeekDay[7][20] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
char str1[100],str2[100],str3[100],str4[100];

int day,hour,minute;

void strProcess()
{
    int l1;
    char cday,chour;
    int cnt = 0;
    l1 = strlen(str1);
    for(int i=0; i<l1; i++)
    {
        if(isupper(str1[i])!=0) //说明是大写
        {
            if(str2[i]==str1[i])
            {
                if(cnt==0)
                {
                    if(str1[i]>='A'&&str1[i]<='G')
                    {
                        cday = str1[i];
                        cnt++;
                    }
                }
                else
                {
                    if(str1[i]>='A'&&str1[i]<='N')
                    {
                        chour = str1[i];
                        break;
                    }
                }
            }
        }
        else if(isdigit(str1[i]))//如果是数字
        {
            if(cnt==1)
            {
                if(str1[i]==str2[i])
                {
                    chour = str1[i];
                    break;
                }
            }
        }
    }
    day = cday - 'A';
    if(isdigit(chour))
    {
        hour = chour - '0';
    }
    else
    {
        hour = 10 + chour - 'A';
    }
    printf("%s %02d:",WeekDay[day],hour);

    for(int i=0; i<strlen(str3); i++)
    {
        /*上次未AC是因为这里*/
        if(islower(str3[i])||isupper(str3[i]))
        {
            if(str4[i]==str3[i])
            {
                minute = i;
                break;
            }
        }
    }
    printf("%02d\n",minute);
}

void strInit()
{
    memset(str1,'\0',sizeof(str1));
    memset(str2,'\0',sizeof(str2));
    memset(str3,'\0',sizeof(str3));
    memset(str4,'\0',sizeof(str4));
}
/*
3485HAHkxD4hhGF
2984HAHfkDkkggFdsb
g&hgjfdksdfsdfsdfsdf
s&Hyscvnmfsdgsdgfsds
*/
int main()
{
    strInit();
    while(scanf("%s %s %s %s",str1,str2,str3,str4)!=EOF)
    {
        strProcess();
        strInit();
    }
    return 0;
}
