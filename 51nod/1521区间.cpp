/*
1,在一段距离能放战舰的数量是: (r - l)/(a + 1); 其中 r l 是开边界。 
2， 那么中间被一个元素隔开，两端孤立的距离段则是： (r - mid)/(a + 1),  (mid - l)/(a + 1) 
所以，按照上面的思路，可以进行计算。 
*/
#include<cstdio>
using namespace std;
const int N = 2e5+7;
int A[N];
int n,k,a,m;
int main()
{
	scanf("%d%d%d%d",&n,&k,&a,&m);
	int t;
	int maxx = (n+1)/(a+1);
	int num = 0;
	int ans = -1;
	for(int i = 1; i<=m; i++)
	{
		scanf("%d",&t);
		int left,right;
		for( left = t-1; left>=1&&!A[left]; left--) ;
		for(right = t+1; right<=n&&!A[right]; right++);
		maxx -= (right - left)/(a+1) - (t-left)/(a+1) - (right-t)/(a+1);
		if(maxx<k)
		{
			ans = i;
			break;
		}
		A[t] = 1;
	}
	printf("%d\n",ans);
	return 0;
}
