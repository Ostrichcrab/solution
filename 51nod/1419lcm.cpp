#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#define ll long long
using namespace std;
ll n;
int main()
{
    scanf("%lld",&n);
    if(n<3)
    {
        printf("%lld\n",n);
        return 0;
    }
    if(n&1){
        printf("%lld\n",n*(n-1)*(n-2));
    }
    else if(n%3==0){
        printf("%lld\n",(n-1)*(n-2)*(n-3));
    }else{
        printf("%lld\n",n*(n-1)*(n-3));
    }
    return 0;
}