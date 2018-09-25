#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int temp = 0;
	int ans = 0;
	while(n)
	{
		temp=n%10;
		n/=10;
		ans = max(ans,temp);
	}
	printf("%d\n",ans);
	return 0;
} 
