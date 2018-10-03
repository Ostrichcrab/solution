#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<set>
using namespace std;
#define ll long long
const int N = 2e5+100;
int n,m;
struct seg {
    ll le,ri;
}bdg[N];
bool cmp(seg s1, seg s2)
{
    if(s1.ri != s2.ri)
        return s1.ri < s2.ri;
    else 
        return s1.le < s1.le;
}
multiset <ll> st;
multiset <ll> :: iterator it;
bool flag;
int main()
{
    scanf("%d%d",&n,&m);
    ll prel,prer,l,r;
    scanf("%lld%lld",&prel,&prer);
    for(int i = 0; i < n-1; i++){
        scanf("%lld%lld",&l,&r);
        bdg[i].le = l - prer;
        bdg[i].ri = r - prel;
        prel = l, prer = r;
    } 
    n--;
    sort(bdg,bdg+n,cmp);
    ll t;
    for(int i = 0; i < m; i++)
    {
        scanf("%lld",&t);
        st.insert(t);
    }
    flag = true;
    for(int i = 0; i < n; i++)
    {
        it = st.lower_bound(bdg[i].le);
        if(it == st.end()||((*it)>bdg[i].ri)){
            flag = false;
            break;
        }
        st.erase(it);
    }
    if(flag) puts("YES");
    else puts("NO");
    return 0;
}