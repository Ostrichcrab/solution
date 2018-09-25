//https://blog.csdn.net/qq_33229466/article/details/78456066
/*分析一下两个字符串相似的条件不难得出实际上就是问有多少个字符串对(A,B)使得A和B循环同构。 
显然对于一个循环节为T的串A，共有T个不同的串B使得A和B循环同构。 
考虑枚举循环节。因为循环节必然是n的因数，所以先把n的所有因数求出来。不难发现n的因数个数最多只有1000个左右。 
设f[i]表示长度为i且循环节恰好为i的字符串有多少个。f[i]=ki−∑j|i f(j) 
因为i的因数也一定是n的因数，所以只要枚举所有小于i的n的因数即可。 
答案就是∑i|n i∗f(i)*/
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=50000+5,M=1e9+7;
int n,m,k,a,c,f[N],d[N];
inline int p(int x,int y){
    int r=1;
    while(y){
        if(y&1)r=1LL*r*x%M;
        x=1LL*x*x%M,y>>=1;
    }return r;
}
int main()
{
    scanf("%d%d",&n,&k);
    f[1] = k; m = sqrt(n);
    for(int i = 1; i<=m; i++)
    {
        if(n%i==0)
        {
            d[++c]=i;
            if(i*i!=n)
                d[++c]=n/i;
        }
    }
    sort(d+1,d+c+1);
    for(int i = 2; i<=c; i++)
    {
        f[i]=p(k,d[i]);
        for(int j = 1; j<i; j++)
        {
            if(d[i]%d[j]==0)
                f[i]=(f[i]-f[j]+M)%M;
        }
    }
    for(int i = 1; i<=c; i++)
        a = (a+1LL*d[i]*f[i]%M)%M;
    printf("%d\n",a);
    return 0;
}