/*
5 6 7 8 9这样的序列只对于5来说的话，求对5的mod最大值，会发现其实并不需要求6%5，7%5，8%5，我只需要求5和10之间最大的那一个就可以，如果还有更大的就求10到15之间最大的，以此类推下去。
所以这道题也是这样，不用逐一暴力，只需对每一个Ai，挑选合适的Aj就好，时间就能省下来了。
*/
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
const int N = 2e5+99;
int a[N];
int n,ans;
int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; i++) scanf("%d",&a[i]);
    sort(a,a+n);
    for(int i = 0; i < n-1; i++)
    {
        if(i ==0 || a[i]!=a[i-1])
        {
            int j = a[i]+a[i],p;
            while(j <= a[n-1])
            {
                p = lower_bound(a,a+n,j)-a;
                if(p>0) ans=max(ans,a[p-1]%a[i]);
                j+=a[i];
            }
            ans=max(ans,a[n-1]%a[i]);
        }
    }
    printf("%d\n",ans);
    return 0;
}