#include<stdio.h>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
#define ll long long
const int N = 1e5+7;
struct Node
{
    double pric;
    double cnt;
    double cost;
}p[2000];
double t2[N];
double t1[N];
bool cmp(Node a, Node b )
{
    return a.pric>b.pric;
}
int main()
{

    ll n ;double sum;
    scanf("%lld%lf",&n,&sum);
    for(int i = 0; i < n; i++)
     scanf("%lf",&t1[i]);
    for(int i = 0; i < n; i++) 
    scanf("%lf",&t2[i]);
    for(int i = 0; i < n; i++)
    {
        p[i].cnt=t1[i];
        p[i].pric=(double)t2[i]/t1[i]; //cout<<p[i].price<<endl;
        p[i].cost=t2[i];
    }
    sort(p,p+n,cmp);
    double Sum = 0;
    ll pos=0;
    double ans = 0;
    // while(Sum + p[pos].cnt < sum)
    // {
    //     //ans += (double)(p[pos].pric*p[pos].cnt);
    //     ans += p[pos].cost;
    //     Sum += p[pos].cnt;
    //     pos++;
    // }
    // ans += (double)p[pos].pric*(Sum+p[pos].cnt-sum);
    for(int i = 0; i < n; i++)
    {
      if(p[i].cnt <= sum) ans+=p[i].cost;
      else{
        ans+=p[i].pric*sum; break;
      }
      sum-=p[i].cnt;
    }
    printf("%.2f",ans);
    return 0;
}