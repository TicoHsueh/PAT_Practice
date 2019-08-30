#include "bits/stdc++.h"
#define MAXN 100010
#define INF 100000000
using namespace std;
int n;
double p,r;
vector<int> Adj[MAXN];
int minLay = INF;
int numOfLay[MAXN];
void DFS(int index,int layer)
{
    if(Adj[index].size()==0){
        if(layer<minLay){
            minLay = layer;
            numOfLay[layer] = 1;
        }else if(layer==minLay){
            numOfLay[layer]++;
        }
        return ;
    }

    for(int i=0;i<Adj[index].size();i++){
        DFS(Adj[index][i],layer+1);
    }
}

int main()
{
    cin>>n>>p>>r;
    r /= 100;
    for(int i=0;i<n;i++){
        int num,e;
        cin>>num;
        for(int j=0;j<num;j++){
            cin>>e;
            Adj[i].push_back(e);
        }
    }
    fill(numOfLay,numOfLay+n,0);
    DFS(0,0);
    cout<<minLay<<endl;
    printf("%.4f %d\n",p*pow(1+r,minLay),numOfLay[minLay]);
    return 0;
}
