#include<bits/stdc++.h>
using namespace std;
#define N 100010
int le[N],ri[N],sex[N];
set<int> ance[3];
void bfs(int x, int loc)
{
    queue<int> q;
    q.push(x);
    int level = 1, last = x;
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        ance[loc].insert(t);
        if(le[t]!=-1) q.push(le[t]);
        if(ri[t]!=-1) q.push(ri[t]);
        if(t == last)
        {
            level++;
            last = q.back();
            if(level == 6) break;
        }
    }
    return ;
}
int main()
{
    int n,id,fa,ma;
    char se;
    memset(le,-1,sizeof(le));
    memset(ri,-1,sizeof(ri));
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>id;
        cin>>se;
        cin>>fa>>ma;
        sex[id] = (se == 'M'?1:0);
        le[id]=fa;
        ri[id]=ma;
        if(fa != -1)
        {
            sex[fa] = 1;
        }
        if(ma != -1)
        {
            sex[ma] = 0;
        }
    }
    int q,x,y;
    cin>>q;
    while(q--)
    {
        cin>>x>>y;
        if(sex[x] == sex[y])
        {
            cout<<"Never Mind\n";
            continue;
        }
        ance[0].clear();
        ance[1].clear();
        ance[2].clear();
        bfs(x,0);
        bfs(y,1);
        set_intersection(ance[0].begin(),ance[0].end(),ance[1].begin(),ance[1].end(),inserter(ance[2],ance[2].begin()));
		if(ance[2].size()) cout<<"No\n";
		else cout<<"Yes\n";
    }
    return 0;
}