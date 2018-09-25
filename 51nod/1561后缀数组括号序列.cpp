/*A代表(的数量，B代表)的数量...
如果(的数量多于)的数量，那么最有方案显然是添加A−B个)...反之亦然...
因为这两种情况的处理方法差不多，所以我们假定A>B...
因为是有循环位移操作的，所以我们我们证明一定存在一种添加方案可以使得循环位移之后在最后添加A−B个)
并且字典序最小...
证明如下：
我们把(设为+1)设为−1，那么合法的序列就是每个位置的前缀和都>=0，那么我们考虑找到最后一个坏点
(也就是不合法的点)，然后把这个位置到最后的字符全部移到前面，这样就满足了前缀没有坏点，
然后对于后面的坏点我们递归进行...
那么如何找到字典序最小的满足要求的原串排列，考虑是循环位移，所以我们倍增字符串，
那么一个合法的排列就是某个后缀的长度n的前缀，因为要字典序最小，所以我们通过后缀数组来解决...
我们找到每个后缀，判断是否合法，怎么判断自己YY吧，有益身心健康~~~*/
#include<algorithm>
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
const int maxn = 4e6-9;
int n,len,gs[maxn],sa[maxn],wb[maxn],wv[maxn],ran[maxn],sum[maxn],pre[maxn],suf[maxn];
char s[maxn],ans[maxn];
inline bool cmp(int *x, int a, int b, int l)
{
    return x[a]==x[b]&&x[a+l]==x[b+l];
}
inline void da(int *sa, int *x, int n, int m)
{
    int i,j,p,*y=wb;
    for(i=0;i<m;i++) gs[i]=0;
    for(i=0;i<n;i++) gs[x[i]]++;
    for(i=1;i<m;i++) gs[i]+=gs[i-1];
    for(i=n-1;~i;i--) sa[--gs[x[i]]]=i;
    for(j=1,p=1;p<n;j<<=1,m=p){
        for(i=n-j,p=0;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0;i<n;i++) wv[i]=x[y[i]];
        for(i=0;i<m;i++) gs[i]=0;
        for(i=0;i<n;i++) gs[wv[i]]++;
        for(i=1;i<m;i++) gs[i]+=gs[i-1];
        for(i=n-1;~i;i--) sa[--gs[wv[i]]]=y[i];
        p=1;swap(x,y);x[sa[0]]=0;
        for(i=1;i<n;i++) x[sa[i]]=cmp(y,sa[i],sa[i-1],j)?p-1:p++;
    }
}
int main()
{
    int i,j;
    scanf("%s",s);
    n = strlen(s);
    len = n<<1;
    for( i = 0; i<n; i++) ran[i]=(int)s[i]-39;
    for(i = n; i<len; i++) ran[i]=(int)s[i-n]-39,s[i]=s[i-n];
    da(sa,ran,len+1,5);
    for(i = 0; i< n; i++) sum[i]=sum[i-1]+(s[i]=='('?1:-1);
    pre[0]=sum[0];
    for(i = 1; i < n; i++) pre[i]=pre[i-1]>sum[i]?sum[i]:pre[i-1];
    suf[n-1]=sum[n-1];
    for(i = n-2; i>=0; i--) suf[i]=suf[i+1]>sum[i]?sum[i]:suf[i+1];
    for(i = 1; i<=len; i++)
    {
        if(sa[i]< n){//后缀至少有n个前缀
            int tmp,tmp1=suf[sa[i]]-sum[sa[i]-1],tmp2=sum[n-1]-sum[sa[i]-1]+pre[sa[i]-1];
            tmp=tmp1>tmp2?tmp2:tmp1;
            if(sum[n-1]>=0&&tmp>=0){
                for(j = 0; j<n;j++) ans[j]=s[sa[i]+j];
                for(j = 0; j<sum[n-1]; j++) ans[j+n]=')';
                puts(ans); break;
            }
            tmp-=sum[n-1];
            if(sum[n-1]<0&&tmp>=0){
                tmp-=sum[n-1];
                for(j = 0; j<tmp; j++) ans[j]='(';
                for(j = 0; j< n; j++) ans[j+tmp]=s[sa[i]+j];
                puts(ans); break;
            }
        }
    }
    return 0;
}