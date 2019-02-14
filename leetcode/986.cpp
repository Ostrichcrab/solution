/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool cmp(Interval a, Interval b)
    {
        return a.start < b.start;
    }
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        sort(A.begin(),A.end(),cmp);
        sort(B.begin(),B.end(),cmp);
        int i = 0, j = 0;
        vector<Interval> res;
        while(i < A.size() && j < B.size())
        {
            int le = max(A[i].start,B[j].start);
            int ri = min(A[i].end,B[j].end);
            if(le <= ri) {res.emplace_back(le,ri);}
            if(A[i].end < B[j].end) i++;
            else j++;
        }
        return res;
    }
};