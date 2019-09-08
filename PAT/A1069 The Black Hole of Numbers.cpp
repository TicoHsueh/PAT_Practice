#include "bits/stdc++.h"
#include "string"
using namespace std;
bool cmp(char a,char b)
{
    return a>b;
}

int main()
{
    int n;
    cin>>n;
    string s;
    char temp[5];
    sprintf(temp,"%04d",n);
    s = temp;
//    cout<<s<<endl;
    int res;
    while(true) {
        sort(s.begin(),s.end(),cmp);
        int a = atoi(s.c_str());
        sort(s.begin(),s.end());
        int b = atoi(s.c_str());
        res = a-b;
        printf("%04d - %04d = %04d\n",a,b,res);
        if(res==6174) return 0;
        if(res==0) return 0;
        s.clear();
        char temp1[5];
        sprintf(temp1,"%04d",res);
        s = temp1;
    }
    return 0;
}
