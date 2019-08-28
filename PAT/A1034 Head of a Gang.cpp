#include "bits/stdc++.h"
#define MAXN 3000
using namespace std;
int N,K;
map<string,int> node,numOfMem;
map<int,string> intToStr;
map<string,vector<string> > MemList;
set<string> nameSet;
int father[MAXN];

int findFather(int x)
{
    int a = x;
    while(x!=father[x])
    {
        x = father[x];
    }

    while(a!=father[a])
    {
        int k = father[a];
        father[a] = x;
        a = k;
    }
    return x;
}

void init()
{
    for(int i=0; i<MAXN; i++)
        father[i] = i;
}

void Union(int a,int b)
{
    int fa = findFather(a);
    int fb = findFather(b);
    if(fa!=fb)
    {
        father[fa] = fb;
    }
    return ;
}

int hashName(string s)
{
    int ans = 0;
    for(int i=0; i<s.length(); i++)
    {
        ans += (s[i]-'A')*26 + i;
    }
    return ans;
}

int main()
{
    cin>>N>>K;
    init();
    for(int i=0; i<N; i++)
    {
        string nameA,nameB;
        int Aid,Bid;
        int length;
        cin>>nameA>>nameB>>length;
        Aid = hashName(nameA);
        Bid = hashName(nameB);
        intToStr[Aid] = nameA;
        intToStr[Bid] = nameB;
        Union(Aid,Bid);
        if(node.count(nameA)==0)
        {
            node[nameA] = 0;
        }
        if(node.count(nameB)==0)
        {
            node[nameB] = 0;
        }
        node[nameA] += length;
        node[nameB] += length;
    }
    map<string,int>::iterator it;
    for(it=node.begin(); it!=node.end(); it++)
    {
        string s = it->first;
        int id = hashName(s);
        int t = findFather(id);
        string faName = intToStr[t];
        if(numOfMem.count(faName)==0)
        {
            numOfMem[faName] = 0;
        }
        numOfMem[faName]++;
        MemList[faName].push_back(s);
//        printf("%s's Fa:%d(%s)\n",s.c_str(),t,intToStr[t].c_str());
    }
    int maxLen = 0;
    for(it=numOfMem.begin(); it!=numOfMem.end(); it++)
    {
        if(it->second>2)
        {
            cout<<it->first<<" "<<it->second<<endl;
            vector<string> temp = MemList[it->first];
            for(int i=0; i<temp.size(); i++)
            {
                cout<<temp[i]<<" ";
            }
            cout<<endl;
        }
    }


    return 0;
}
