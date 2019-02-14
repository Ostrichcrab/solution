class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string s = "";
        if(A>B) {s+="aab";A-=2;B--;}
        else if(A<B){s+="bba";B-=2;A--;}
        while(A||B)
        {
            if(A==0){
                for(int i = 0; i < B; i++) s+="b"; break;
            }
            if(B==0){
                for(int i = 0; i < A; i++) s+="a"; break;
            }
            if(A>B){
                if(s[s.length()-1]=='a'){s+="baa";A=A-2;B--;}
                else{s+="aab";A=A-2;B--;}
            }
            else if(A<B){
                if(s[s.length()-1]=='a'){s+="bba";B=B-2;A--;}
                else{s+="abb";B=B-2;A--;}
            }
            else if(A=B){
                if(s[s.length()-1]=='a'){s+="ba";B--;A--;}
                else{s+="ab";B--;A--;}
            }
        }
        return s;
    }
};