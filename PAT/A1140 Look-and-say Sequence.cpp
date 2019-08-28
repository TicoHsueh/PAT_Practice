#include "bits/stdc++.h"
using namespace std;

string read(string num)
{
    string res;
    res.clear();
    char currChar = '\0',lastChar;
    lastChar = currChar;
    int tpCnt = 1;
    for(int i=0; i<num.length(); i++) {
        currChar = num[i];
        if(currChar!=lastChar) {
            if(i!=0){
                res += '0'+tpCnt;
            }
            tpCnt = 1;
            res += currChar;
            lastChar = currChar;
        }else{
            tpCnt++;
        }
    }
    res += '0'+tpCnt;
    return res;
}

int main()
{
    int D,t;
    string res;
    res.clear();
    cin>>D>>t;
    res += '0'+D;
    while(--t)
    {
        res = read(res);
    }
    cout<<res;
    return 0;
}
