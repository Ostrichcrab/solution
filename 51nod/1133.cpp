#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e4+5;
struct point
{
	int s,e;
	bool operator < (const point &t)const{
		return e<t.e;
	}
 }p[N];
 int main()
 {
 	ios::sync_with_stdio(false);
 	int n; cin>>n;
 	for(int i = 0; i<n; i++)
 		cin>>p[i].s>>p[i].e;
 	sort(p,p+n);
 	int ans = 1; int last = p[0].e;
 	for(int i = 1; i<n; i++)
 	{
 		if(p[i].s>=last) {
 			ans++; last=max(last,p[i].e);
		 }
	 }
	 cout<<ans<<endl;
	 return 0;
  } 
