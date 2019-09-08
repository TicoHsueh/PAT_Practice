#include "bits/stdc++.h"
using namespace std;
map<string,int> strMap;
bool check(char c)
{
    if(c<='9'&&c>='0') return true;
    if(c<='Z'&&c>='A') return true;
    if(c<='z'&&c>='a') return true;
    return false;
}
int main()
{
    string s;
    getline(cin,s);
    int i=0;
    while(s[i]!='\0')
    {
        while(!check(s[i])) i++;

    }
    return 0;
}
