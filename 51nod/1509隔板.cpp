/*
这道题目也就是要将L分成4部分，允许为空，所以先L+4，表示每个部分至少为1，所以总共有L+4-1的空隙可以插板，我们需要插3个板，所以总的方法数为C（L+4-1,3）。
接下来求解不满足的个数:
构不成三角形的条件就是（假设c为最大边）：a+x+b+y<=c+z
同时还满足：x+y+z<=L
所以x+y<=min（c+z-a-b，l-z）
接下来我们只需要枚举z，然后求出x+y的值，把它的长度加到两根棒上，可以为0也可以剩余，这不就又是前面的隔板法了吗
*/
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define ll long long
ll a,b,c,l;
ll solve(ll a,ll b, ll c, ll l)//设c为最大边
{
    ll cnt = 0;
    for(int z = 0; z <=l; z++){
        ll x = min(c+z-a-b,l-z);
        if(x >= 0) cnt += (x+1)*(x+2)/2;
    }
    return cnt;
}
int main()
{
    scanf("%lld%lld%lld%lld",&a,&b,&c,&l);
    ll ans = (l+1)*(l+2)*(l+3)/6;
    ans -= solve(a,b,c,l);
    ans -= solve(a,c,b,l);
    ans -= solve(b,c,a,l);
    printf("%lld\n",ans);
    return 0;
}
