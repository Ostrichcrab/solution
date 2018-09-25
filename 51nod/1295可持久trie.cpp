#include<bits/stdc++.h>
using namespace std;
const int N = 5e4+9;
const int limit = 33;
int bin[65];
int tot;
int son[N*limit*2][2],val[N*limit*30];
int T[N];
void init()
{
	tot = 0;
	memset(son,-1,sizeof(son));
	memset(val,0,sizeof(val));
}
int insert(int root, int cur)
{
	if(cur < 0) return -1;
	int t = bin[cur-1];
	int rt = ++tot;
	val[rt] = val[root] + 1;
	son[rt][t^1] = son[root][t^1];//不需要更新的点
	son[rt][t] = insert(son[root][t],cur - 1);
	return rt;
}
int cal(int root1, int root2, int cur)
{
	if (cur < 0)
		return 0;
	int t = bin[cur-1];
	if(val[son[root2][t]]-val[son[root1][t]] > 0)
		return cal(son[root1][t],son[root2][t],cur-1) + (1<<(cur-1));
	return cal(son[root1][t^1],son[root2][t^1],cur-1);
}
int main()
{
	freopen("in.txt","r",stdin);
	int n,q;
	int x,l,r;
	while(scanf("%d",&n)!=EOF)
	{
		init();
		scanf("%d",&q);
		int x;
		for(int i = 1; i<=n; i++)
		{
			scanf("%d",&x);
			for(int j = 0; j<=limit; j++)
			{
				bin[j] = x%2;
				x /=2;
			}
			T[i] = insert(T[i-1],limit);
		}
		for(int i = 1; i <=q; i++)
		{
			scanf("%d%d%d",&x,&l,&r);
			for(int j = 0; j<=limit; j++)
			{
				bin[j] = 1 - x%2;
				x /=2;
			}
			printf("%d\n",cal(T[l],T[r+1],limit));
		}
	}
	return 0;
}