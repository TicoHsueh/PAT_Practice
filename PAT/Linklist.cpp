#include "iostream"
#include "stdio.h"
#include "stdlib.h"
#define OK 1
#define ERROR 0
#define Status int
#define ElemType int
#define NULL 0
using namespace std;

typedef struct LNode
{
    int data;
    LNode* next;
} LinkList,*Node;

Status addData(ElemType e,LinkList *L)
{
    Node p,q;
    p = (Node)malloc(sizeof(LNode));
    if(p==NULL)
        return ERROR;
    p->data = e;
    p->next = NULL;
    cout<<L<<" "<<L->next<<" "<<L->next->next<<endl;
//    while(q!=NULL)
//    {
//        cout<<"CurPtr:"<<q;
//        q = q->next;
//    }
//    q = p;
}

Status TraverseLinkList(LinkList L)
{
    Node p;
    p = &L;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    return OK;
}

Status InitLinkList(LinkList *L)
{
    L = (LinkList *)malloc(sizeof(LNode));
    L->next = NULL;
    if(L==NULL)
        return ERROR;
    return OK;
}

int main()
{
    LinkList L;
    InitLinkList(&L);
    int T = 5;
    while(T--)
    {
        ElemType e;
        cin>>e;
        addData(e,&L);
    }
    TraverseLinkList(L);
    return 0;
}
