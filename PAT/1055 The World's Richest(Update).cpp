#include "bits/stdc++.h"
#define MAXN 100100
using namespace std;

struct node {
    string name;
    int age;
    int wealth;
};

bool cmp(node A,node B)
{
    if(A.wealth!=B.wealth) return A.wealth>B.wealth;
    else if(A.age!=B.age) return A.age<B.age;
    else return A.name<B.name;
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<node> vt(n),v;
    vector<int> book(250,0);
    for(int i=0; i<n; i++) cin>>vt[i].name>>vt[i].age>>vt[i].wealth;
    sort(vt.begin(),vt.end(),cmp);
    for(int i=0; i<n; i++) {
        if(book[vt[i].age]<100) {
            v.push_back(vt[i]);
            book[vt[i].age]++;
        }
    }
    int caseCnt = 1;
    for(int i=0; i<k; i++) {
        int index,minAge,maxAge;
        vector<node> res;
        cin>>index>>minAge>>maxAge;
        printf("Case #%d:\n",caseCnt++);
        int cnt = 0;
        for(int i=0;i<v.size();i++){
            if(v[i].age>=minAge&&v[i].age<=maxAge){
                res.push_back(v[i]);
                cnt++;
                if(cnt==index) break;
            }
        }
        if(res.size()!=0) {
            for(int k=0; k<res.size(); k++) {
                node p = res[k];
                cout<<p.name<<" "<<p.age<<" "<<p.wealth<<endl;
            }
        } else {
            printf("None\n");
        }
    }
    return 0;
}
