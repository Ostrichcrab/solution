class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int len = A.size(); int llen = A[0].length();
        int ans = 0;
      cout<<len<<endl<<llen<<endl;
            for(int j = 0; j < llen; j++){
                for(int i = 0; i < len-1; i++){ 
                
                 if(A[i][j]>A[i+1][j])  {
                    ans++;
                     cout<<i<<" "<<j<<endl;
                     break;   
                 }
                
            }    
        }
        
        return ans;
    }
};