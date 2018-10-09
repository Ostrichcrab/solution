/*
找规律。。。
当 a[i]都是1的时候
k = 0,1,2,3...的时候
*/
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
#define ll long long
const int N = 5009;
const int mod = 1e9+7;
ll a[N],inv[N];
void get_inv()
{
    inv[1] = 1;
    for(int i = 2; i < N; i++)
        inv[i]=((mod-mod/i)*inv[mod%i])%mod;
}
ll ans[N];
void init(int n, int k)
{
    ans[0] = 1;
    for(int i = 1; i <= n; i++)
        ans[i] = ((ans[i-1]*(k-1+i)%mod)*inv[i])%mod;
}
int main()
{
    get_inv();
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i = 1; i <= n; i++)
        scanf("%lld",&a[i]);
    init(n,k);
    for(int i = 1; i <= n; i++)
    {
        ll sum = 0;
        for(int j = 1; j <= i; j++)
            sum=(sum+ans[i-j]*a[j]%mod+mod)%mod;
        printf("%lld\n",sum);
    }
    return 0;
}