#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define ll long long
const int N = 1e5+9;
ll tot;
ll mu[N + 10];
ll prime[N + 10];
bool isprime[N + 10];
void Moblus(int n)
{
    tot = 0;
    mu[1] = 1;
    memset(isprime, 1, sizeof(isprime));
    isprime[0] = isprime[1] = 0;
    for (ll i = 2; i <= n; i++)
    {
        if (isprime[i])
        {
            prime[tot++] = i;
            mu[i] = -1;
        }
        for (ll j = 0; j < tot; j++)
        {
            if ((ll)i * prime[j] > n)
                break;
            isprime[i * prime[j]] = 0;
            if (i % prime[j] == 0)
            {
                mu[i * prime[j]] = 0;
                break;
            }
            else
            {
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
}
int main()
{
    Moblus(N);
    //freopen("in.txt","r",stdin);
    int T;
    int a,b,c,d,k;
    scanf("%d",&T);
    int ca = 1;
    while(T--)
    {
        ll ans1 = 0, ans2 = 0;
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        if(k == 0){
            printf("Case %d: %lld\n",ca++,ans1 - ans2 / 2);
            continue;
        }
        b /= k; d /= k;
        for(int i = 1; i<=min(b,d); i++)
            ans1 += mu[i]*(b/i)*(d/i);
        for(int i = 1; i <=min(b,d); i++)
            ans2 += mu[i]*(min(b,d)/i)*(min(b,d)/i);
        printf("Case %d: %lld\n",ca++,ans1 - ans2 / 2);
    }
    return 0;
}