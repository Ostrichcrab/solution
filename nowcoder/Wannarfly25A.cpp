#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
#define ll long long
vector <ll> pri;
map<ll ,ll> mp;
ll p,n;
ll work(ll n, ll x)
{
    ll ret = 0;
    while(n){
        ret += n/x;
        n /= x;
    }
    return ret;
}
int main()
{
    scanf("%lld%lld",&n,&p);
    ll ans = 1000000000000000001;
    for(ll i = 2; i <= p; i++){
        if(p%i==0){
            pri.push_back(i); mp[i]++;
            p/=i;
            while(p%i==0) {p/=i;
            mp[i]++;
            }
        }
    }
    // for(int i = 0; i < pri.size(); i++){
    //     printf("%d %d\n",pri[i],mp[pri[i]]);
    // }
    for(ll i = 0; i < pri.size(); i++){
        ll tt = work(n,pri[i])/mp[pri[i]];
        if(i==0) ans = tt;
        else 
        ans = min(ans,tt);
    }
    printf("%lld\n",ans);
    return 0;
}
