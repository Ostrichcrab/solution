class Solution {
public:
    vector<int> ans;
     void work(int N, int K,int s,int tmp)
    {
        if(s >= N) 
        {
            ans.push_back(tmp);
            return ;
        }
        int t = tmp%10;
        s++;
        if(t+K<10) work(N,K,s,tmp*10+t+K);
        if(t-K>=0 && K != 0) work(N,K,s,tmp*10+t-K);
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        if(N==1){
            for(int i = 0; i < 10; i++) ans.push_back(i);
        }
        else{
             for(int i = 1; i <= 9; i++){
            work(N,K,1,i);
          }
        }
       
        return ans;
    }
};