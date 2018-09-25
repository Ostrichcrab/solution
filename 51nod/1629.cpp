#include<cstdio>
#include<cmath>
const double pi = acos(-1.0);
using namespace std;
int main()
{
	long long s;
	scanf("%d",&s);
	double r = sqrt(s/(4*pi));
	double h = sqrt((s*s/(pi*pi*r*r))-(2*s/pi));
	double v = h*pi*r*r/3;
	printf("%f\n",v);
	return 0;
}
