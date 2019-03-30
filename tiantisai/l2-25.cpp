#include<bits/stdc++.h>
using namespace std;
int mp[10001][2];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i = 0; i < m; i++)
    {
        cin>>mp[i][0]>>mp[i][1];
    }
    int k; cin>>k;
    for(int o = 0; o < k; o++)
    {
        set<int> s;
        int t; cin>>t;
        int a;
        while(t--)
        {
            cin>>a;
            s.insert(a);
        }
        int flag  = 1;
        for(int i = 0; i < m; i++)
        {
            if(s.find(mp[i][0])==s.end()&&s.find(mp[i][1])==s.end())
            {
                flag = 0;
                break;
            }
        }
        if(flag == 0)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}