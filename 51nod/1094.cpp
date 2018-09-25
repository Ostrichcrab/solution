#include<cstdio>
#include<map>
#define ll long long
using namespace std;
const int N = 1e4+9;
ll a[N],pre[N];
map<ll,int> mp;
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i = 1; i<=n; i++){
		scanf("%lld",&a[i]);
		pre[i]=pre[i-1]+a[i];
		mp[pre[i]]++;
	}
	for(int i = 0; i <=n; i++){
		if(mp[pre[i]+k]){
			for(int j = i; j<=n; j++){
				if(pre[j]-pre[i]==k){
					printf("%d %d",i+1,j);
					return 0;
				}
			}
		}
	}
	puts("No Solution");
	return 0;
}
