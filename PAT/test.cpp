#include "bits/stdc++.h"
using namespace std;
int data[20];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
        cin>>data[i];
    sort(data,data+t,cmp);
    for(int i=0; i<t; i++)
        cout<<data[i];
    return 0;
}
