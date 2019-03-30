#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,flag;
int f[105];
int p[105][105]={0};
void init()
{
    for(int i = 1; i <= n; i++) f[i] = i;
}
int find(int x)
{
    return f[x]==x?f[x]:find(f[x]);
}
void merge(int a, int b)
{
    int fa=find(a);
    int fb=find(b);
    if(fa!=fb)
        f[fa]=fb;
}
int main()
{
    cin>>n>>m>>k;
    init();
    for(int i = 1; i <= m; i++)
    {
        cin>>x>>y>>flag;
        if(flag==1){
            merge(x,y);
        }else{
            p[x][y]=p[y][x]=-1;
        }
    }
    while(k--)
    {
        cin>>x>>y;
        int a = find(x);
        int b = find(y);
        if(a==b && p[x][y]!=-1)
        {
            puts("No problem");
        }else if(a!=b && p[x][y]!=-1)
        {
            puts("OK");
        }
        else if(a==b&&p[x][y]==-1){
            puts("OK but...");
        }else{
            puts("No way");
        }
    }
    return 0;
}