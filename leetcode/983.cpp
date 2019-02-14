class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int dp[n+1];
        memset(dp,0x3f3f3f3f,sizeof(dp));
        dp[0]=0;
        //  for(int i = 0; i < n; i++) dp[i]=999999999;
        // for(int i = 0; i < n; i++) cout<<dp[i]<<endl;
        for(int i = 1; i <= n; i++){
            dp[i]=dp[i-1]+costs[0];
            for(int j = i-1; j>=0; j--){
                if(days[i-1]-days[j]+1<=7){
                    dp[i] = min(dp[i],dp[j]+costs[1]);
                }
                if(days[i-1]-days[j]+1<=30){
                    dp[i] = min(dp[i],dp[j]+costs[2]);
                }
            }
        }
        return dp[n];
    }
};