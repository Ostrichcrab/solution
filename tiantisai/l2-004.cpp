
#include<bits/stdc++.h>
using namespace std;
const int N = 10010;
struct Node{
    int val;
    Node *lson, *rson;
    Node():lson(NULL),rson(NULL){}
}*root;
int n;
int s[N];
vector<int> ans;
bool test(bool kind, int l, int r)//true origion false mirror
{
    if(l >= r) return true;
    int i;
    for(i = l+1; i<=r; i++)
    {
        if(kind){
            if(s[l]<=s[i]) break;
        }else{
            if(s[l]>s[i]) break;
        }
    }
    bool flag = true;
    for(int j = i; j <= r; j++)
    {
        if(kind){
            if(s[j]<s[l]) flag = false;
        }else{
            if(s[j]>=s[l]) flag = false;
        }
    }
    if(flag) return test(kind,l+1,i-1)&&test(kind,i,r);
    else return false;
}
Node *create(bool kind, int l, int r)
{
    if(l>r) return NULL;
    int i;
    for( i = l+1; i<=r; i++)
    {
        if(kind){
            if(s[l]<=s[i]) break;
        }else{
            if(s[l]>s[i]) break;
        }
    }
    Node *p = new Node();
    p->val=s[l];
    p->lson=create(kind,l+1,i-1);
    p->rson=create(kind,i,r);
    return p;
}
void postOrderTraverse(Node *p)
{
    if(p)
    {
        postOrderTraverse(p->lson);
        postOrderTraverse(p->rson);
        ans.push_back(p->val);
    }
}
int main()
{
    cin>>n;
    for(int i = 0; i < n; i++) cin>>s[i];
    int flag = 0;
    if(test(true,0,n-1))
    {
        flag=1;
        root=create(true,0,n-1);
    }else if(test(false,0,n-1))
    {
        flag=2;
        root=create(false,0,n-1);
    }
    if(flag!=0)
    {
        postOrderTraverse(root);
        cout<<"YES"<<endl;
        for(int i = 0; i < ans.size()-1; i++) cout<<ans[i]<<" ";
        cout<<ans[ans.size()-1]<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}