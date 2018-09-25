/*
���ÿ����ͳ�ƵĻ����Ͷ�ͳ����һ���������鷳�����Ծ͹�ͳ��֮ǰ��������ģ�
����ͳ�Ƶ�ͷ��û���ظ��ˣ�ֱ�Ӽ��±���У���ʡ�� 
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
	// ����һ�������٣���Ҫ�����ѭ����ǰ��������Ϊ�ڶ��ֲ���֮�еõ������l������һ��������Ҫ������ұ�һ���ڵ㡣
    // ֮���Դ���-1������Ϊ����ߵĽڵ�Ҳ��Ҫ�ж�
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
