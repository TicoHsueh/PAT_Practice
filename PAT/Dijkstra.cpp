#include "bits/stdc++.h"
#define MAXN 100
#define INF 0x3fffffff
using namespace std;
int G[MAXN][MAXN];
bool vis[MAXN]= {false};
int dis[MAXN];
//6 8
//0 1 1
//0 3 4
//0 4 4
//1 3 2
//2 5 1
//3 2 2
//3 4 3
//4 5 3

void Dijstra(int s,int n)
{
    fill(dis,dis+n,INF);
    dis[s] = 0;
//    vis[s] = true;
    int u,MIN;
    for(int i=0; i<n; i++)
    {
        u = -1,MIN = INF;
        for(int k=0; k<n; k++)
        {
            if(!vis[k]&&dis[k]<MIN)
            {
                u = k;
                MIN = dis[k];
            }
        }
        cout<<u<<endl;
        vis[u] = true;
        for(int j=0; j<n; j++)
        {
            if(!vis[j]&&G[u][j]!=INF&&dis[u]+G[u][j]<dis[j]) //¿ÉÓÅ»¯
            {
                dis[j] = dis[u]+G[u][j];
            }
        }
    }
}

int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) G[i][j] = INF;
    for(int i=0; i<e; i++)
    {
        int a,b;
        cin>>a>>b;
        cin>>G[a][b];
    }
    Dijstra(0,n);
    for(int i=0; i<n; i++)
        cout<<dis[i]<<" ";
    return 0;
}
