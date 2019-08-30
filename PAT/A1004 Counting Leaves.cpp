#include "bits/stdc++.h"
#define MAXN 100100
using namespace std;
struct node
{
    int layer;
    vector<int> child;
};
int numOfLay[MAXN];
vector<node> Adj(MAXN);
int maxLayer;
void DFS(int index,int layer)
{
    if(layer>maxLayer)
        maxLayer = layer;
    if(Adj[index].child.size()==0)
    {
        numOfLay[layer]++;
        return ;
    }
    for(int i=0; i<Adj[index].child.size(); i++)
    {
        DFS(Adj[index].child[i],layer+1);
    }
}

int main()
{
    int n,non;
    cin>>n>>non;
    for(int i=0; i<non; i++)
    {
        int id,num,e;
        cin>>id>>num;
        for(int j=0; j<num; j++)
        {
            cin>>e;
            Adj[id].child.push_back(e);
        }
    }
    fill(numOfLay,numOfLay+n,0);
    DFS(1,0);
    for(int i=0; i<=maxLayer; i++)
    {
        printf("%d",numOfLay[i]);
        i==maxLayer? printf("\n"):printf(" ");
    }
    return 0;
}
