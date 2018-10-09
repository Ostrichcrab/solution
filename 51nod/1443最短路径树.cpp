#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
#define ll long long
const int N = 3e5+99;
int n,m,hd[N],xnt,to[N<<1],nxt[N<<1],w[N<<1],st,mn[N];
ll dis[N],ans;
bool vis[N];
priority_queue<pair<ll,int> >q;
void add(int x, int y, int z)
{
    to[++xnt]=y;nxt[xnt]=hd[x];hd[x]=xnt;w[xnt]=z;
    to[++xnt]=x;nxt[xnt]=hd[y];hd[y]=xnt;w[xnt]=z;
}
void dij()
{
    q.push(make_pair(0,st));
    memset(dis,0x3f,sizeof(dis));
    dis[st] = 0;
    while(!q.empty())
    {
        int k = q.top().second; q.pop();
        while(vis[k]&&q.size()) k = q.top().second,q.pop();
        if(vis[k]) break;
        vis[k] = 1;
        for(int i = hd[k],v;i;i=nxt[i])
        {
            if(dis[v=to[i]]>dis[k]+w[i])
            {
                dis[v]=dis[k]+w[i];
                q.push(make_pair(-dis[v],v));
                mn[v]=w[i];
            }
            else if(dis[v]==dis[k]+w[i])
            {
                mn[v] = min(mn[v],w[i]);
            }
        }
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    int u,z,v;
    for(int i = 1; i <= m; i++)
    {
        scanf("%d%d%d",&u,&v,&z);
        add(u,v,z);
    }
    scanf("%d",&st);
    memset(mn,0x3f,sizeof(mn));
    dij();
    for(int i = 1; i <= n; i++)
        if(i!=st) ans+=mn[i];
    printf("%lld\n",ans);
    return 0;
}