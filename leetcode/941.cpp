class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int len = A.size();
        int maxx = -9999999; int count = 0;
        int pos = -1;
        if(len<3) return false;
        else{
            
            for(int i = 0; i < len; i++){ 
                
                if(A[i]>maxx){
                    maxx = A[i]; count = 1; pos = i;
                }else if(A[i]==maxx){
                    count++;
                }
                
            }
            if(count==1){
                if(pos>0 && pos<len-1 ) {
                    
                    for(int i = pos; i>0; i--){
                        if(A[i]<=A[i-1]) return false;
                    }
                    for(int i = pos; i <len-1; i++){
                        if(A[i+1]>=A[i]) return false;
                    }
                    return true;
                }
            }
            return false;
        }
    }
};