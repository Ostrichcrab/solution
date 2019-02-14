class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int n = A.size();
        vector<int> flag(n,0);
        for(int i = 0; i < n; i++) if(A[i]&1) flag[i] = 1;
        int sum = 0;
        for(int i = 0; i < n; i++) if(!flag[i]) sum+=A[i];
        int add,pos; 
        vector<int> res;
        for(int i = 0; i < queries.size(); i++)
        {
            add = queries[i][0];
            pos = queries[i][1];
            int t = A[pos];
            int tt = A[pos]+add;
            A[pos]+=add;
            if(t&1 && tt&1){sum+=0; res.push_back(sum);continue;}
            if(!(t&1) && !(tt&1)){sum+=add; res.push_back(sum); continue;}
            if(!(t&1) && (tt&1)){sum-=t; res.push_back(sum); continue;}
            if((t&1) && !(tt&1)){sum+=tt; res.push_back(sum); continue;}
        }
        return res;
    }
};