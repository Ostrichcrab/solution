#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+9;
ll n,a,b;
int main()
{
   ios::sync_with_stdio(false);
   //freopen("in.txt","r",stdin);
   int T;
   cin>>T;
   while(T--)
   {
       cin>>n>>a>>b;
       if(a*2<=b){
           cout<<n*a<<endl;
       }else{
           cout<<n/2*b+(n%2)*a<<endl;
       }
   }
   return 0;
}
