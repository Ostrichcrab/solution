class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        long long x[100003];
        x[0]=0;
        long long cnt = 0;
        long long w;
        int m = K;
        for(int i = 1; i <= A.size(); i++)
        {
            w = A[i-1];
            x[i]=((x[i-1]+w)%m+m)%m;
        }
        sort(x,x+A.size()+1);
        long long s = 1;
        for(long long i = 1; i <= A.size(); i++)
        {
            if(x[i]==x[i-1]){
                s++;
            }else{
                cnt += s*(s-1)/2;
                s=1;
            }
        }
        cnt+=s*(s-1)/2;
        return cnt;
    }
};