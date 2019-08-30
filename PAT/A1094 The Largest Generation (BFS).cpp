#include "bits/stdc++.h"
#define MAXN 100005
using namespace std;
struct node
{
    int layer;
    vector<int> child;
};
vector<node> Adj(MAXN);
int num[MAXN];//统计个数
bool vis[MAXN] = {false};
int n,cnt;

void BFS(int s)
{
    queue<int> q;
    fill(num,num+MAXN,0);
    q.push(s);
    vis[s] = true;
    Adj[s].layer = 1;
    num[s] = 1;
    while(!q.empty())
    {
        int frontnode = q.front();
        vector<int> Child = Adj[frontnode].child;
        q.pop();
        for(int i=0;i<Child.size();i++){
            int tempIndex = Child[i];
            Adj[tempIndex].layer = Adj[frontnode].layer + 1;
            int lay = Adj[tempIndex].layer;
            num[lay]++;
            if(!vis[tempIndex]){
                vis[tempIndex] = true;
                q.push(tempIndex);
            }
        }
    }
}
/*
1 0


*/
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
    BFS(1);
    int maxNum = -1,lay = 0;
    for(int i=0;i<=n;i++){
        if(num[i]>maxNum){
            maxNum = num[i];
            lay = i;
        }
    }
    printf("%d %d\n",maxNum,lay);
    return 0;
}
