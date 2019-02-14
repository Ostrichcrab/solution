class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses,0);
        for(int i = 0; i < prerequisites.size(); i++){
            indegree[prerequisites[i].first]++;
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++)
            if(indegree[i]==0)
                q.push(i);
        vector<int> ans;
        while(!q.empty())
        {
            int sta = q.front();
            q.pop();
            ans.push_back(sta);
            for(int i = 0; i < graph[sta].size(); i++){
                indegree[graph[sta][i]]--;
                if(indegree[graph[sta][i]] == 0)
                    q.push(graph[sta][i]);
            }
        }
        if(ans.size()==numCourses) return ans;
        vector<int> t;
        return t;
    }
};