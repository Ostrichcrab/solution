#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
//#define max(a,b) {return (a)>(b)?(a):(b);}
const int N = 3e4+1129;
int dp[N][500];
int n,t,Max,ans,d;
int a[N];
int dfs(int x, int y)
{
   
    if(x > Max) return 0;
    if(dp[x][y]!=-1) return dp[x][y];
    if(y > 1) dp[x][y] = max(dp[x][y],dfs(x+y-1,y-1)+a[x]);
    dp[x][y] = max(dp[x][y],dfs(x+y,y)+a[x]);
    dp[x][y] = max(dp[x][y],dfs(x+y+1,y+1)+a[x]);
    ans = max(ans,dp[x][y]); 
    return dp[x][y];
}
int main()
{
    memset(dp,-1,sizeof(dp));
    scanf("%d%d",&n,&d);
    for(int i = 1; i <= n; i++){
        scanf("%d",&t);
        a[t]++;
        Max = max(Max,t);
    }
    dfs(d,d);
    printf("%d\n",ans);
    return 0;
}