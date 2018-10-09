#include<stdio.h>
#include<string.h>
using namespace std;
int a[100];
int tag[100];
int n,flag;
const int inf = 0x3f3f3f3f;
void dfs(int now, int sum)
{
    if(flag == 1) return ;
    if(sum > n / 2) return ;
    if(now == n && sum == n/2)
    {
        flag = 1;
        return ;
    }
    tag[sum] = a[now];
    dfs(now+1,sum+1);
    tag[now] = inf;
    if(now-sum+1<=sum&&a[now]==tag[now-sum])//情况二，遇到能放到集合B里面的  放或者不放。
    {
        dfs(now+1,sum);
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    int t; scanf("%d",&t);
    while(t--)
    {
        flag = 0;
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i = 0; i < n; i++)
        {
            tag[i] = inf;
        }
        dfs(0,0);
        if(flag==1) printf("Good job!!\n");
        else printf("What a pity!\n");
    }
    return 0;
}