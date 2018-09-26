/*
要求的就是素数因子的个数，相同的素数因子个数也要相加。然后求前缀和。
*/
//#include"pch.h"
#include<stdio.h>
#include<string.h>
#define ll long long
using namespace std;
const int N = 5e6+9;
int  prime[N], sum[N];
void init()
{
	memset(sum, 0, sizeof(sum));
	memset(prime, 0, sizeof(prime));
	int tmp;
	prime[1] = 0;
	for (int i = 2; i < N; i++) {
		if (prime[i] == 0) {
			for (int j = i; j < N; j += i) {
				tmp = j;
				while (tmp % i == 0) {
					tmp /= i;
					sum[j]++;
				}
				prime[j] = 1;
			}
		}
	}
	for (int i = 1; i < N; i++)
		sum[i] += sum[i - 1];
}
int main()
{
	int t, a, b;
	scanf("%d", &t);
	init();
	while (t--) {
		scanf("%d%d", &a, &b);
		printf("%d\n", sum[a] - sum[b]);
	}
	return 0;
}
