class Solution {
public:
    bool canReorderDoubled(vector<int>& a) {
       // if(a.size()==0) return true;
        if(a.size() % 2) return false;
        multiset<int> pos, neg;
        for(int x: a){
            if(x < 0) neg.insert(-x);
            else pos.insert(x);
        }
        if(pos.size() % 2) return false;
        if(neg.size() % 2) return false;
        while(!pos.empty()){
            int x = *pos.begin();
            pos.erase(pos.begin());
            auto it = pos.lower_bound(x * 2);
            if(it == pos.end() || *it != x * 2) return false;
            pos.erase(it);
        }
        while(!neg.empty()){
            int x = *neg.begin();
            neg.erase(neg.begin());
            auto it = neg.lower_bound(x * 2);
            if(it == neg.end() || *it != x * 2) return false;
            neg.erase(it);
        }
        return true;
    }
};