#include "bits/stdc++.h"
#define MAXN 100010
using namespace std;
struct node
{
    int layer;
    vector<int> child;
};
vector<node> Adj(MAXN);
int num[MAXN];
void DFS(int index,int layer)
{
    Adj[index].layer = layer;
    num[layer]++;
    if(Adj[index].child.size()==0){
        return ;
    }
    for(int i=0;i<Adj[index].child.size();i++){
        int id = Adj[index].child[i];
        DFS(id,layer+1);
    }
}

int main()
{
    int n,cnt;
    cin>>n>>cnt;
    for(int i=0;i<cnt;i++){
        int id,num;
        cin>>id>>num;
        for(int j=0;j<num;j++){
            int e;
            cin>>e;
            Adj[id].child.push_back(e);
        }
    }
    fill(num,num+n,0);
    DFS(1,1);
    int maxNum = -1,lay = 1;
    for(int i=0;i<=n;i++){
        if(num[i]>maxNum){
            maxNum = num[i];
            lay = i;
        }
    }
    printf("%d %d\n",maxNum,lay);
    return 0;
}
