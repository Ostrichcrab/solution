#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 10050;
int n,m;
int a[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 0; i<n; i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	int l = 0,r= n-1;
	int ans = 0;
	while(l<=r)
	{
		if(a[l]+a[r]<m){
			ans++;
			l++,r--;
		}
		else{
			ans++;
			r--;
		}
	}
	printf("%d\n",ans);
	return 0;
}
