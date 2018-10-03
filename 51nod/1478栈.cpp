// #include<stdio.h>
// #include<stack>
// #include<algorithm>
// #include<string>
// #include<iostream>
// #include<map>
// using namespace std;
// const int N = 1e6+9;
// map<int,int>mp;
// string s;
// int main()
// {
//     stack <char> ss;
//     while(!ss.empty()) ss.pop();
//     cin>>s;
//     int tmp1 = 0;
//     for(int i = 0; i < s.length(); i++){
//         if(ss.empty() && s[i] == ')') continue;
//         else if(s[i] == '('){
//             if(ss.empty()) tmp1 = 0;
//             ss.push('(');
//         }
//         else if(s[i] == ')' && !ss.empty()){
//             ss.pop();
//             tmp1+=2;
//             mp[tmp1]++;
//         }
//     }
//     map<int,int> ::iterator it;
//     if(mp.size()!=0){
//         it = mp.end();
//     it--;
//     cout<<it->first<<" "<<it->second<<endl;
//     }
//     else cout<<"0"<<" "<<"1"<<endl;
//     return 0;
// }
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<stack>
#define LL long long
#define debug(x) cout << "[" << x << "]" << endl
using namespace std;

const int mx = 1e6+10;
char a[mx];
int dp[mx];
stack<int> s;

int main(){
    int ans = 0, num = 1;
    scanf("%s", a+1);
    int len = strlen(a+1);
    for (int i = 1; i <= len; i++){
        if (a[i] == '(') s.push(i);
        else if (!s.empty()){
            int t = s.top(); s.pop();
            dp[i] = dp[t-1]+i-t+1;
            if (ans == dp[i]) num++;
            else if (ans < dp[i]) ans = dp[i], num = 1;
        }
    }
    printf("%d %d\n", ans, num);
    return 0;
}