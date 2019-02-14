class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        vector<int> dp(A.size());
        int ans = 2;
        if(A.size()==1) return 1;
        dp[0]=1;
        if(A[1]!=A[0]) dp[1]=2;
        else dp[1]=1;
        for(int i = 2; i<A.size(); i++)
        {
            if(A[i-2]>A[i-1]&&A[i-1]<A[i] || A[i-2]<A[i-1]&&A[i-1]>A[i]) {
                dp[i]=dp[i-1]+1;
                ans=max(dp[i],ans);
            }
            else{
                if(dp[i-1]==dp[i]) dp[i]=1;
                else dp[i]=2;
            }
        }
        return ans;
    }
};