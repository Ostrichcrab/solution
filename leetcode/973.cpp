class Solution {
public:
    struct node
    {
        int index;
        double dis;
        bool operator < (const node& t)const{
            return dis < t.dis;
        }
    }p[10004];
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        if(points.size()==0) return res;
        int len = points.size();
        for(int i = 0; i < 10004; i++) p[i].dis = 999999;
        for(int i = 0; i < len; i++)
        {
            double dis = sqrt(points[i][0]*points[i][0]+points[i][1]*points[i][1]);
            p[i].index = i;
            p[i].dis = dis;
        }
        sort(p,p+10004);
        for(int i = 0; i < K; i++){
            res.push_back(points[p[i].index]);
        }
        return res;
    }
};