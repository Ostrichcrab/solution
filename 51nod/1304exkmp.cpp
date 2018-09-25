#include<stdio.h>
#include<string.h>
using namespace std;
#define ll long long
const int N = 1e6+9;
int nxt[N];
char s[N];
void getnxt()
{
    int po,i=0,j,len = strlen(s);
    nxt[0]=len;
    while(s[i]==s[i+1]&&i+1<len) i++;
    nxt[1]=i;
    po=1;
    for(i = 2; i<len; i++)
    {
        if(nxt[i-po]+i<nxt[po]+po)
            nxt[i]=nxt[i-po];
        else{
            j=nxt[po]+po-i;
            if(j<0) j=0;
            while(i+j<len&&s[j]==s[i+j])
            j++;
            nxt[i]=j;
            po=i;
        }
    }
}
int main()
{
    scanf("%s",s);
    getnxt();
    ll ans = 0;
    int len = strlen(s);
    for(int i = 0; i<len; i++)
        ans+=nxt[i];
    printf("%lld\n",ans);
    return 0;
}