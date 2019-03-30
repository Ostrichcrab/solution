#include<bits/stdc++.h>
using namespace std;
int n,m,mp[506][506];
int book[504],flag[506];
void bfs(int x)
{
    queue<int> q;
    q.push(x);
    book[x] = 1;
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        for(int i = 0; i < n; i++)
        {
            if(flag[i] == 0 && mp[t][i]==1 && !book[i])
            {
                q.push(i);
                book[i] = 1;
            }
        }
    }
}
int main()
{
    int x,y,cnt;
    cin>>n>>m;
    memset(mp,0,sizeof(mp));
    memset(flag,0,sizeof(flag));
    for(int i = 0; i < m; i++)
    {
        cin>>x>>y;
        mp[x][y] = mp[y][x] = 1;
    }
    cnt = 0;
    memset(book,0,sizeof(book));
    for(int i = 0; i < n; i++)
    {
        if(!book[i])
        {
            bfs(i);
            cnt++;
        }
    }
    int q,cnt1;
    cin>>q;
    for(int i = 0; i < q; i++)
    {
        cin>>x;
        flag[x] = -1;
        cnt1 = 0;
        memset(book,0,sizeof(book));
        for(int i = 0; i < n; i++)
        {
            if(flag[i]==0 && !book[i])
            {
                bfs(i);
                cnt1++;
            }
        }
        if(cnt1 > cnt)
        {
            cout<<"Red Alert: City "<<x<<" is lost!"<<endl;
        }
        else
        {
            cout<<"City "<<x<<" is lost."<<endl;
        }
        cnt = cnt1;
    }
    if(q==n) cout<<"Game Over."<<endl;
    return 0;
}