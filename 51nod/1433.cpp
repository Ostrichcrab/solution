#include<cstdio>
using namespace std;
int c0,c5;
int n;
int main()
{
	scanf("%d",&n);
	int t;
	for(int i = 0; i<n; i++)
	{
		scanf("%d",&t);
		if(t==0) c0++;
		else c5++;
	}
	if(c0==0) {
		puts("-1");
		return 0;
	}
	if(c5<9){
		puts("0");
		return 0;
	}
	int a = c5%9;
	c5-=a;
	while(c5--) putchar('5');
	while(c0--) putchar('0');
	return 0;
}
