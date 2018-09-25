/*
问题可以转化为，在那些点上建边，一个幂等就是进入的环的长度，要满足所有都幂等就是所有的环的长度的最小公倍数，
但是有一点需要注意，如果一开始一个点没有在环上，且它到环上的距离大于最终的最小公倍数，此时答案应该一直+ans，
直到大于最大的步数
*/
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
#define ll long long
int f[205],n,m,l[205],u[205];
ll a = 1;
ll lcm(ll a, ll b){
	return a / __gcd(a,b)*b;
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&f[i]);
	for(int i=1;i<=n;i++)
	{
		memset(u,0,sizeof(u));
		int t=i,c=0;
		while(!u[t])
		{
			l[t]=c++;
			u[t]=true;
			t=f[t];
		}
		//printf("c=%d t=%d l[%d]=%d\n",c,t,t,l[t]); cout<<c-l[t]<<endl;
		a = lcm(a,(c-l[t]*1ll));
		m=max(m,l[t]);
	} //cout<<endl;
	ll t = a;
	while(a < m){
		a += t;
	}
	printf("%lld\n",a);
	return 0;
}