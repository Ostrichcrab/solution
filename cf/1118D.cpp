#include<iostream>
#include<algorithm>
using namespace std;
typedef    long long ll;
int n,m;
ll a[(int)2e5+5];
bool check(int day)
{
    ll s=0;
    for(int i=0;i<n;i++)s+=max(a[n-1-i]-(i/day),(ll)0);
    return s>=m;
}
int main()
{
    // freopen("ini","r",stdin);
    cin>>n>>m;
    ll sum=0;
    for(int i=0;i<n;i++){scanf("%lld",&a[i]);sum+=a[i];}
    sort(a,a+n);
    if(sum-m<=0){
        if((sum-m)==0)cout<<n;
        else cout<<-1<<endl;
        return 0;
    }
    int l=0,r=n;
    while(l+1<r){
        // cout<<r<<endl;
        int mid=(l+r)>>1;
        if(check(mid))r=mid;
        else l=mid;//l not ans
    }
    cout<<r<<endl;
    return 0;
}
