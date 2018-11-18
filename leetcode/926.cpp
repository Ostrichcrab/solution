class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int len = S.length();
        int zoro=0,one=0;
        for(int i = 0; i < len; i++){
            if(S[i]=='0') zoro++;
        }
        int ans = min(9999999,one+zoro);
        for(int i = 0; i <len; i++)
        {
            if(S[i]=='0') zoro--;
            else one++;
            ans=min(ans,zoro+one);
        }
        return ans;
    }
};