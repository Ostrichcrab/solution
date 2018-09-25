#include<cstdio> 
#include<algorithm>
using namespace std;
const int N = 50+4;
int a[N],X;
int b[50];
bool vis[N];
int sum[50];
int main()
{
	int n;
	scanf("%d%d",&n,&X);
	for(int i = 0; i<n; i++)
		scanf("%d",&a[i]);
	int cnt = 0;
	while(X)
	{
		if(X&1) b[cnt++] = 1;
		else cnt++;
		X>>=1;
	}
	for(int i = 0; i<n; i++){
		int t = a[i]; int pos = 0;
		while(t)
		{
			if((t&1)&&(b[pos]==0)) {vis[i]=true ;break;}
			pos++;
			t>>=1;
		}
	}
	for(int i = 0; i<n; i++)
		if(!vis[i]) {
			int t = a[i]; int pos = 0;
			while(t)
			{
				if((t&1)&&b[pos]==1) {
					sum[pos]++;
					pos++;
				}
				else{
					pos++;
				}
				t>>=1;
			}
		}
	int ans = 60;
	for(int i = 0; i<cnt; i++){
	if(b[i]==1)	ans = min(ans,sum[i]);
	}
	printf("%d\n",ans);
	return 0;
}
