#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    Node *lchild;
    Node *rchild;
};
Node *build(int *mid, int *post, int len)
{
    if(len == 0) return NULL;
    int i = len - 1;
    while(post[len-1] != mid[i])
        --i;
    Node *h = new Node;
    h->val = post[len-1];
    h->lchild = build(mid,post,i);
    h->rchild = build(mid+i+1,post+i,len-i-1);
    return h;
}
int ans[35];
int cnt = 0;
Node *root = NULL;
void print(Node *t)
{
    queue<Node*> q;
    if(t->lchild) q.push(t->lchild);
    if(t->rchild) q.push(t->rchild);
    ans[cnt++]=t->val;
    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        ans[cnt++]=temp->val;
        if(temp->lchild) q.push(temp->lchild);
        if(temp->rchild) q.push(temp->rchild);
    }
}
int main()
{
    int n; cin>>n;
    int pos[35];
    int mid[35];
    for(int i = 0; i < n; i++) cin>>pos[i];
    for(int i = 0; i < n; i++) cin>>mid[i];
    root = build(mid,pos,n);
    print(root);
    for(int i = 0; i < cnt-1; i++)
        cout<<ans[i]<<" ";
    cout<<ans[cnt-1]<<endl;
    return 0;
}