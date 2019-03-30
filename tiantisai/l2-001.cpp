#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define inf 0x3f3f3f3f
int n,m,s,d;
const int N = 555;
int team[N];
int road[N][N];
int vis[N];
int dis[N];
int ansb[N];
int ansa[N];
int before[N];
void path(int x)
{
    if(before[x]!=-1){
        path(before[x]);
        cout<<before[x]<<" ";
    }
}
void dijkstra()
{
    dis[s] = 0;
    vis[s] = 1;
    ansa[s] = 1;
    ansb[s] += team[s];
    for(int i = 0; i < n; i++)
    {
        int minn=inf; int k = s;
        for(int j = 0; j < n; j++)
        {
            if(!vis[j] && minn > dis[j])
            {
                minn = dis[j];
                k = j;
            }
        }
        vis[k] = 1;
        if(k == d) return ;
        for(int j = 0; j < n; j++)
        {
            if(road[k][j] != inf && !vis[j])
            {
                if(dis[k]+road[k][j]<dis[j])
                {
                    dis[j]=dis[k]+road[k][j];
                    ansa[j]=ansa[k];
                    ansb[j]=ansb[k]+team[j];
                    before[j]=k;
                }
                else if(dis[k]+road[k][j]==dis[j])
                {
                    ansa[j]+=ansa[k];
                    if(ansb[j]<ansb[k]+team[j])
                    {
                        ansb[j] = ansb[k]+team[j];
                        before[j] = k;
                    }
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m>>s>>d;
    memset(road,inf,sizeof(road));
    memset(vis,0,sizeof(vis));
    memset(dis,inf,sizeof(dis));
    memset(ansa,0,sizeof(ansa));
    memset(ansb,0,sizeof(ansb));
    memset(before,-1,sizeof(before));
    for(int i = 0; i < n; i++)
    {
        int a; cin>>a;
        team[i] = a;
    }
    for(int i = 0; i < m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        road[a][b]=road[b][a]=min(road[a][b],c);
    }
    dijkstra();
    cout<<ansa[d]<<" "<<ansb[d]<<endl;
    path(d);
    cout<<d<<endl;
    return 0;
}
