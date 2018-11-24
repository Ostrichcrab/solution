// #include<stdio.h>
// #include<algorithm>
// #include<iostream>
// using namespace std;
// const int N = 1e3+9;
// int a[N];
// long long sum[N];
// int n,k;
// long long ans[N*N];
// int main()
// {
//     freopen("in.txt","r",stdin);
//     cin>>n>>k;
//     for(int i = 1; i <= n; i++)
//     {
//         cin>>a[i];
//         sum[i]=sum[i-1]+a[i];
//     }
//     int p=0;
//     for(int i = 0; i <= n; i++)
//     {
//         for(int j = 1; j<= n; j++)
//         {
//             ans[p++]=sum[j]-sum[i];
//         }
//     }
//     sort(ans,ans+p);
//     long long res = sum[n];
//     p--;
//     while(k--)
//     { //cout<<ans[p]<<endl;
//         res = res&ans[p--];
//     }
//     cout<<res<<endl;
//     return 0;
// }
#include <cstdio>
//位运算
#define maxn 1010
typedef long long ll;
int a[maxn];
ll s[maxn * maxn];
int main()
{
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	int t = 0;
	for (int i = 1; i <= n; ++i)
	{
		ll sum = 0;
		for (int j = i; j <= n; ++j)
			sum += a[j], s[++t] = sum;
	}
	ll ans = 0;
	for (int i = 40; ~i; --i)
	{
		int cnt = 0;
		for (int j = 1; j <= t; ++j)
			if (s[j] & (1ll << i)) ++cnt;
		if (cnt >= k)
		{
			int nt = 0;
			for (int j = 1; j <= t; ++j)
				if (s[j] & (1ll << i)) s[++nt] = s[j];
			t = nt;
			ans |= 1ll << i;
		}
	}
	printf("%lld\n", ans);
	return 0;
}