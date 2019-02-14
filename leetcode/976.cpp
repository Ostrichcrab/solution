class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        int ans = 0;
        if(A.size()<3) return ans;
        sort(A.begin(),A.end());
        int n = A.size();
        for(int i = n-3; i>=0; i--){
            if(A[i]+A[i+1]>A[i+2]){
                ans = A[i]+A[i+1]+A[i+2];
                break;
            }
        }
        return ans;
    }
};