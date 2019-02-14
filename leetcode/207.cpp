class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses,0);
        for(int i = 0; i < prerequisites.size(); i++){
            indegree[prerequisites[i].first]++;
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        queue<int> q;
        vector<bool> vis(numCourses, false);
        for(int i = 0; i < numCourses; i++)
            if(indegree[i]==0)
                q.push(i);
        while(!q.empty())
        {
            int sta = q.front();
            q.pop();
            vis[sta] = true;
            for(int i = 0; i < graph[sta].size(); i++){
                indegree[graph[sta][i]]--;
                if(indegree[graph[sta][i]] == 0)
                    q.push(graph[sta][i]);
            }
        }
        for(int i = 0; i < numCourses; i++)
            if(vis[i] == false)
                return false;
        return true;
    }
};