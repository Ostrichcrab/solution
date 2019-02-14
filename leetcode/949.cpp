class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        string ans = "";
        int a = -1, b = -1;
        for(int i = 0; i < 24; i++)
        {
            for(int j = 0; j < 60; j++)
            {
                if(check(i,j,A)) {a=i;b=j;}
            }
        }
       // cout<<a<<endl<<b<<endl;
        if(a==-1&&b==-1) return ans;
        else{
            int aa = a/10; int aaa = a%10;
            int bb = b/10; int bbb = b%10;
            ans = ans + to_string(aa) +to_string(aaa) +":" +to_string(bb) + to_string(bbb);
        }
        return ans;
    }
    public:
    bool check(int i, int j, vector<int>& A)
    {
        int aa = i/10; int aaa = i%10;
        int bb = j/10; int bbb = j%10;
        vector<int> B;
        for(int k = 0; k < 4; k++) B.push_back(A[k]);
     
        
        for(int k = 0; k < 4; k++) if(aa==B[k]) {
            B[k]=999;break;
        }
       
        for(int k = 0; k < 4; k++) if(aaa==B[k]){
            B[k]=999;break;
        }
        
        for(int k = 0; k < 4; k++) if(bb==B[k]) {
            B[k]=999;break;
        }
        
        for(int k = 0; k < 4; k++) if(bbb==B[k]){
            B[k]=999;break;
        }
        
      
        for(int k = 0; k < 4; k++) if(B[k]!=999) return false;
        return true;
    }
};