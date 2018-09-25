#include<cstdio>
#include<iostream>
#define ll long long
using namespace std;
const int N = 1e5+9;
ll pre[N];
int s[N],l[N],r[N],a[N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1; i<=n; i++ ){
		scanf("%d",&a[i]);
		pre[i]=pre[i-1]+a[i];
	}
	int head = 0;
	for(int i = 1; i<=n; i++){
		while(head>0 && a[s[head]]>=a[i]) head--;
		if(head == 0) l[i] = 1;
		else l[i] = s[head] + 1;
		s[++head] = i;
	}
	head = 0;
	for(int i = n; i>=1; i--){
		while(head > 0&&a[s[head]]>=a[i]) head--;
		if(head ==0) r[i] = n;
		else r[i] = s[head] -1;
		s[++head] = i;
	}
	ll ans = 0;
	int le=0,ri=0;
	for(int i = 1; i<=n; i++){
		ll sum = pre[r[i]] - pre[l[i]-1];
		sum *= a[i];
		if(sum >= ans){
			le = l[i];
			ri = r[i];
			ans = sum;
		}
	}
	printf("%lld\n%d %d\n",ans,le,ri);
	return 0;
} 
