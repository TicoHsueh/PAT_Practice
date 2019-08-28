#include "bits/stdc++.h"
using namespace std;
int n,s,wigit;

struct node {
    int id;
    int weight;
    bool vis;
    vector<node> child;
};
vector<node> nodes;
vector<int> path;
void dfs(int currid,int sum)
{
//    cout<<"currid"<<currid<<"currSum:"<<sum<<endl;
    if(sum>wigit) return ;
    if(sum+nodes[currid].weight==wigit&&nodes[currid].child.size()==0) {
        path.push_back(nodes[currid].weight);
        for(int i=0; i<path.size(); i++) {
            printf("%d",path[i]);
            if(i!=path.size()-1) printf(" ");
            else printf("\n");
        }
        path.pop_back();
        return ;
    }

    for(int i=0; i<nodes[currid].child.size(); i++) {
        int id = nodes[currid].child[i].id;
//        cout<<"id:"<<id<<endl;
        if(!nodes[id].vis){
            nodes[id].vis = false;
            path.push_back(nodes[currid].weight);
            dfs(id,sum+nodes[currid].weight);
            path.pop_back();
        }
    }
}

bool cmp(const node &a,const node &b)
{
    return  a.weight > b.weight;
}
int main()
{
    cin>>n>>s>>wigit;
    for(int i=0; i<n; i++) {
        node p;
        p.id = i;
        p.vis = false;
        p.child.clear();
        cin>>p.weight;
        nodes.push_back(p);
    }
    int id,num,e;
    for(int i=0; i<s; i++) {
        cin>>id>>num;
        for(int j=0; j<num; j++) {
            node p;
            cin>>e;
            p = nodes[e];
            nodes[id].child.push_back(p);
        }
        sort(nodes[id].child.begin(),nodes[id].child.end(),cmp);
    }
    dfs(0,0);
//    for(int i=0;i<n;i++){
//        printf("id:%d\n",nodes[i].id);
//        for(int j=0;j<nodes[i].child.size();j++){
//            printf("cid:%d val:%d\n",nodes[i].child[j].id,\
//                   nodes[i].child[j].weight);
//        }
//    }
    return 0;
}
