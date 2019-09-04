#include "bits/stdc++.h"
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    map<int,vector<int> >p;
    for(int i=0; i<n; i++) {
        int a,b;
        cin>>a>>b;
        p[a].push_back(b);
        p[b].push_back(a);
    }
    while(m--) {
        int cnt,e;
        cin>>cnt;
        bool flag = false;
        int a[100000] = {0};
        while(cnt--) {
            cin>>e;
            if(!flag) {
                a[e] = 1;
                vector<int> temp;
                temp = p[e];
                for(int i=0; i<temp.size(); i++) {
                    if(a[temp[i]]==1) {
                        flag = true;
                    }
                }
            }
        }
        flag==true?printf("No\n"):printf("Yes\n");
    }
    return 0;
}
