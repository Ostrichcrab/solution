class Solution {
public:
    int countTriplets(vector<int>& A) {
        int n = A.size();
        vector<int> f(1<<16,-1);
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int x = (A[i]&A[j]);
                if(f[x]==-1){
                    f[x]=0;
                    for(int k = 0; k < n; k++){
                        if((x&A[k])==0) f[x]++;
                    }
                }
                ans+=f[x];
            }
        }
        return ans;
    }
};