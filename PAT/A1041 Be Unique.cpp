#include "bits/stdc++.h"
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> num;
    int a[100000] = {0};
    for(int i=0;i<n;i++){
        int e;
        cin>>e;
        a[e]++;
        num.push_back(e);
    }
    for(int i=0;i<n;i++){
        if(a[num[i]]==1){
            cout<<num[i]<<endl;
            return 0;
        }
    }
    cout<<"None"<<endl;
    return 0;
}
