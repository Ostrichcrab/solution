/*
两条不相交路径，即两个点在同一个强连通分量里
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
const int N = 5e4+9;
int stack[N];//每遍历一个点便入栈 
int top;
bool instack[N];//判断某个点是否在栈
int dfn[N],low[N];//时间戳、最早回点 
int belong[N];//判断那些点连通
int bcnt,dindex;//记录强连通的个数，当前时间
vector<int> v[N] ;//邻接表保存边 
int n,m,q;
void init()
{
	bcnt=dindex=top=0;
	memset(dfn,-1,sizeof(dfn));
	memset(instack,false,sizeof(instack));
	for(int i = 0; i < N; i++) v[i].clear();
}
void tarjan(int u, int fa)
{
	dfn[u]=low[u]=++dindex;
	stack[++top]=u;
	instack[u]=true;
	int u_size=v[u].size();
	for(int i = 0; i < u_size; i++)
	{
		int k = v[u][i];
		if(dfn[k]==-1)//没有访问过 
		{
			tarjan(k,u);
			low[u]=min(low[u],low[k]);
		}
		else if(instack[k] && k!=fa)
			low[u]=min(low[u],dfn[k]);
	}
	if(dfn[u]==low[u])
	{
		bcnt++;
		int tmp;
		do
		{
			tmp = stack[top--];
			belong[tmp]=bcnt;
			instack[tmp]=false;
		}while(tmp!=u);
	}
}
void solve()
{
	for(int i = 1; i<=n; i++)
		if(dfn[i]==-1)
			tarjan(i,-1);
}
int main()
{
	init();
	scanf("%d%d",&n,&m);
	for(int i = 0; i < m; i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	solve();
	scanf("%d",&q);;
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(belong[x]==belong[y])
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}