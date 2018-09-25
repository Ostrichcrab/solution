#include<cstdio>
#include<cstring>
using namespace std;
const int N = 5e4+6;
int s[N],p[N],a[N];
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 0; i<n; i++)
		scanf("%d",&a[i]);
	for(int i = 0; i<m; i++)
		scanf("%d",&p[i]);
	int head = 0;
	s[head++] = a[0];
	for(int i = 1; i<n; i++){
		if(s[head-1]<a[i]) {
			s[head] = s[head-1];
			head++;
		}
		else s[head++]=a[i];
	}
	int ans = 0;
	for(int i = 0; i<m; i++){
		while(s[head-1]<p[i]) head--;
		if(head<0) break;
		head--; ans++;
	}
	printf("%d\n",ans);
		return 0;
}
