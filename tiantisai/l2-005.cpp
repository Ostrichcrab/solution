#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 10010;
set<ll> ss[M];
set<ll> ::iterator it;
double s(int a, int b)
{
    double x,y,up;
    up = 0;
    x = ss[a].size();
    y = ss[b].size();
    for(it = ss[a].begin(); it != ss[a].end(); it++)
    {
        if(ss[b].find(*it) != ss[b].end())
        {
            up++;
        }
    }
    return up / (x + y - up) * 100;
}
int main()
{
    int n,m;
    int a,b;
    while(~scanf("%d",&n))
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&m);
            for(int j = 0; j < m; j++)
            {
                scanf("%d",&a);
                ss[i].insert(a);
            }
        }
        int t;
        scanf("%d",&t);
        for(int i = 0; i < t; i++)
        {
            scanf("%d %d",&a,&b);
            printf("%.2f%%\n",s(a-1,b-1));
        }
    }
    return 0;
}