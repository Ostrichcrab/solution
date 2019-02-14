class Solution {
public:
    void find(vector<int> &last, const vector<int> &A, int K){
        int n = A.size();
        int j = 0, cur = 0;
        vector<int> vis(n+1,0);
        for(int i = 0; i < n; i++){
            if(vis[A[i]] == 0)
                cur++;
            vis[A[i]]++;
            while(cur == K+1){
                if(vis[A[j]] == 1)
                    cur--;
                vis[A[j]]--;
                j++;
            }
            last[i] = j;
        }
    }
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int n = A.size();
        vector<int> left(n,0),right(n,0);
        find(right,A,K-1);
        find(left,A,K);
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans += right[i] - left[i];
        return ans;
    }
};