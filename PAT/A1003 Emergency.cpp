#include "bits/stdc++.h"
#define MAXN 510
#define INF 1000000000
using namespace std;
int G[MAXN][MAXN];
bool vis[MAXN] = {false};
int w[MAXN],weight[MAXN],num[MAXN];
int dis[MAXN];
int n,m,st,ed;
void Dijkstra(int s)
{
    fill(dis,dis+MAXN,INF);
    fill(w,w+MAXN,0);
    fill(num,num+MAXN,0);
    dis[s] = 0;
    num[s] = 1;
    w[s] = weight[s];
    for(int i=0;i<n;i++){
        int u = -1,MIN = INF;
        for(int j=0;j<n;j++){
            if(!vis[j]&&dis[j]<MIN){
                u = j;
                MIN = dis[j];
            }
        }
        if(u==-1) return ;
        vis[u] = true;
        for(int v = 0;v<n;v++){
            if(!vis[v]&&G[u][v]!=INF){
                if(dis[u]+G[u][v]<dis[v]){
                    dis[v] = dis[u]+G[u][v];
                    w[v] = w[u] + weight[v];
                    num[v] = num[u];
                }else if(dis[u]+G[u][v]==dis[v]){
                    if(w[u]+weight[v]>w[v])
                        w[v] = w[u]+weight[v];
                    num[v] += num[u];
                }
            }
        }
    }
}


int main()
{
    cin>>n>>m>>st>>ed;
    for(int i=0;i<n;i++) cin>>weight[i];
    fill(G[0],G[0]+MAXN*MAXN,INF);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        cin>>G[a][b];
        G[b][a] = G[a][b];
    }
    Dijkstra(st);
    printf("%d %d\n",num[ed],w[ed]);
    return 0;
}
