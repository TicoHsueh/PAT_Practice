#include "bits/stdc++.h"
using namespace std;
//注意格式
int main()
{
    int n;
    cin>>n;
    map<int,int> cp;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        cp[a] = b;
        cp[b] = a;
    }
    int num;
    vector<int> res,temp;
    cin>>num;
    int a[100000] = {0};
    for(int i=0;i<num;i++){
        int t;
        cin>>t;
        temp.push_back(t);
        a[t] = 1;
    }
    for(int i=0;i<temp.size();i++){
        if(!a[cp[temp[i]]])
            res.push_back(temp[i]);
    }
    cout<<res.size()<<endl;
    sort(res.begin(),res.end());
    for(int i=0;i<res.size();i++){
        printf("%05d",res[i]);
        i==res.size()-1? printf("\n"):printf(" ");
    }
    return 0;
}
