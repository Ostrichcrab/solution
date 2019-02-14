class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> B;
        while(K)
        {
            int t = K % 10;
            B.push_back(t);
            K /= 10;
        }
        reverse(A.begin(),A.end());
        int maxx = max(A.size(),B.size());
        vector<int> res(maxx+1,0);
        for(int i = 0; i < res.size(); i++)
        {
            int t = res[i];
            if( i < A.size()){
              t += A[i];  
            }
            if( i < B.size()){
              t += B[i];  
            }
            
            if(t >= 10)
            {
                t -= 10;
                res[i+1] = 1;
            }
            res[i] = t;
        }
        while(res[res.size()-1]==0 && res.size()!=1) res.pop_back();
        reverse(res.begin(),res.end());
        return res;
    }
};