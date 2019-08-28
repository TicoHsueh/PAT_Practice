#include "bits/stdc++.h"
using namespace std;
int inValidCnt = 0;
char teamId[2000][30],passwd[2000][30];
list<int> mList;
list<int>::iterator it = mList.begin();
bool isValid(char passwd[30])
{
    //1 (one) by @, 0 (zero) by %, l by L, and O by o
    bool res = true;
    for(int i=0; i<strlen(passwd); i++)
    {
        switch (passwd[i])
        {
        case '1':
            passwd[i] = '@';
            res = false;
            break;
        case '0':
            passwd[i] = '%';
            res = false;
            break;
        case 'l':
            passwd[i] = 'L';
            res = false;
            break;
        case 'O':
            passwd[i] = 'o';
            res = false;
            break;
        }
    }
    return res;
}

int main()
{
    int T,total;
    scanf("%d",&T);
    mList.clear();
    int dir = 0;
    total = T;
    while(T--)
    {
        scanf("%s %s",teamId[dir],passwd[dir]);
        if(!isValid(passwd[dir]))
        {
            inValidCnt++;
            mList.push_back(dir);
        }
        dir++;
    }
    if(inValidCnt==0)
    {
        if(total==1)
            printf("There is 1 account and no account is modified\n");
        else
            printf("There are %d accounts and no account is modified\n",total);
    }
    else
    {
        printf("%d\n",inValidCnt);
        for(it = mList.begin(); it!=mList.end(); ++it)
        {
            printf("%s %s\n",teamId[*it],passwd[*it]);
        }
    }
    return 0;
}
