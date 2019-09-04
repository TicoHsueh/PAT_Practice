#include "bits/stdc++.h"
using namespace std;
int mark[10] = {0};
int original[10] = {0};
string bigMul(string s)
{
    string res;
    int dir = 0;
    int t = s.length()-1;
    int carrier = 0;
    for(int i=t; i>=0; i--) {
        int m = s[i]-'0',p;
        original[m] = 1;
        p = (m*2)%10 + carrier;
        if(2*m>=10) carrier = 1;
        else carrier = 0;
        res.push_back(p+'0');
        mark[p] = 1;
    }
    if(carrier==1) {
        res.push_back('1');
        mark[1] = 1;
    }
    reverse(res.begin(),res.end());
    return res;
}

int main()
{
    string s,res;
    cin>>s;
    res = bigMul(s);
//    cout<<res<<endl;
    for(int i=0; i<10; i++) {
        if(mark[i]!=original[i]) {
//            cout<<i<<endl;
            printf("No\n");
            cout<<res<<endl;
            return 0;
        }
    }
    printf("Yes\n");
    cout<<res<<endl;
    return 0;
}
