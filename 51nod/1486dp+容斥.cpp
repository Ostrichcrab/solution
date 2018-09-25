/*
算法】动态规划+组合数学
【题意】有一个h行w列的棋盘，定义一些格子为不能走的黑点，现在要求从左上角走到右下角的方案数。
【题解】
大概能考虑到离散化黑点后，中间的空格子直接用组合数计算。
然后解决容斥问题就很重要了。
定义f[i]为走到第i个黑点且不经过其它黑点的方案数。
f[i]=calc(x[i]-1,y[i]-1)-Σ(f[j]*calc(x[i]-x[j],y[i]-y[j])),j<i&&x[j]<=x[i]&&y[j]<=y[i]。
calc(n,m)表示向右n步，向下m步的方案数，即C(n+m,n)。
这个转移自带容斥功能，从另一方面考虑，一条路径到达黑点i，如果经过了若干黑点，那么只在它经过了第一个黑点的时候减去它。
那么f[i]减掉在其左上的所有f[j]（再乘j走到i的路径数）就可以减去这样的所有路径了。
最后在右下角(h,w)增加一个黑点统计答案。
*/
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
#define ll long long
const int N = 2010,MOD = 1e9+7;
int f[N],fac[200010],h,w,n;
struct node
{
    int x,y;
}a[N];
bool cmp(node a, node b){
    return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
void gcd(int a,int b,int &x,int &y){
    if(!b){x=1;y=0;}
    else{gcd(b,a%b,y,x);y-=x*(a/b);}
}
int inv(int a){
    int x,y;
    gcd(a,MOD,x,y);
    return ((x%MOD)+MOD)%MOD;
}
int calc(int n,int m){return 1ll*fac[n+m]*inv(fac[n])%MOD*inv(fac[m])%MOD;}
int main()
{
    scanf("%d%d%d",&h,&w,&n);
    fac[0] = 1;
    for(int i = 1; i <= h+w; i++) fac[i]=1ll*fac[i-1]*i%MOD;
    for(int i = 1; i<=n; i++) scanf("%d%d",&a[i].x,&a[i].y);
    a[++n]=(node){h,w};
    sort(a+1,a+1+n,cmp);
    f[0]=1;
    for(int i = 1; i<=n; i++)
    {
        f[i] = calc(a[i].x-1,a[i].y-1);
        for(int j = 1; j<i; j++)
        {
            if(a[j].x<=a[i].x&&a[j].y<=a[i].y)
            {
                f[i]=(f[i]+MOD-1ll*f[j]*calc(a[i].x-a[j].x,a[i].y-a[j].y)%MOD)%MOD;
            }
        }
    }
    printf("%d\n",f[n]);
    return 0;
}