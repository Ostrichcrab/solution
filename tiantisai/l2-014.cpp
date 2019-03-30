#include<bits/stdc++.h>
using namespace std;
int main()
{
    set<int> s;
    set<int>::iterator it;
    s.clear();
    int n; cin>>n;
    while(n--)
    {
        int x; cin>>x;
        if(s.empty()){
            s.insert(x);
        }
        else
        {
            it = s.lower_bound(x);
            if(it==s.end())
            {
                s.insert(x);
            }
            else{
                s.erase(it);
                s.insert(x);
            }
        }
    }
    cout<<s.size()<<endl;
    return 0;
}