#include "bits/stdc++.h"
#define INF 1000000
using namespace std;
const int MAXN = 2000;
int G[MAXN][MAXN];
int Tcost[MAXN][MAXN];
int dis[MAXN],rcost[MAXN];
bool vis[MAXN];
int pre[MAXN];
void Dijkstra(int st,int n)
{
    fill(dis,dis+MAXN,INF);
    fill(vis,vis+MAXN,false);
    fill(pre,pre+MAXN,-1);
    fill(rcost,rcost+MAXN,0);
    dis[st] = 0;
    pre[st] = st;
    for(int i=0; i<n; i++) {
        int u = -1,minVal = INF;
        for(int j=0; j<n; j++) {
            if(!vis[j]&&dis[j]<minVal) {
                minVal = dis[j];
                u = j;
            }
        }
        if(u==-1) return ;
        vis[u] = true;
        for(int v=0; v<n; v++) {
            if(!vis[v]&&G[u][v]!=INF) {
                if(dis[u]+G[u][v]<dis[v]) {
                    dis[v] = dis[u]+G[u][v];
                    rcost[v] = rcost[u]+Tcost[u][v];
                    pre[v] = u;
                } else if(dis[u]+G[u][v]==dis[v]) {
                    if(rcost[u]+Tcost[u][v]<rcost[v]){
                        rcost[v] = rcost[u]+Tcost[u][v];
                        pre[v] = u;
                    }
                }
            }
        }
    }
}
void DFS(int u)
{
//    for(int i=0; i<4; i++) {
//        printf("pre%d:%d\n",i,pre[i]);
//    }
    if(pre[u]==u){
        cout<<u<<" ";
        return ;
    }
    DFS(pre[u]);
    printf("%d ",u);
}
int main()
{
    int n,m,s,t;
    fill(G[0],G[0]+MAXN*MAXN,INF);
    cin>>n>>m>>s>>t;
    while(m--) {
        int a,b,len,cost;
        cin>>a>>b>>len>>cost;
        G[a][b] = len;
        G[b][a] = len;
        Tcost[a][b] = cost;
        Tcost[b][a] = cost;
    }
    Dijkstra(s,n);
    DFS(t);
    cout<<dis[t]<<" "<<rcost[t]<<endl;
    return 0;
}
