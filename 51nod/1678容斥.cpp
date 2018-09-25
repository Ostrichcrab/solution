/*题意：输入一个数A，为1时，将a[i]改成b；为2时，求gcd(i,j)=1的j对应的a[j]的和

思路：求i与1-n中互质的数，这个很眼熟，是一个经典的容斥，即将n素因子分解，对n的素因子及素因子的组合进行容斥，
最后用a[i]的和减去容斥的结果就是最后的结果了，但是如果直接求 某个素因子或者素因子的组合的 倍数和时，很容易超时，
所以可以先预处理这些数的倍数和。在修改时也需要修改这些已经预处理过的倍数和，和a[i]的总和，也对要修改的下标进行了素因子分解
*/
//一定注意边界一定注意边界一定注意边界，少写一个=，出到边界就是wa
#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
#define ll long long
const int N = 1e5+9;
ll data[N],gsum[N];
vector<ll> p;
int main()
{
    //freopen("in.txt","r",stdin);
    ll n,q;
    scanf("%lld%lld",&n,&q);
    ll sum = 0;
    for(ll i = 1; i <=n; i++)
    {
        scanf("%lld",&data[i]);
        sum += data[i];
    } //printf("%lld\n",sum);
    memset(gsum,0,sizeof(gsum));
    for(ll i = 1; i <= n; i++)
    {
        for(ll j = i; j <=n; j+=i)
            gsum[i] += data[j];
    }
    while(q--)
    {
        int a; scanf("%d",&a);
        if(a == 1)
        {
            ll b,c;
            scanf("%lld%lld",&b,&c);
            ll m = b;
            p.clear();
            for(ll i = 2; i*i<=m; i++)
            {
                if(m%i==0)
                {
                    p.push_back(i);
                    while(m%i==0) m /= i;
                }
            }
            if(m > 1) p.push_back(m);
            for(ll i = 1; i<(1<<p.size()); i++)
            {
                ll mul = 1, cnt = 0;
                for(ll j = 0; j < p.size(); j++)
                {
                    if(i & (1<<j))
                    {
                        cnt++;
                        mul *= p[j];
                    }
                }
                gsum[mul]=gsum[mul]-data[b]+c;
            }
            sum=sum-data[b]+c;
            data[b]=c;
        }
      else  if(a==2)
        {
            ll tmp,m;
            scanf("%lld",&tmp);
            ll ans=sum;
            m = tmp;
            p.clear();
            for(ll i = 2; i*i<=m; i++)
            {
                if(m%i==0)
                {
                    p.push_back(i);
                    while(m%i==0) m /= i;
                }
            }
            if(m > 1) p.push_back(m);
            ll S = 0;
            for(ll i = 1; i<(1<<p.size());i++)
            {
                ll mul = 1, cnt = 0;
                for(ll j = 0; j<p.size(); j++)
                {
                    if(i&(1<<j))
                    {
                        cnt++;
                        mul *= p[j];
                    }
                }
                if(cnt & 1)
                {
                    S = S + gsum[mul];
                }
                else{
                    S = S - gsum[mul];
                }
            } 
            printf("%lld\n",ans-S);
        }
    }
    return 0;
}