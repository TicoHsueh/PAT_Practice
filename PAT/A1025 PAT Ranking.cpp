#include "bits/stdc++.h"
using namespace std;

typedef struct kaosheng
{
    char ID[30];
    int score;
    int kcId;
};
kaosheng ksGroup[10086];
int totalKs;
bool cmp(kaosheng k1,kaosheng k2)
{
    if(k1.score!=k2.score)
        return k1.score>k2.score;
    else
        return strcmp(k1.ID,k2.ID)<0;
}
void traverse()
{
    int kcRank[200],kcLsSco[200],kcRecCnt[200];
    int curRank,LstSco,curCnt;
    memset(kcRank,0,sizeof(kcRank));
    memset(kcLsSco,0,sizeof(kcLsSco));
    memset(kcRecCnt,0,sizeof(kcRecCnt));
    int score,kcId;
    kcId = ksGroup[0].kcId;
    LstSco = ksGroup[0].score,curCnt = 1,curRank = 1;
    kcRank[kcId] = 1,kcLsSco[kcId] = ksGroup[0].score,kcRecCnt[kcId] = 1;
    printf("%s %d %d %d\n",ksGroup[0].ID,curRank,kcId,kcRank[kcId]);
    for(int i=1;i<totalKs;i++){
        score = ksGroup[i].score;
        kcId = ksGroup[i].kcId;
//        printf("score:%d\n",score);
        curCnt++;
        kcRecCnt[kcId]++;
//        printf("kid:%d cnt:%d\n",kcId,kcRecCnt[kcId]);
        if(score!=LstSco){
            curRank = curCnt;
            LstSco = score;
        }
        if(kcLsSco[kcId]!=score){
            kcLsSco[kcId] = score;
            kcRank[kcId] = kcRecCnt[kcId];
        }

        printf("%s %d %d %d\n",ksGroup[i].ID,curRank,kcId,kcRank[kcId]);
    }

}
int main()
{
    int Kcnt;
    scanf("%d",&Kcnt);
    int dir = 0,kcId = 1;
    int sumOfRec = 0;
    while(Kcnt--)
    {
        int numOfKs;
        scanf("%d",&numOfKs);
        sumOfRec += numOfKs;
        while(numOfKs--)
        {
            ksGroup[dir].kcId = kcId;
            scanf("%s %d",ksGroup[dir].ID,&ksGroup[dir].score);
            dir++;
        }
        kcId++;
    }
    totalKs = dir;
    sort(ksGroup,ksGroup+dir,cmp);
    printf("%d\n",sumOfRec);
    traverse();
    return 0;
}
