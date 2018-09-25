#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e4+9;
map<string,int> mp1,mp2;
int main()
{
	ios::sync_with_stdio(false);
	int n,q;
	cin>>n;
	for(int i = 0; i<n; i++){
		string t;
		cin>>t;
		mp1[t]++;
		sort(t.begin(),t.end());
		mp2[t]++;
	}
	cin>>q;
	for(int i = 0; i<q; i++)
	{
		string t;
		cin>>t;
		int t1 = mp1[t];
		sort(t.begin(),t.end());
		int t2 = mp2[t];
		cout<<t2-t1<<endl;
	}
	return 0;
 } 
