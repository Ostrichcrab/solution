/*
如果每个都统计的话，就多统计了一倍，（还麻烦）所以就光统计之前与它相离的，
这样统计到头就没有重复了，直接加下标就行，简单省事 
*/
#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int N = 5e4+5;
struct point
{
	int l,r;
	bool operator < (const point t)const{
		if(r==t.r) return l<t.l;
		return r<t.r;
	}
}p[N];
int Binary_Search(int l,int r,int x)
{
	int mid;
	while(l < r)
	{
		mid=(l+r)>>1;
		if(p[mid].r >=x)
			r = mid -1;
		else
			l = mid + 1;
	}
	// 这里一定不能少，还要从这个循环往前遍历，因为在二分查找之中得到的这个l，并不一定是满足要求的最右边一个节点。
    // 之所以大于-1，是因为最左边的节点也需要判断
	while(l>-1 && p[l].r >=x)  l--;
	return l+1; 
}
int main()
{
	ios::sync_with_stdio(false);
	int n; cin>>n;
	int c,r;
	for(int i = 0; i<n; i++){
		cin>>c>>r;
		p[i].l=c-r;
		p[i].r=c+r;
	}
	sort(p,p+n);
	int ans = 0;
	for(int i = 0; i<n; i++)
		ans+=Binary_Search(0,i,p[i].l );
	cout<<ans<<endl;
	return 0;
}
