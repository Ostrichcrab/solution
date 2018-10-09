/*
遍历每个元素v[i]求出以这个元素为最小值的最大区间,长度len, 更新ans[len] = max(ans[len], v[i]), 
最从尾到头更新ans[i], ans[i] = max(ans[i], ans[i+1])
因为如果宽度为 x 的最大力量为 y，那么宽度比 x 小的最大力量一定大于等于 y,所以最后倒着更新一下ans
*/
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 2e5+90;
int n,st[N],top;
int v[N],l[N],r[N],ans[N];
int main()
{
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) scanf("%d",&v[i]);
    st[top=1]=0;v[0]=0;
    for(int i = 1; i <= n; i++){
        while(top && v[st[top]] >= v[i]) top--;
        l[i] = st[top] + 1; st[++top]=i;
    }
    st[top=1]=n+1; v[n+1]=0;
    for(int i = n; i >=1; i--){
        while(top && v[st[top]]>=v[i]) top--;
        r[i] = st[top] - 1; st[++top] = i;
    }
    for(int i = 1; i <= n; i++){
        int len  = r[i] - l[i] + 1;
        ans[len] = max(ans[len],v[i]);
    }
    for(int i = n; i >= 1; i--) ans[i]=max(ans[i],ans[i+1]);
    for(int i = 1; i <= n; i++) printf("%d",ans[i]);
    return 0;
}