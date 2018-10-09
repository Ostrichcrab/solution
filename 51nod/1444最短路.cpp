#include<stdio.h>
#include<string.h>
#include<vector>
#include<iostream>
#include<queue>
using namespace std;
int dis[3009][3009];
vector <int> mp[3009];
int vis[3009];
int s1,t1,l1,s2,t2,l2;
int n,m;
void bfs(int ss)
{
    memset(vis,0,sizeof(vis));
    for(int i = 1; i <= n; i++)
    {
        if(i == ss)
        {
            dis[ss][i] = 0;
        }
        else 
            dis[ss][i] = 0x3f3f3f3f;
    }
    queue<int> q;
    q.push(ss); int t = 0; 
    while(!q.empty())
    {  
        int u = q.front();
        vis[u] = 0; 
        q.pop();  
        for(int i = 0; i < mp[u].size(); i++)
        {
            int v = mp[u][i];
            if(dis[ss][v] > dis[ss][u] + 1)
            {
                dis[ss][v] = dis[ss][u] + 1;
                if(vis[v] == 0)
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return ;
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++) mp[i].clear();
    for(int i = 1; i <= m; i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    scanf("%d%d%d%d%d%d",&s1,&t1,&l1,&s2,&t2,&l2);
    for(int i = 1; i <= n; i++) bfs(i);
    int ans = dis[s1][t1] + dis[s2][t2];
    if(dis[s1][t1]>l1||dis[s2][t2]>l2)
    {
        printf("-1\n");
        return 0;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(dis[s1][i]+dis[i][j]+dis[j][t1]<=l1&&dis[s2][i]+dis[i][j]+dis[j][t2]<=l2)
            {
                ans = min(ans,dis[s1][i]+dis[i][j]+dis[j][t1]+dis[s2][i]+dis[j][t2]);
            }
            if(dis[s1][i]+dis[i][j]+dis[j][t1]<=l1&&dis[t2][i]+dis[i][j]+dis[j][s2]<=l2)
            {
                ans = min(ans,dis[s1][i]+dis[i][j]+dis[j][t1]+dis[t2][i]+dis[j][s2]);
            }
            if(dis[t1][i]+dis[i][j]+dis[j][s1]<=l1&&dis[s2][i]+dis[i][j]+dis[j][t2]<=l2)
            {
                ans = min(ans,dis[t1][i]+dis[i][j]+dis[j][s1]+dis[s2][i]+dis[j][t2]);
            }
            if(dis[t1][i]+dis[i][j]+dis[j][s1]<=l1&&dis[t2][i]+dis[i][j]+dis[j][s2]<=l2)
            {
                ans = min(ans,dis[t1][i]+dis[i][j]+dis[j][s1]+dis[t2][i]+dis[j][s2]);
            }
        }
    }
    printf("%d\n",m-ans);
    return 0;
}