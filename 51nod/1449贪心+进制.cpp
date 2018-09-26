/*如果可以表示的话有两种形式分别是
w^a+w^b+w^c+......=m;  或者    w^a+w^b+w^c+....+m=w^A+w^B+w^C+......;
显然无m的一端可以用一个w进制的01串表示出来，因为每个砝码只有一个，所以有m的一端也要能这样表示出来才可，先把m用w进制表示出来，由低位开始递推。
如果这一位是01就跳过表示将对应的砝码放另一边，如果不是得话，只能考虑往这一位放砝码使其进位，不可行直接输出"NO",一直到最后。*/
//#include"pch.h"
#include<stdio.h>
#define ll long long
using namespace std;
const int N = 109;
int a[N];
int main()
{
	int w, m;
	scanf("%d%d", &w, &m);
	int  p = 0;
	while (m) {
		a[p++] = m % w;
		m /= w;
	}
	for (int i = 0; i < p; i++) {
		if (a[i] == 0 || a[i] == 1) continue;
		else if (a[i] == w - 1 || a[i] == w) {
			a[i + 1]++;
		}
		else {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}
