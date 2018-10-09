/*
根据贪心策略，对每一位进行拆分，且拆出来的数字的个数越多越好，比如9!=9*8*7*6*5*4*3*2*1，7是素数，无法进行拆分，则后面的也不可进行拆分，
同时9*8=3*3*2*2*2=(3*2*1)*(3*2*1)*2=3!*3!*2!，即9!=3!*3!*2!*7!.以此类推.
*/
#include<stdio.h>
#include<algorithm>
using namespace  std;
#define ll long long
int ans[100];
int main()
{
    freopen("in.txt","r",stdin);
    ll x;
    scanf("%*d%lld",&x);
    int num = 0;
    while(x)
    {
        int t = x%10;
        if(t==9)
        {
            ans[num++]=3;
            ans[num++]=3;
            ans[num++]=2;
            ans[num++]=7;
        }
        else if(t==8)
        {
            ans[num++]=2;
            ans[num++]=2;
            ans[num++]=2;
            ans[num++]=7;
        }
        else if(t==6)
        {
            ans[num++]=3;
            ans[num++]=5;
        }
        else if(t==4)
        {
            ans[num++]=2;
            ans[num++]=2;
            ans[num++]=3;
        }
        else if(t!=1&&t!=0){
           ans[num++]=t;
        }
         x/=10;
    }
    sort(ans,ans+num);
    for(int i = num-1; i >=0; i--)
        printf("%d",ans[i]);
    printf("\n");
    return 0;
}