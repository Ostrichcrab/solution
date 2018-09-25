#include<cstdio>
#include<iostream>
#include<cmath>
#define ll long long
using namespace std;
int main()
{
	int x;
	cin>>x;
	bool flag = false;
	for(int i = (int)sqrt(2*x); i>=2; i--)
	{
		if((2*x-i*i+i)%(2*i)==0){
			flag = true;
			cout<<(2*x-i*i+i)/(2*i)<<endl;
		}
	}
	if(!flag) cout<<"No Solution"<<endl;
	return 0;
}
