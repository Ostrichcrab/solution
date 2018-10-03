//由于最少的袋鼠数量也就是n/2取上整，那么可以排序，然后从[1,n/2] [n/2+1,n]两个部分中匹配
#include<stdio.h>
#include<algorithm>
using namespace std;
const int N = 5e5+99;
int a[N];
int n;
int main()
{
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int ans = n,mid = n/2;
    int ret = 0;
    for(int i = n; i >= 1; i--)
    {
        while(a[i]/2 < a[mid]) mid--;
        if(mid == 0) break;
        ret++;
        mid--;
    }
    printf("%d\n",ans-ret);
    return 0;
}