class TimeMap {
public:
    /** Initialize your data structure here. */
    map<string, map<int,string>> m;
    TimeMap() {
        m.clear();
    }
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        if(m[key].size()==0) return "";
        auto it = m[key].upper_bound(timestamp);
        if(it==m[key].begin()) return "";
        it--;
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */