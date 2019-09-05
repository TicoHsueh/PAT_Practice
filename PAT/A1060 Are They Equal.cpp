#include "bits/stdc++.h"
using namespace std;

string deal(string s,int &e,int n)
{
    e = 0;
    string res;
    while(s[0]=='0') {
        s.erase(s.begin());
    }
    if(s[0]=='.') {
        s.erase(s.begin());
        int k = 0;
        while(s[k]=='0') {
            k++;
            e--;
        }
        for(int i=0; i<n; i++) {
            if(s[k]!='0'&&k<s.length()) res.push_back(s[k]);
            else {
                if(s.length()>0)
                    s.erase(s.begin());
                res.push_back('0');
            }
            k++;
        }
        if(s.length()==0) e = 0;
    } else {
        int k = 0;
        while(s[k]!='.'&&k<s.length()) {
            k++;
            e++;
        }
        if(k<s.length()&&s[k]=='.')
            s.erase(s.begin()+k);
        k = 0;
        for(int i=0; i<n; i++) {
            if(k<s.length()) res.push_back(s[k]);
            else res.push_back('0');
            k++;
        }
    }
//    printf("0.%s*10^%d\n",res.c_str(),e);
    return res;
}

int main()
{
    int n,e1,e2;
    string A,B,resA,resB;
    cin>>n>>A>>B;
    resA = deal(A,e1,n);
    resB = deal(B,e2,n);
    if(resA==resB&&e1==e2) {
        printf("YES ");
        printf("0.%s*10^%d\n",resA.c_str(),e1);
    } else {
        printf("NO ");
        printf("0.%s*10^%d ",resA.c_str(),e1);
        printf("0.%s*10^%d\n",resB.c_str(),e2);
    }
    return 0;
}
