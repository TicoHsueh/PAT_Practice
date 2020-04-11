#include "bits/stdc++.h"
using namespace std;
char sentens[105][1000];
string res = "";
int main()
{
    int T,total;
    scanf("%d",&T);
    getchar();
    total = T;
    string s;
    char temp[1002];
    int dir = 0;
    int testVal = 10;
    while(T--)
    {
        memset(temp,'\0',sizeof(temp));
        getline(cin,s);
        strcpy(temp,s.c_str());
        reverse(temp,temp+strlen(temp));
        if(strlen(temp)<minLen)
            minLen = strlen(temp);
        strcpy(sentens[dir],temp);
        dir++;
    }
    bool flag = false;
    for(int i=0; i<minLen; i++)
    {
        flag = false;
        char curr = sentens[0][i];
        for(int j=1; j<total; j++)
        {
            if(sentens[j][i]!=curr)
            {
                flag = true;
                break;
            }
        }
        if(flag==false)
            res = res + curr;
    }
    if(res.length()==0)
        printf("nai\n");
    else
    {
        string finalRes(res.rbegin(),res.rend());
        printf("%s\n",finalRes.c_str());
    }
    return 0;
}
