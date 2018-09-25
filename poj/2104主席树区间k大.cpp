#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
const int maxn = 1e5+9;
int rt[maxn*20],lson[maxn*20],rson[maxn*20],sum[maxn*20];
int tot;
int a[maxn],b[maxn];
int n,q;
void build(int &x, int l, int r)
{
    x = ++tot;
    sum[x] = 0;
    if(l==r) return ;
    int mid = (l+r)>>1;
    build(lson[x],l,mid);
    build(rson[x],mid+1,r);
}
void update(int &x, int last, int l, int r, int pos)
{
    x = ++tot;
    lson[x] = lson[last];
    rson[x] = rson[last];
    sum[x] = sum[last] + 1;
    if(l == r) return ;
    int mid = (l+r)>>1;
    if(pos<=mid) update(lson[x],lson[last],l,mid,pos);
    else update(rson[x],rson[last],mid+1,r, pos);
}
int query(int L, int R, int l, int r, int k)
{
    if(l==r) return l;
    int mid = (l+r)>>1;
    int cnt = sum[lson[R]]-sum[lson[L]];
    if(k<=cnt) return query(lson[L],lson[R],l,mid,k);
    else return query(rson[L],rson[R],mid+1,r,k-cnt);
}
int main()
{
    //int T;
    //scanf("%d",&T);
    //while(T--)
    //{
        scanf("%d %d",&n,&q);
        for(int i = 1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            b[i] = a[i];
        }
        sort(b+1,b+n+1);
        int m = unique(b+1,b+n+1) - (b+1);
        tot = 0;
        build(rt[0],1,m);
        for(int i = 1; i<=n; i++) a[i]=lower_bound(b+1,b+m+1,a[i])-b;
        for(int i = 1; i<=n; i++) update(rt[i],rt[i-1],1,m,a[i]);
        int x,y,k,ans;
        while(q--)
        {
            scanf("%d%d%d",&x,&y,&k);
            ans = query(rt[x-1],rt[y],1,m,k);
            printf("%d\n",b[ans]);
        }
    //}
    return 0;
}