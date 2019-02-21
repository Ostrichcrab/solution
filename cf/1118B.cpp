
 #include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+9;
ll a[N];
ll odd[N],even[N];
int main()
{
   ios::sync_with_stdio(false);
   //freopen("in.txt","r",stdin);
   int n;
   cin>>n;
   ll sum_odd=0,sum_even=0;
   for(int i = 1; i <= n; i++)
   {
       cin>>a[i];
       if(i&1){//jishu
        sum_odd += a[i];
            odd[i]=sum_odd;
            even[i]=even[i-1];
       }else{
           sum_even +=a[i];
           even[i]=sum_even;
           odd[i]=odd[i-1];
       }
   }
   ll ans = 0;
   ll t_odd=0,t_even=0;
   for(int i = 1; i <= n; i++)
   {
       t_odd=odd[i-1]+even[n]-even[i];
       t_even=even[i-1]+odd[n]-odd[i];
       if(t_odd==t_even) ans++;
   }
   cout<<ans<<endl;
   return 0;
}
