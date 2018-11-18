class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> tmp;
        int len = S.length();
        int fu=1,zh=1;
        tmp.push_back(0);
        for(int i = 0; i < len; i++)
        {
            
            if(S[i]=='I'){
                tmp.push_back(zh);
                zh++;
            }else{
                tmp.push_back(0-fu);
                fu++;
            }
            
        }
        
        for(int i = 0; i < len+1; i++){
            tmp[i]=tmp[i]+fu-1; cout<<tmp[i]<<" ";
        }
        
        return tmp;
    }
};