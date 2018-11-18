class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0,j=0;
        int len1=name.length(),len2=typed.length();
        if(len1>len2) return false;
        while(i<len1||j<len2)
        { 
            if(name[i]==typed[j]){
                i++,j++;
            }
            else if(name[i-1]==typed[j])
            {
                j++;
            }
            else 
            {
                return false;
            }
        }
        return true;
    }
};