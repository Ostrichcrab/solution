#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
#define ll long long
vector<int> a[N];
double z,r;
int b[N];
int n,k;
double dfs(int x, int t)
{
    double s = 0;
    if(a[x].size() == 0)
        s += b[x]*z*pow(1-r/100,t);
    else
    {
        for(int i = 0; i <(int)a[x].size(); i++)
            s += dfs(a[x][i],t+1);
    }
    return s;
}
int main()
{
    cin>>n>>z>>r;
    for(int i = 0; i < n; i++)
    {
        cin>>k;
        if(k == 0)
            cin>>b[i];
        else
        {
            int t;
            for(int j = 0; j < k; j++)
            {
                cin>>t;
                a[i].push_back(t);
            }
        }
    }
    printf("%lld\n",(long long)(dfs(0,0)));
    return 0;
}