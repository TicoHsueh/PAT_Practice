#include "bits/stdc++.h"
using namespace std;
map<string,int> mp;
int main()
{
    string temp;
    int cnt = 0;
    while(cin>>temp){
        char c = getchar();
        mp[temp] = cnt;
        cnt++;
        if(c=='\n') break;
    }
    map<string,int>::iterator it;
    for(it=mp.begin();it!=mp.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}
