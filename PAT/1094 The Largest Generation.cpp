#include "bits/stdc++.h"
#define MAXN 100005
using namespace std;
struct node
{
    int layer;
    vector<int> child;
};
vector<node> Adj[MAXN];
int num[MAXN];//统计个数
bool vis[MAXN] = {false};
int n,cnt;

void BFS(int s)
{
    queue<node> q;
    node p = Adj[s];
    q.push(p);
    vis[s] = true;
    while(!q.empty())
    {
        node frontNode = q.front();
        vector<int> Child = frontNode.child;
        q.pop();
        for(int i=0;i<Child.size();i++){
            int tempIndex = Child[i];
            if(!vis[tempIndex]){
                vis[tempIndex] = false;
                q.push(p);
            }
        }
    }
}

int main()
{
    cin>>n>>cnt;
    for(int i=0;i<cnt;i++){
        int id,num,e;
        cin>>id>>num;
        vector<int> temp;
        for(int j=0;j<num;j++){
            cin>>e;
            temp.push_back(e);
        }
        Adj[id].child = temp;
    }
    return 0;
}
