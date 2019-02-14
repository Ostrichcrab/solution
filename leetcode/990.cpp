class Solution {
public:
    vector<int> f,sz;
    int find(int x){
        return x == f[x] ? x : f[x] = find(f[x]);
    }
    void uni(int x, int y){
        int fx = find(x), fy = find(y);
        if(fx == fy) return ;
        if(sz[fx] < sz[fy]){
            f[fx] = fy;
            sz[fy] += sz[fx];
        }else{
            f[fy] = fx;
            sz[fx] += sz[fy];
        }
    }
    bool equationsPossible(vector<string>& equations) {
        f.resize(26);
        sz.resize(26);
        for(int i = 0; i < 26; i++){
            f[i] = i;
            sz[i] = 1;
        }
        for(auto &s : equations){
            if(s[1] == '='){
                int x = s[0] - 'a', y = s[3] - 'a';
                uni(x,y);
            }
        }
        for(auto &s : equations){
            if(s[1] == '!'){
                int x = s[0] - 'a', y = s[3] - 'a';
                int fx = find(x), fy = find(y);
                if(fx == fy) return false;
            }
        }
        return true;
    }
};