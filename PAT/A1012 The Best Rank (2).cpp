#include "bits/stdc++.h"
using namespace std;
struct node {
    string id;
    int C,M,E;
    int SUM;
    node(string id,int C,int M,int E)
    {
        this->id = id,this->C = C,this->M = M,this->E = E;
        this->SUM = C+M+E;
    }
};
int sortCmd;
vector<node> RankList[4];
char sortBy[4] = {'A','C','M','E'};
bool cmp(const node &a,const node &b)
{
    if(sortCmd==1) {//A
        return a.SUM > b.SUM;
    } else if(sortCmd==2) {//C
        return a.C > b.C;
    } else if(sortCmd==3) {//M
        return a.M > b.M;
    } else if(sortCmd==4) {//E
        return a.E > b.E;
    }
}

vector<node> stus;

int rankFind(vector<node> p,string id,int type)
{
    if(type==0) { //A
        int rankNum = 0,lastScore,CurrScore;
        CurrScore = lastScore = -1;
        for(int i=0; i<p.size(); i++) {
            CurrScore = p[i].SUM;
            if(CurrScore!=lastScore) {
                rankNum = i+1;
                lastScore = CurrScore;
            }
            if(p[i].id==id)
                return rankNum;
        }
    } else if(type==1) { //C
        int rankNum = 0,lastScore,CurrScore;
        CurrScore = lastScore = -1;
        for(int i=0; i<p.size(); i++) {
            CurrScore = p[i].C;
            if(CurrScore!=lastScore) {
                rankNum = i+1;
                lastScore = CurrScore;
            }
            if(p[i].id==id)
                return rankNum;
        }
    } else if(type==2) { //M
        int rankNum = 0,lastScore,CurrScore;
        CurrScore = lastScore = -1;
        for(int i=0; i<p.size(); i++) {
            CurrScore = p[i].M;
            if(CurrScore!=lastScore) {
                rankNum = i+1;
                lastScore = CurrScore;
            }
            if(p[i].id==id)
                return rankNum;
        }
    } else if(type==3) { //E
        int rankNum = 0,lastScore,CurrScore;
        CurrScore = lastScore = -1;
        for(int i=0; i<p.size(); i++) {
            CurrScore = p[i].E;
            if(CurrScore!=lastScore) {
                rankNum = i+1;
                lastScore = CurrScore;
            }
            if(p[i].id==id)
                return rankNum;
        }
    }
    return -1;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        string id;
        int C,M,E;
        cin>>id>>C>>M>>E;
        stus.push_back(node(id,C,M,E));
    }
    for(sortCmd=1; sortCmd<=4; sortCmd++) {
        sort(stus.begin(),stus.end(),cmp);
        RankList[sortCmd-1] = stus;
    }
    for(int i=0; i<m; i++) { //m次查询
        string qid;
        int t;
        int minRank = 500000,sortid = -1;
        cin>>qid;
        for(int j=3; j>=0; --j) { //四个表查询
            t = rankFind(RankList[j],qid,j);
            if(t==-1) {
                cout<<"N/A"<<endl;
                break;
            } else if(t<=minRank) {
                minRank = t;
                sortid = j;
            }
        }
        if(t!=-1)
            cout<<minRank<<" "<<sortBy[sortid]<<endl;
    }
    return 0;
}
