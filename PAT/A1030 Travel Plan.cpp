#include "bits/stdc++.h"
#define INF 1000000000
#define MAXN 1000
using namespace std;
int n,m,s,d;
int G[MAXN][MAXN],Cost[MAXN][MAXN];
int dis[MAXN];
bool vis[MAXN];
void Dijskra(int st)
{
    fill(dis,dis+MAXN,INF);
    fill(vis,vis+MAXN,false);
    int num = 1;
    vis[st] = true;
    dis[st] = 0;
    vector<int> p;
    p.push_back(st);
    while(num<n) {
        for(int i=0;i<p.size();i++){
            if(dis[i])
        }
    }
//    if()
}

int main()
{
    cin>>n>>m>>s>>d;
    for(int i=0; i<m; i++) {
        int a,b,len,cos;
        cin>>a>>b>>len>>cos;
        G[a][b] = len;
        G[b][a] = len;
        Cost[a][b] = cos;
        Cost[b][a] = cos;
    }

    return 0;
}
