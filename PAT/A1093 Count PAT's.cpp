#include "bits/stdc++.h"
using namespace std;

int countPAT(string s)
{
    int nP,nA,nT;
    bool pf,af,tf;
    pf = af = tf = false;
    nP = nA = nT = 0;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='P')
        {
            if(!af&&!tf)
                nP++;
            pf = true;
        }
        else if(s[i]=='A')
        {
            if(pf)
                af = true;
            if(!tf&&pf)
                nA++;
        }
        else if(s[i]=='T')
        {
            if(af)
                tf = true;
            if(af&&pf)
                nT++;
        }
    }
}

int main()
{
    string s;
    getline(cin,s);
    bool pf,af,tf;
    pf = af = tf = false;
    int st,ed;
    st = ed = 0;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]!='T')
        {
            if(pf&&af&&tf)
            {
                st = ed;
                ed = i-st;
                string temp = s.substr(st,ed);
                cout<<temp<<endl;
            }
        }
        if(s[i]=='P')
        {
            if(!af&&!tf)
                pf = true;
        }
        else if(s[i]=='A')
        {
            if(pf&&!tf)
                af = true;
        }
        else
        {
            if(pf&&af)
                tf = true;
        }
    }
    return 0;
}
