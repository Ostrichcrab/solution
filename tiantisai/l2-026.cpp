#include<bits/stdc++.h>
using namespace std;
vector<int> d[100008],v;
int maxdep = -1,root;
void dfs(int root, int dep)
{
    if(dep == maxdep){
        v.push_back(root);
    }
    if(dep>maxdep)
    {
        maxdep=dep;
        v.clear();
        v.push_back(root);
    }
    for(int i = 0; i < d[root].size(); i++)
    {
        dfs(d[root][i],dep+1);
    }
}
int main()
{
    int n,x;
    cin>>n;
    for(int i = 1; i < n+1; i++)
    {
        cin>>x;
        if(x == -1)
        {
            root = i; continue;
        }
        d[x].push_back(i);
    }
    dfs(root,1);
    sort(v.begin(),v.end());
    cout<<maxdep<<endl;
    for(int i = 0; i < v.size(); i++)
    {
        if(!i) cout<<v[i];
        else cout<<" "<<v[i];
    }
    cout<<endl;
    return 0;
}