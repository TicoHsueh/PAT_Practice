#include "bits/stdc++.h"
using namespace std;

map<string,set<int> > mp_title,mp_author,mp_keywords,mp_pub,mp_year;
void lookInfo(set<int> st)
{
    set<int>::iterator it;
    int t = st.size();
    if(t==0) {
        printf("Not Found\n");
        return ;
    }
    int cnt = 0;
    for(it=st.begin(); it!=st.end(); it++) {
        printf("%07d\n",*it);
    }
}
int main()
{
    int n;
    cin>>n;
    int id;
    string title,author;
    string keyword,pub,year;
    while(n--) {
        cin>>id;
        getchar();
        getline(cin,title);
        getline(cin,author);
        mp_title[title].insert(id);
        mp_author[author].insert(id);
        int cnt = 0;
        while(cin>>keyword) {
            mp_keywords[keyword].insert(id);
            char c = getchar();
            if(c=='\n') break;
        }
        getline(cin,pub);
        cin>>year;
        mp_pub[pub].insert(id);
        mp_year[year].insert(id);
    }
    int m;
    cin>>m;
    while(m--) {
        int type;
        string quer;
        scanf("%d:",&type);
        getchar();
        getline(cin,quer);
        printf("%d: %s\n",type,quer.c_str());
        if(type==1) {
            lookInfo(mp_title[quer]);
        } else if(type==2) {
            lookInfo(mp_author[quer]);
        } else if(type==3) {
            lookInfo(mp_keywords[quer]);
        } else if(type==4) {
            lookInfo(mp_pub[quer]);
        } else if(type==5) {
            lookInfo(mp_year[quer]);
        }
    }
    return 0;
}
