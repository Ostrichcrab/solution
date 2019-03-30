#include<bits/stdc++.h>
using namespace std;
const int N = 35;
struct Node
{
    int val;
    Node *lson;
    Node *rson;
    Node(int a){
        val=a;
        lson=NULL;
        rson=NULL;
    }
};
Node *build(int *in, int *pre, int n)
{
    if(n == 0) return NULL;
    Node *root = new Node(pre[0]);
    int i = 0;
    for(;i<n; i++) if(in[i]==*pre) break;
    if(i > 0) root->lson=build(in,pre+1,i);
    if(n-i-1>0) root->rson=build(in+i+1,pre+i+1,n-i-1);
    return root;
}
void print(Node *root)
{
    queue<Node *> q;
    bool k = 0;
    if(root)
    {
        q.push(root);
        while(!q.empty())
        {
            Node *tmp = q.front();
            q.pop();
            if(k==0)
            {
                cout<<tmp->val;
                k = 1;
            }
            else cout<<" "<<tmp->val;
            if(tmp->rson) q.push(tmp->rson);
            if(tmp->lson) q.push(tmp->lson);
        }
    }
}
int inNode[N];
int preNode[N];
int main()
{
    int n; cin>>n;
    for(int i = 0; i < n; i++) cin>>inNode[i];
    for(int i = 0; i < n; i++) cin>>preNode[i];
    Node *root = NULL;
    root = build(inNode,preNode,n);
    print(root);
    return 0;
}