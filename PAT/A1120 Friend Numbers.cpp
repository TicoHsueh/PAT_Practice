#include "bits/stdc++.h"
using namespace std;

set<int> res;

int strToInt(string num)
{
    int ret = 0;
    for(int i=0;i<num.length();i++){
        ret += num[i] - '0';
    }
    return ret;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string num;
        cin>>num;
        res.insert(strToInt(num));
    }
    int t = res.size(),cnt = 0;
    printf("%d\n",t);
    set<int>::iterator it;
    for(it=res.begin();it!=res.end();it++){
        cnt++;
        printf("%d",*it);
        cnt==t?printf("\n"):printf(" ");
    }
    return 0;
}
