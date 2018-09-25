#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define M 600600
using namespace std;
struct Trie{
    int cnt;
    Trie *son[2];
}*tree[M],node[14000000];
int n,m,tot,sum[M];
inline int getc() {
    static const int L = 1 << 15;
    static char buf[L], *S = buf, *T = buf;
    if (S == T) {
        T = (S = buf) + fread(buf, 1, L, stdin);
        if (S == T)
            return EOF;
    }
    return *S++;
}
inline int getint() {
    int c;
    while(!isdigit(c = getc()));
    int tmp = c - '0';
    while(isdigit(c = getc()))
        tmp = (tmp << 1) + (tmp << 3) + c - '0';
    return tmp;
}
inline int getch() {
    int c;
    while((c = getc()) != 'A' && c != 'Q');
    return c;
}
inline Trie* New_Node(int _,Trie*__,Trie*___)
{
    node[tot].cnt=_;
    node[tot].son[0]=__;
    node[tot].son[1]=___;
    return &node[tot++];
}
Trie* Build_Tree(Trie *p,int x,int pos)
{
    if(!pos)
        return New_Node(p->cnt+1,tree[0],tree[0]);
    if( (x&pos)==0 )
        return New_Node(p->cnt+1,Build_Tree(p->son[0],x,pos>>1),p->son[1]);
    else
        return New_Node(p->cnt+1,p->son[0],Build_Tree(p->son[1],x,pos>>1));
}
int Get_Ans(Trie *l,Trie *r,int x,int pos)
{
    int num=x&pos?1:0;
    if(!pos)
        return 0;
    if(r->son[!num]->cnt-l->son[!num]->cnt)
        return pos + Get_Ans(l->son[!num],r->son[!num],x,pos>>1);
    else
        return Get_Ans(l->son[num],r->son[num],x,pos>>1);
}
int main()
{
    int i,x,l,r;
    char p[10];
    tree[0]=New_Node(0,0x0,0x0);
    tree[0]->son[0]=tree[0]->son[1]=tree[0];
    tree[1]=Build_Tree(tree[0],0,1<<25);
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        x=getint();
        sum[i]=sum[i-1]^x;
        tree[i+1]=Build_Tree(tree[i],sum[i],1<<25);
    }
    for(i=1;i<=m;i++)
    {
        p[0]=getch();
        if(p[0]=='A')
        {
            x=getint();
            sum[n+1]=sum[n]^x;
            tree[n+2]=Build_Tree(tree[n+1],sum[n+1],1<<25);
            ++n;
        }
        else
        {
            l=getint();
            r=getint();
            x=getint();
            x^=sum[n];--l;--r;
            printf("%d\n", Get_Ans(tree[l],tree[r+1],x,1<<25) );
        }
    }
}
