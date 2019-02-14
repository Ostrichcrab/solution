class Solution {
public:
    bool check(string a, string b, string order){
        map <char,int> mp;
        int len = order.length();
        for(int i = 0; i < len; i++){
            mp[order[i]] = i;
        }
        int la = a.length();
        int lb = b.length();
        for(int i = 0; i<la&&i<lb; i++){
            if(mp[a[i]] > mp[b[i]]) return false;
            else if(mp[a[i]] < mp[b[i]]) return true;
        }
        if(la<lb) return true;
        else return false;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        int len = words.size();
        for(int i = 1; i < len; i++){
            if(check(words[i-1],words[i],order)) continue;
            else return false;
        }
        return true;
    }
};