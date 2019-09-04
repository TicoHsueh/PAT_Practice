#include "bits/stdc++.h"
#define MAXN 3000
#define INF 1000000000
using namespace std;
map<string,int> strToInt;
map<int,string> intToStr;
map<string,int> Gang;//统计团伙信息 名字<->成员数
int G[MAXN][MAXN];
bool vis[MAXN] = {false};
int nameID = 0;
int n,m;
int callLen[MAXN];
int numMem = 0,totalCall = 0,head;
void DFS(int index) {
    if(!vis[index]) {
        vis[index] = true;
//    cout<<"curr:"<<index<<endl;
        if(callLen[index]>callLen[head]) {
            head = index;
        }
        for(int i=0; i<n; i++) {
            if(G[index][i]!=INF) {
//                cout<<intToStr[index]<<"->"<<intToStr[i];
//                cout<<":"<<G[index][i]<<endl;
                totalCall += G[index][i];
                if(!vis[i])
                    numMem++;
//                cout<<"Num:"<<numMem<<endl;
                G[i][index] = INF;
                G[index][i] = INF;
                DFS(i);
            }
        }

//    }
        return ;
    }
}

void DFS_Traverse() {
    for (int i = 0; i < n; ++i) {
//        if(!vis[i]) {
        numMem = 1;
        totalCall = 0;
        head = i;
        DFS(i);
//        if(numMem>0) {
//            cout<<"numMem"<<numMem<<endl;
//            cout<<"Tcall:"<<totalCall<<endl;
//        }
        if(totalCall>m&&numMem>2) {
            Gang[intToStr[head]] = numMem;
        }
//        }
    }
}

void change(string name) {
    if(strToInt.count(name)==0) {
        strToInt[name] = nameID;
        intToStr[nameID] = name;
        nameID++;
    }
}

int main() {
    cin>>n>>m;
    fill(G[0],G[0]+MAXN*MAXN,INF);
    fill(callLen,callLen+n,0);
    for(int i=0; i<n; i++) {
        string nameA,nameB;
        int length,idA,idB;
        cin>>nameA>>nameB>>length;
        change(nameA);
        change(nameB);
        idA = strToInt[nameA];
        idB = strToInt[nameB];
        if(G[idA][idB]==INF) {
            G[idA][idB] = 0;
            G[idB][idA] = 0;
        }
        G[idA][idB] += length;
        G[idB][idA] += length;
        callLen[idA] += length,callLen[idB] += length;
    }
    DFS_Traverse();
    cout<<Gang.size()<<endl;
    map<string, int>::iterator it;
    for(it=Gang.begin(); it!=Gang.end(); it++) {
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}
