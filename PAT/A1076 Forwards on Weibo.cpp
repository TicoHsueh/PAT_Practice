#include "bits/stdc++.h"
#define MAXN 2000
using namespace std;
int n,Layer;
bool inq[MAXN] = {false};
struct node {
    int id;
    int layer;
};
vector<node> Adj[MAXN];

int BFS(int s)
{
    node st;
    int cnt = -1;
    st.id = s;
    st.layer = 0;
    inq[s] = true;
    queue<node> q;
    q.push(st);
    while(!q.empty()) {
        node nFront = q.front();
        q.pop();
        for(int i=0; i<Adj[nFront.id].size(); i++) { //找关注i的节点
            node nowNode = Adj[nFront.id][i];
            nowNode.layer = nFront.layer + 1;
            if(!inq[nowNode.id]&&nowNode.layer<=Layer) {
                inq[nowNode.id] = true;
                q.push(nowNode);
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
}

int main()
{
    int e;
    cin>>n>>Layer;
    for(int i=1; i<=n; i++) {
        int num;
        cin>>num;
        for(int j=0; j<num; j++) {
            cin>>e;
            node n;
            n.id = i;
            n.layer = 0;
            Adj[e].push_back(n);
        }
    }
    int qur;
    cin>>qur;
    for(int i=0; i<qur; i++) {
        cin>>e;
        fill(inq,inq+n+2,false);
        BFS(e);
    }
    return 0;
}

/*
#include "bits/stdc++.h"
using namespace std;

typedef struct student
{
    int id;
    int grade[4];//A C M E
};
student stugrp[10086];
char subject[4] = {'A','C','M','E'};
int stuRank[1000000][4];
int numOfList = 0;
bool cmpByA(student A,student B)
{
    return A.grade[0]>B.grade[0];
}
bool cmpByC(student A,student B)
{
    return A.grade[1]>B.grade[1];
}
bool cmpByM(student A,student B)
{
    return A.grade[2]>B.grade[2];
}
bool cmpByE(student A,student B)
{
    return A.grade[3]>B.grade[3];
}

void rankSet(int storeSig)
{
    int rankNum = 0;
    int lastScore = stugrp[0].grade[storeSig];
    stuRank[stugrp[0].id][storeSig] = 0;
    for(int i=1; i<numOfList; i++)
    {
        if(stugrp[i].grade[storeSig]!=lastScore)
        {
            rankNum++;
        }
        stuRank[stugrp[i].id][storeSig] = rankNum;
        lastScore = stugrp[i].grade[storeSig];
    }
}
int findMin(int num[])
{
    int retVal = 10;
    int minVal = 10;
    for(int i=0; i<4; i++)
    {
        if(num[i]<minVal)
        {
            minVal = num[i];
            retVal = i;
        }
    }
    return retVal;
}
void rankTrav()
{
    for(int i=0; i<numOfList; i++)
    {
        printf("%d ",stugrp[i].id);
        printf("%d ",stugrp[i].grade[0]);
        for(int j=0; j<4; j++)
            printf("%d ",stuRank[stugrp[i].id][j]);
        printf("\n");
    }
}

int main()
{
    int M,N;
    scanf("%d%d",&N,&M);
    int dir = 0;
    memset(stuRank,-1,sizeof(stuRank));
    while(N--)
    {
        int tempSum = 0;
        scanf("%d",&stugrp[dir].id);
        for(int i=1; i<4; i++)
        {
            scanf("%d",&stugrp[dir].grade[i]);
            tempSum += stugrp[dir].grade[i];
        }
        stugrp[dir].grade[0] = tempSum;
        dir++;
    }
    numOfList = dir;
    sort(stugrp,stugrp+dir,cmpByA);
    rankSet(0);
    sort(stugrp,stugrp+dir,cmpByC);
    rankSet(1);
    sort(stugrp,stugrp+dir,cmpByM);
    rankSet(2);
    sort(stugrp,stugrp+dir,cmpByE);
    rankSet(3);
    int query = 0;
//    rankTrav();
    while(M--)
    {
        scanf("%d",&query);
        if(stuRank[query][0]!=-1)
            printf("%d %c\n",1+stuRank[query][findMin(stuRank[query])],subject[findMin(stuRank[query])]);
        else
            printf("N/A\n");
    }
    return 0;
}

*/
