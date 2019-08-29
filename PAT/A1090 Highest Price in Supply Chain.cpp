#include "bits/stdc++.h"
#define MAXN 10005
using namespace std;
vector<int> Adj[MAXN];
int st = 0;
int n;
double p,r;
int numOfMax = 0;
int maxLayer = 0;
void DFS(int index,int layer)
{
    if(Adj[index].size()==0){//Reached the leaf point
        if(layer>maxLayer){
            maxLayer = layer;
            numOfMax = 1;
        }
        else if(layer==maxLayer)
            numOfMax++;
        return ;
    }

    for(int i=0;i<Adj[index].size();i++){
        int nextIndex = Adj[index][i];
        DFS(nextIndex,layer+1);
    }
    return ;
}

int main()
{
    cin>>n>>p>>r;
    r/=100;
    for(int i=0; i<n; i++)
    {
        int e;
        cin>>e;
        if(e==-1)
            st = i;
        else
            Adj[e].push_back(i);
    }
    DFS(st,0);
    printf("%.2f %d\n",p*pow(1+r,maxLayer),numOfMax);
    return 0;
}
