#include<stdio.h>
#include<string.h>
#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int N = 1e5+99;
int n;
int val[N];
int le[N];
int stack[N];
int main()
{
    int i,res,top,tmp;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&val[i]);
    }
    res = 0;
    top = 0;
    memset(stack,0,sizeof(stack));
    for(int i = 0; i < n; i++)
    {
        while(top > 1 && val[i] > val[stack[top]])
        {
            top--;
        }
        if(top)
        {
            res = max(res,val[i]^val[stack[top]]);
        }
        stack[++top] = i;
    }
    top = 0;
    memset(stack,0,sizeof(stack));
    for(int i = n; i >= 0; i--)
    {
        while(top>=1 && val[i] > val[stack[top]])
        {
            top--;
        }
        if(top)
        {
            res = max(res,val[i]^val[stack[top]]);
        }
        stack[++top] = i;
    }
    printf("%d\n",res);
    return 0;
}