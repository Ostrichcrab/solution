/*
这题主线思路肯定是Trie对吧 
定义笔名和真名之间的相关度是他们之间的最长公共前缀 
题目要求分配笔名，使得匹配质量最大 
那么我们可以先按照真名建立一颗字典树，并且在经过的一条路线上的标记+1 
然后把所有笔名依次在字典树上匹配，从根开始遍历，如果当前标记大于0，答案+1，当前标记-1
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 8e5+9;
int np = 0, p[N][26], ans ;
int b[1000001];
char c[N];
inline void insert()
{
    int now =0, l = strlen(c+1);
    for(int i = 1; i<=l;i++)
    {
        int t = c[i] - 'a';
        if(!p[now][t]) p[now][t]=++np;
        now=p[now][t];
        b[now]++;
    }
}
inline void check()
{
    int now = 0, l = strlen(c+1);
    for(int i = 1; i<=l; i++)
    {
        int t = c[i] - 'a';
        if(!p[now][t]) break;
        now=p[now][t];
        if(b[now]) ans++,b[now]--;
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i = 1; i<=n; i++)
    {
        scanf("%s",c+1);
        insert();
    }
    for(int i = 1; i<=n; i++)
    {
        scanf("%s",c+1);
        check();
    }
    printf("%d",ans);
    return 0;
}