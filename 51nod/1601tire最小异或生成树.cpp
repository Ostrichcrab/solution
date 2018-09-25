/*
我们将所有数字按照二进制位从高到低建到 Trie 上，按照 kruscal 思想，
我们要保证先选较小的边。
　　于是我们很容易得出结论：在 Trie 上，设 f(x)= 合并子树 x 的所有叶子节点的代价，
设 L(x),R(x) 分别为 x 的左右子树编号，则 f(x)=f(L(x))+f(R(x))+Connect(L(x),R(x)) 。
其中 Connect(a,b) 表示在 a 的叶子节点中 和 b 的叶子节点中各选择一个节点，并将他们相连，需要的最小代价。
这个显然非常容易求。
最后我们还有一个问题，就是当递归到 Trie 的叶子节点之后，我们发现它们代表的数字全部相同，连任意一条边的代价为 0 ，
求把它们连成一棵树的方案，就相当于有 k 个点的无根树计数。有一个东西叫做 pruffer 编码，通过这个东西可以得到 k 个点的互不相同的带标号无根树个数为 kk−2
*/#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5+9, mod = 1e9+7;
#define ll long long
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while (!isdigit(ch)&&ch!='-')
        ch=getchar();
    if (ch=='-')
        f=-1,ch=getchar();
    while (isdigit(ch))
        x=(x<<1)+(x<<3)+ch-48,ch=getchar();
    return x*f;
}
int trie[30*N][2],tot[N*30],dep[N*30],flag[N*30],cnt = 1;
int Pow(int x,int y){
    int ans=1;
    for (;y;y>>=1,x=1LL*x*x%mod)
        if (y&1)
            ans=1LL*ans*x%mod;
    return ans;
}
ll ans1 = 0, ans2 = 1;
void build(int v)
{
    int x = 1, t;
    for(int i = 29; i >=0; i--)
    {
        t = (v>>i)&1;
        if(!trie[x][t])
            trie[x][t] = ++cnt;
        x = trie[x][t];
        dep[x] = i, flag[x] = t;
    }
    tot[x]++;
}
int mindif,situ;
void min_cost_merge(int x, int y, int dif)
{
    dif |= (flag[x]^flag[y])<<dep[x];//add
    int f = 0;
    for(int k = 0; k<2; k++) //两个子树的0 1分别计算
    {
        for(int t = 0; t<2; t++)
            if(trie[x][t]>0&&trie[y][t^k]>0)
                min_cost_merge(trie[x][t],trie[y][t^k],dif), f = 1;
        if(f)
            return ;
    }
    if(dif<mindif)
        mindif = dif, situ = 0;
    if(dif==mindif)
        situ = (1LL*tot[x]*tot[y]+situ)%mod;
}
int slove(int x)
{
    if(!x)
        return 0;
    int s = slove(trie[x][0]) + slove(trie[x][1]);
    if(s == 0 && tot[x] > 1) //叶子节点数目>1(相同的值)
        ans2 = 1LL*ans2*Pow(tot[x],tot[x]-2)%mod;
    if(s==2){ //两颗子树
        mindif = 1<<30, situ = 1;
        min_cost_merge(trie[x][0],trie[x][1],0);
        ans1+=mindif,ans2 = 1LL*ans2*situ%mod;
    }
    return 1;
}
int main()
{
    //freopen("in.txt","r",stdin);
    memset(tot,0,sizeof(tot));
    memset(trie,0,sizeof(trie));
    for(int i = 1,n=read(); i <= n; i++)
        build(read());
    slove(1);
    printf("%lld\n%lld\n",ans1,ans2);
    return 0;
}