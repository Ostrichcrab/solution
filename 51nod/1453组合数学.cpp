/*
对于最后一种颜色n,我们只需要将它的c[i]个球中拿出一个放在最后就可以了,
这样就保证了他一定是在最后一个用完的,现在它的数量变成了c[i]-1,再将剩下的在剩余的位置C（res，s）种。
同理,安排完n,那么n-1也是没有限制的了,我们也需要把它拿出一个放在最后一个空位置,依次类推....这样就保证了
所有的都满足上述条件.然后将每种所有的可能情况相乘即可
*/
#include <stdio.h>
#include <math.h>
using namespace std;
#define ll long long
const int N = 1009;
const int mod = 1e9 + 7;
int c[N];
ll sum[N];
ll fac[N] = {1, 1}, inv[N] = {1, 1}, fi[N] = {1, 1};
void init()
{
    for (int i = 2; i < N; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        fi[i] = inv[i] * fi[i - 1] % mod;
    } //递推保存fac阶乘，和fi各个逆元取模相乘
}
ll C(ll a, ll b)
{
    return fac[a] * fi[b] % mod * fi[a - b] % mod; //C(a,b)=a!/(b!*(a-b)!)
}

int main()
{
    init();
    int n;
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &c[i]);
        sum[i] = sum[i-1] + c[i];
    }
    ll ans = 1;
    ll t = 1;
    for(int i= n; i >= 1; i--){
        ll t = c[i] - 1;
        ll tt = sum[i]-1;
        ans = ans*C(tt,t)%mod; 
    }
    printf("%lld\n",ans%mod);
    return 0;
}
