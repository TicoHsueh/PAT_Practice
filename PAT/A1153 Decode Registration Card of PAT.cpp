#include "bits/stdc++.h"
using namespace std;
typedef struct node {
    string id;
    int score;
};
vector<node> v;

bool cmp(const node &a,const node &b)
{
    if(a.score!=b.score)
        return a.score > b.score;
    else
        return a.id < b.id;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        node n;
        string id;
        int score;
        cin>>id>>score;
        n.id = id;
        n.score = score;
        v.push_back(n);
    }
    int cmd;
    string s;
    int t = 1;
    for(int i=0; i<m; i++) {
        cin>>cmd>>s;
        vector<node> ans;
        cout<<"Case "<<t++<<": "<<cmd<<" "<<s<<endl;
        if(cmd==1) {
            for(int j=0; j<n; j++)
                if(v[j].id[0]==s[0]) ans.push_back(v[j]);
            if(ans.size()==0) {
               cout<<"NA"<<endl;
                continue;
            }
            sort(ans.begin(),ans.end(),cmp);
            for(int k=0; k<ans.size(); k++)
                cout<<ans[k].id<<" "<<ans[k].score<<endl;
        } else if(cmd==2) { //¿¼³¡ºÅ
            int total = 0;
            int cnt = 0;
            for(int l=0; l<n; l++) {
                if(s==v[l].id.substr(1,3)) {
                    total += v[l].score;
                    cnt++;
                }
            }
            if((cnt==total)&&cnt==0) {
                cout<<"NA"<<endl;
                continue;
            }
            cout<<cnt<<" "<<total<<endl;
        } else if(cmd==3) {
            for(int p=0; p<n; p++) {
                if(v[p].id.substr(4,6)==s) {
                    ans.push_back(v[p]);
                }
            }
            if(ans.size()==0) {
               cout<<"NA"<<endl;
                continue;
            }
            unordered_map<string,int> sid_num;
            for(int p=0; p<ans.size(); p++) {
                string site_id = ans[p].id.substr(1,3);
                if(sid_num.count(site_id)==0) {
                    sid_num[site_id] = 0;
                }
                sid_num[site_id]++;
            }
            ans.clear();
            for(auto it=sid_num.begin(); it!=sid_num.end(); it++) {
                node n;
                n.id = it->first;
                n.score = it->second;
                ans.push_back(n);
            }
            sort(ans.begin(),ans.end(),cmp);
            for(auto it=ans.begin(); it!=ans.end(); it++) {
                cout<<(*it).id<<" "<<(*it).score<<endl;
            }
        }
    }
    return 0;
}
