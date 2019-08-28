#include "bits/stdc++.h"
#define MAXN 2000
using namespace std;
int father[MAXN];
bool isRoot[MAXN];
int findFather(int x)
{
    int a = x;
    while(x!=father[x]) {
        x = father[x];
    }
//    while(a!=father[a]) {
//        int z = a;
//        a = father[a];
//        father[z] = x;
//    }
    return x;
}

void Union(int a,int b)
{
    int fa = findFather(a);
    int fb = findFather(b);
    if(fa!=fb) {
        father[fa] = fb;
    }
}

int main()
{
    int t,cnt,stuNum,listNum;
    cin>>t;
    int p,k;
    while(t--) {
        cin>>stuNum>>listNum;
        cnt = 0;
        for(int i=1;i<=stuNum;i++) {
            father[i] = i;
        }
        for(int i=0;i<listNum;i++){
            cin>>p>>k;
            Union(p,k);
        }
        for(int i=1;i<=stuNum;i++){
            if(father[i]==i)
                cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
