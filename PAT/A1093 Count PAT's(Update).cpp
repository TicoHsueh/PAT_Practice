#include "bits/stdc++.h"
using namespace std;

int main()
{
    string s;
    cin>>s;
    int countP,countA,countT;
    countA = countP = countT = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='T') countT++;
    }
    int res = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='P') countP++;
        if(s[i]=='T') countT--;
        if(s[i]=='A') res = (res + (countP*countT)%1000000007)%1000000007;
    }
    cout<<res;
    return 0;
}
