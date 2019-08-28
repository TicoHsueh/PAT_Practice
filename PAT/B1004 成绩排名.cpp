#include "cstdio"
#include "algorithm"
#include "iostream"
#define MAXN 10086
using namespace std;

typedef struct Stu
{
    char name[20];
    char id[30];
    int score;
};

Stu stus[MAXN];

void stuInfoInit(int n)
{
    int dir = 0;
    while(n--)
    {
        scanf("%s %s %d",stus[dir].name,stus[dir].id,&stus[dir].score);
        dir++;
    }
}

void gradeSort(int n)
{
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(stus[i].score<stus[j].score)
                swap(stus[i],stus[j]);
        }
    }
    printf("%s %s\n",stus[0].name,stus[0].id);
    printf("%s %s\n",stus[n-1].name,stus[n-1].id);
}

int main()
{
    int n;
    scanf("%d",&n);
    stuInfoInit(n);
    gradeSort(n);
    return 0;
}
/*
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

struct student
{
    char name[11];
    char id[11];
    int score;
}stu[1005];

bool cmp(student A,student B)
{
    return A.score>B.score;
}

int main()
{
    int T,iter;
    iter = 0;
    cin>>T;
    while(T--)
    {
        cin>>stu[iter].name>>stu[iter].id>>stu[iter].score;
        iter++;
    }
    sort(stu,stu+iter,cmp);
    cout<<stu[0].name<<" "<<stu[0].id<<endl;
    cout<<stu[iter-1].name<<" "<<stu[iter-1].id;
    return 0;
}

*/
