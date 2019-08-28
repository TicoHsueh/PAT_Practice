#include<stdio.h>
#include<queue>
#include<string.h>
#define MAXN 1005
using namespace std;
struct Point
{
    int x;
    int y;
} tmp,tmp2;
queue<Point>q;
int vis[1005][1005];
int a[1005][1005];
int d[4][2]= {0,1,0,-1,1,0,-1,0};//四个方向
int i,j;
int main()
{
    int n,m,p1,p2;
    while(scanf("%d%d%d%d",&n,&m,&p1,&p2)!=EOF)
    {
        int ans=1;
//        memset(a,0,sizeof(a));
        for(i=1; i<=n; i++)
            for(j=1; j<=m; j++)
                scanf("%d",&a[i][j]);
        while(!q.empty())//队列清空
        {
            q.pop();
        }
        memset(vis,0,sizeof(vis));//数组清空
        tmp.x = p1;
        tmp.y = p2;
        vis[tmp.x-1][tmp.y-1]=1;
        q.push(tmp);
        while(!q.empty())
        {
            tmp = q.front();
            q.pop();
            for(i=0; i<4; i++)//各方向搜索
            {
                tmp2.x = tmp.x + d[i][0];
                tmp2.y = tmp.y + d[i][1];
                if(a[tmp2.x][tmp2.y]<=a[p1][p2] && tmp2.x>=1 && tmp2.x<=n && tmp2.y>=1 && tmp2.y<=m && !vis[tmp2.x-1][tmp2.y-1])//入队条件
                {
                    ans++;//每淹没一点，答案加一
                    vis[tmp2.x-1][tmp2.y-1] = 1;//标记淹没点
                    a[tmp2.x][tmp2.y] = a[p1][p2];//淹没点与泉眼高度一致
                    q.push(tmp2);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

//#include "bits/stdc++.h"
//#define MAXN 1020
//using namespace std;
//int n,m;
//struct node {
//    int x,y;
//};
//int d[4][2]= {0,1,0,-1,1,0,-1,0};
//int g[MAXN][MAXN];
//int vis[MAXN][MAXN];
//queue<node> q;
//int main()
//{
//    int p1,p2;
//    node now,st,p;
//    while(scanf("%d %d %d %d",&n,&m,&p1,&p2)!=EOF) {
//        int cnt = 1;
////        memset(g,-1,sizeof(g));
//        memset(vis,0,sizeof(vis));
//        for(int i=1; i<=n; i++) {
//            for(int j=1; j<=m; j++) {
//                scanf("%d",&g[i][j]);
//            }
//        }
//        while(!q.empty()) {
//            q.pop();
//        }
//        st.x = p1;
//        st.y = p2;
//        q.push(st);
//        vis[p1-1][p2-1] = 1;
//        while(!q.empty()) {
//            now = q.front();
//            q.pop();
//            for(int i=0; i<4; i++) {
//                p.x = now.x + d[i][0];
//                p.y = now.y + d[i][1];
//                if(p.x>=1&&p.x<=n&&p.y>=1&&p.y<=m) {
//                    if(g[p.x][p.y]<=g[p1][p2]&&!vis[p.x-1][p.y-1]) {
//                        vis[p.x-1][p.y-1] = 1;
//                        g[p.x][p.y]=g[p1][p2];
//                        cnt++;
//                        q.push(p);
//                    }
//                }
//            }
//        }
//        printf("%d\n",cnt);
//    }
//    return 0;
//}
