#include "bits/stdc++.h"
#define ElemType int
using namespace std;
int post[40],in[40];
int n;
struct node
{
    ElemType data;
    node *lchild,*rchild;
};

node* createBTree(int postL,int postR,int inL,int inR)
{
    if(postL>postR) return NULL;
    node *root = new node;
    root->data = post[postR];
    root->lchild=root->rchild=NULL;
    int k,numLeft;
    for(int i=inL;i<=inR;i++){
        if(in[i]==post[postR]){
            k = i;
            break;
        }
    }
    numLeft = k-inL;
    root->lchild = createBTree(postL,postL+numLeft-1,inL,k-1);
    root->rchild = createBTree(postL+numLeft,postR-1,k+1,inR);
    return root;
}

void BFS(node *root)
{
    int num = 0;
    queue<node*> q;
    node *pfront;
    q.push(root);
    while(!q.empty())
    {
        pfront = q.front();
        q.pop();
        printf("%d",pfront->data);
        num++;
        if(num!=n) printf(" ");
        if(pfront->lchild!=NULL) q.push(pfront->lchild);
        if(pfront->rchild!=NULL) q.push(pfront->rchild);
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>post[i];
    for(int i=0;i<n;i++) cin>>in[i];
    node *root = createBTree(0,n-1,0,n-1);
    BFS(root);
    return 0;
}
