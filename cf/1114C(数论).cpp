#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+9;
ll n,b;
ll p[N],k[N];
int cnt = 0;
void divide(ll x)
{
    ll sq = sqrt(x);
    ll ans = 0;
    for(ll i = 2; i * i <= x; i++)
    {
        if(x % i == 0)
        {
            p[++cnt] = i;
            while(x % i == 0)
            {
                x /= i;
                k[cnt]++;
            }
        }
    }
    if(x > 1)
    {
        p[++cnt] = x;
        k[cnt] = 1;
    }
}
ll f(ll x, ll y)
{
    if(x < y) return 0;
    else return x / y + f(x / y, y);
}
int main()
{
   ios::sync_with_stdio(false);
   //freopen("in.txt","r",stdin);
   cin>>n>>b;
   divide(b);
   ll ans = 1000000000000000000;
   for(int i = 1; i <= cnt; i++)
   {
       ans = min(ans,f(n,p[i]) / k[i]);
   }
   cout<<ans<<endl;
   return 0;
}

