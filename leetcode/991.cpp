class Solution {
public:
    int brokenCalc(int X, int Y) {
        int res = 0;
        while(1)
        {
            if(X>=Y) return res + X - Y;
            if(Y&1){
                res++;
                Y++;
            } else{
                Y>>=1;
                res++;
            }
        }
    }
};