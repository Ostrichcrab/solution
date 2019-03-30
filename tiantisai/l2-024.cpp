#include<bits/stdc++.h>
using namespace std;
const int N = 2e4;
int f[N];
int maxx = -1;
void Init(int n)
{
    for(int i = 0; i <= n; i++)
        f[i] = i;
}
int Find(int x)
{
    if(x != f[x]) f[x]=Find(f[x]);
    return f[x];
}
void Un(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if(x > y) f[x] = y;
    if(x < y) f[y] = x;
}
int main()
{
   // freopen("in.txt","r",stdin);
    int n; cin>>n;
    vector<vector<int>> v(n);
    Init(N);
    for(int i = 0; i < n; i++)
    {
        int k; cin>>k; 
        for(int j = 0; j < k; j++)
        {
            int t; cin>>t; 
            maxx = max(maxx,t);
            v[i].push_back(t);
        }
    } 
    for(int i = 0; i < v.size(); i++)
    {
        for(int j = 0; j < v[i].size()-1; j++)
        {
            Un(v[i][j],v[i][j+1]); 
        } 
    }
    // for(int i = 0; i < v.size()-1; i++)
    //     Un(v[i][0],v[i+1][0]);
    int cnt = 0;
    for(int  i = 1; i <= maxx; i++) {if(f[i]==i) cnt++;
   // cout<<f[i]<<" ";
    }
    cout<<maxx<<" "<<cnt<<endl;
    int q; cin>>q;
    while(q--)
    {
        int t1, t2;
        cin>>t1>>t2;
        if(Find(t1)==Find(t2)) cout<<"Y"<<endl;
        else cout<<"N"<<endl;
    }
    return 0;
}