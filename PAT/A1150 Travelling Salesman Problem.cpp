#include "bits/stdc++.h"
#define INF -1
#define MAXN 1000
using namespace std;
int G[MAXN][MAXN];
int n,m;
int traverse(vector<int>path,int &dis)
{
    int res = -1;
    int a[MAXN];
    fill(a,a+MAXN,2);
    dis = 0;
    for(int i=0; i<path.size()-1; i++) {
        a[path[i]]--;
        a[path[i+1]]--;
        int t = G[path[i]][path[i+1]];
        if(t!=INF)
            dis += t;
        else {
            dis = -1;
            break;
        }
    }
    bool flag = false;
    for(int i=1; i<=n; i++) {
        if(a[i]<0) {
            flag = true;
        }
        if(a[i]>0) {
            return 3;
        }
    }
    if(flag) return 2;
    else return 1;
    return res;
}

int main()
{
    cin>>n>>m;
    fill(G[0],G[0]+MAXN*MAXN,INF);
    for(int i=0; i<m; i++) {
        int a,b,dis;
        cin>>a>>b>>dis;
        G[a][b] = dis;
        G[b][a] = dis;
    }
    int k;
    cin>>k;
    int minIndex = -1,minVal = 1000000;
    for(int i=1; i<=k; i++) {
        int t,e,dis,res;
        cin>>t;
        vector<int> temp;
        while(t--) {
            cin>>e;
            temp.push_back(e);
        }
        res = traverse(temp,dis);
        if(dis!=-1) {
            if(dis<minVal&&res!=3) {
                minIndex = i;
                minVal = dis;
            }
            printf("Path %d: %d (",i,dis);
        } else {
            printf("Path %d: NA (",i);
        }
        if(res==1) printf("TS simple cycle");
        else if(res==2) printf("TS cycle");
        else if(res==3) printf("Not a TS cycle");
        printf(")\n");
    }
    printf("Shortest Dist(%d) = %d\n",minIndex,minVal);
    return 0;
}
