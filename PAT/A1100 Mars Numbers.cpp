#include "bits/stdc++.h"
using namespace std;
string a[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug",
                "sep", "oct", "nov", "dec"
               };
string b[13] = {"####", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo",
                "syy", "lok", "mer", "jou"
               };
void func1(int t)
{
    if(t/13) cout<<b[t/13];
    if((t/13)&&(t%13)) cout<<" ";
    if(t%13||t==0) cout<<a[t%13];
}

int func2(string s)
{
    string s1 = s.substr(0,3),s2;
    int t1 = 0,t2 = 0;
    if(s.length()>4) s2 = s.substr(4,3);
//    cout<<s1.length()<<":"<<s2.length()<<endl;
    for(int i=0; i<13; i++) {
        if(s1==a[i]||s2==a[i]) t2 = i;
        if(s1==b[i]) t1 = i;
    }
//    printf("t1:%d t2:%d\n",t1,t2);
    return t1*13+t2;
}
int main()
{
    int t;
    cin>>t;
    string s;
    getchar();
    while(t--) {
        getline(cin,s);
        if(isalpha(s[0])) { //ÊÇ×ÖÄ¸
            cout<<func2(s)<<endl;
        } else { //ÊÇÊý×Ö
            func1(atoi(s.c_str()));
            cout<<endl;
        }
    }
    return 0;
}
