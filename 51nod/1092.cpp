#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1008;
int dp[N][N];
char s[N];
const int inf = 0x3f3f3f3f;
int main()
{
	scanf("%s",s);
	int len = strlen(s);
	for(int i = 0; i<len; i++){
		for(int j = 0; j<len;j++){
			if(i==j||i>j) 
				dp[i][j]=0;
			else 
				dp[i][j]=inf;
		}
	}
	//枚举长度和起点，计算得出终点 
	for(int l = 1; l<=len-1;l++){ //length
		for(int i = 0; (i+l)<len; i++){ //起点 
			int j = i + l; //终点=起点+长度 
			if(s[i]==s[j]) dp[i][j]=min(dp[i+1][j-1],dp[i][j]);
			else dp[i][j]=min(dp[i+1][j-1]+2,dp[i][j]);
			dp[i][j]=min(dp[i][j],dp[i+1][j]+1);
			dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
		}
	}
	printf("%d\n",dp[0][len-1]);
	return 0;
}
