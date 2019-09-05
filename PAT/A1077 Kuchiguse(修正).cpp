#include "bits/stdc++.h"
using namespace std;
string sentens[300];
int main()
{
    int n;
    int minLen = 1000000;
    cin>>n;
    getchar();
    for(int i=0; i<n; i++)
    {
        string temp;
        getline(cin,temp);
        reverse(temp.begin(),temp.end());
        sentens[i] = temp;
        if(temp.length()<minLen)
        {
            minLen = temp.length();
        }
    }
    string res;
    bool flag = false;
    for(int i=0; i<minLen; i++)
    {
        char c = sentens[0][i];
        if(flag) break;
        for(int j=0; j<n; j++)
        {
            if(sentens[j][i]!=c)
            {
                flag = true;
                break;
            }
        }
        if(!flag) res.push_back(c);
    }
    if(res.length()!=0)
    {
        reverse(res.begin(),res.end());
        cout<<res<<endl;
    }
    else cout<<"nai"<<endl;
    return 0;
}
