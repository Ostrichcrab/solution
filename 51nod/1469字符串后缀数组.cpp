/*强烈建议画出后缀数组观察看看
首先排出后缀数组的height数组，从下往上扫描，设定一个变量pre，表示“上一次的height的值”。

根据3，可以得出height为0的肯定不能要。

根据5，可以得出，能要的部分的height值一定是部分最长的。

根据4，说明在部分最长的当中要检查其前一个字母。

举个例子说明更好，假设有字符串aaabcaaa

后缀数组拍出来:

a                    1

aa                  1

aaa                2

aaabcaaa      3

aabcaaa        2

abcaaa          1

bcaaa            0

caaa              0

右边是height值，扫描到"abcaaa"height值为1

但是这个时候a是不是淋漓尽致子串还不知道，如果说后面还有公共部分，就这样冒然加进去了，会违反定义5.

于是向上扫描，直到扫描到height值下降的时候，那个height值得最高峰的地方，一定满足定义5.

但是满不满足定义4不知道，所以需要一个map来记录，最高值期间，这些子串的前一个字符出现的次数。



所以算法就是：扫描height数组，每一次height数组上升后的第一次下降即是潜在答案，检验map，如果没有出现一次以上的字符，那么ans++;*/
#include<map>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define LL long long int
using namespace std;
const int nMax = 120001;
 
 
char arr[nMax+1];
int sa[nMax], rk[nMax], height[nMax];//sa排第i的是后缀几
int wa[nMax], wb[nMax], wv[nMax], wd[nMax];
int n,k;
 
char str[nMax];
char C;
 
int cmp(int *r, int a, int b, int l){
    return r[a] == r[b] && r[a+l] == r[b+l];
}
 
void da(char *r, int n, int m){          //  倍增算法 r为待匹配数组  n为总长度 m为字符范围
    int i, j, p, *x = wa, *y = wb, *t;
    for(i = 0; i < m; i ++) wd[i] = 0;
    for(i = 0; i < n; i ++) wd[x[i]=r[i]] ++;
    for(i = 1; i < m; i ++) wd[i] += wd[i-1];
    for(i = n-1; i >= 0; i --) sa[-- wd[x[i]]] = i;
    for(j = 1, p = 1; p < n; j *= 2, m = p){
        for(p = 0, i = n-j; i < n; i ++) y[p ++] = i;
        for(i = 0; i < n; i ++) if(sa[i] >= j) y[p ++] = sa[i] - j;
        for(i = 0; i < n; i ++) wv[i] = x[y[i]];
        for(i = 0; i < m; i ++) wd[i] = 0;
        for(i = 0; i < n; i ++) wd[wv[i]] ++;
        for(i = 1; i < m; i ++) wd[i] += wd[i-1];
        for(i = n-1; i >= 0; i --) sa[-- wd[wv[i]]] = y[i];
        for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i ++){
            x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p - 1: p ++;
        }
    }
}
 
void calHeight(char *r, int n){           //  求height数组。
    int i, j, k = 0;
    for(i = 1; i <= n; i ++)    rk[sa[i]] = i;
    for(i = 0; i < n; height[rk[i ++]] = k){
        for(k ? k -- : 0, j = sa[rk[i]-1]; r[i+k] == r[j+k]; k ++);
    }
}
map<char, int> mp;
int work(int len)
{
    mp.clear();
    int pre = 0;
    int ans = 0;
    int cnt = 0;
    bool up = false;
    for(int i = len; i >= 1; i--)
    {
        if(height[i] > pre)
        {
            up = true;
            mp.clear();
            pre = height[i];
            if(sa[i]-1 >=0)mp[arr[sa[i]-1]]++;
            if(sa[i-1]-1>=0)mp[arr[sa[i-1]-1]]++;
        }else if(height[i]==pre)
        {
            pre = height[i];
            if(sa[i-1]-1>=0) mp[arr[sa[i-1]-1]]++;
        }
        else if(height[i]<pre)
        {
            pre = height[i];
            if(up==true)
            {
                map<char,int>::iterator iter;
                bool can = true;
                for(iter=mp.begin();iter!=mp.end();iter++)
                {
                    if(iter->second > 1)
                    {
                        can = false;
                        break;
                    }
                }
                if(can == true)
                {
                    ans++;
                }
                up = false;
                mp.clear();
            }
        }
    }
    return ans;
}
int main()
{
    while(scanf("%s",arr)!=EOF)
    {
        int len = strlen(arr);
        arr[len+1] = 0;
        da(arr,len+1,130);
        calHeight(arr,len);
        int ans = work(len);
        cout<<ans<<endl;
    }
}