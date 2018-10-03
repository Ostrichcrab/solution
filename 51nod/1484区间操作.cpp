/*
很容易将题意转化为区间交与区间并的问题。由于题目只要求出1个合法的值，所以取巧用了一些方法。
先判断ans=1的情况下，所有的区间交是否为空，如果不为空，求出区间交。这个很容易求出。
对于ans=0的情况，将所有点对离散。为了方便，用了map进行离散操作。
mp[not_lef]-=inf;
mp[not_rig+1]+=inf
这样，但凡值为 -inf 的区间，都为非法区间。
将之前求出的合法区间交也加入map中
mp[yes_lef]++;
mp[yes_rig+1]--;
综上，但凡值为1的区间，都是合法区间。所以只要判断这个合法区间的大小就行了。
*/
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;
#define ll long long 
map<ll, ll> mp;
map<ll, ll> ::iterator it;
int main()
{
    ll h,q,i,yslef,ysrig,l,r,op,ans,now;
    scanf("%lld%lld",&h,&q);
    yslef=(ll)1<<(h-1);
    ysrig=((ll)1<<h)-1;
    while(q--)
    {
        scanf("%lld%lld%lld%lld",&i,&l,&r,&op);
        if(op)
        {
            yslef=max(yslef,l<<(h-i));
            ysrig=min(ysrig,((r+1)<<(h-i))-1);
        }
        else{
            mp[l<<(h-i)]-=1<<29;
            mp[(r+1)<<(h-i)]+=1<<29;
        }
    }
    if(yslef > ysrig)
    {
        printf("Game cheated!\n");
        return 0;
    }
    mp[yslef]++;
    mp[ysrig+1]--;
    ans = 0;
    it = mp.begin();
    now = it->second;
    if(now>0)
        ans = it->first;
    for(it++;it!=mp.end();it++)
    {
        if(now>0)
        {
            if((it->first)>ans+1)
            {
                ans=-1;
                break;
            }
        }
        now+=it->second;
        if(now>0)
        {
            if(ans)
            {
                ans = -1;
                break;
            }
            else ans = it->first;
        }
    }
    if(ans>0)
        printf("%lld\n",ans);
    else if(ans == 0)
        printf("Game cheated!\n");
    else if(ans == -1)
        printf("Data not sufficient!\n");
    return 0;
}