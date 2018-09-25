#include<cstdio>
using namespace std;
#define ull unsigned long long
const int inf = 0x3f3f3f3f;
const int N = 1e5+9;
int a[N],s[N],num[N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0; i<n; i++)
		scanf("%d",&a[i]);
	int head = 0;
	a[n] = inf;
	for(int i = n; i>=0;i--){
		while(head>0&&a[s[head]]<a[i]) head--;
		if(head == 0)  num[i] = 0;
		else num[i] = s[head] -i-1;
		s[++head] = i;
	}
	ull ans = 0;
	for(int i = 0; i<n; i++){
		ans+=num[i];
	}
	printf("%I64d\n",ans);
	return 0;
}
