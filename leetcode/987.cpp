/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        map<int,vector<int>> m;
        queue<pair<int,TreeNode*>> q;
        q.push({0,root});
        while(!q.empty())
        {
            auto a = q.front();
            q.pop();
            m[a.first].push_back(a.second->val);
            if(a.second->left){q.push({a.first-1,a.second->left});}
            if(a.second->right){q.push({a.first+1,a.second->right});}
        }
        for(auto it : m)
        {
            res.push_back(it.second);
        }
        return res;
    }
};
///////////////////////////////////////
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* rt, int x, int y, map<pair<int, int>,vector<int> >& nodes)
    {
        nodes[make_pair(x,y)].push_back(rt->val);
        if(rt->left)
        {
            dfs(rt->left,x-1,y+1,nodes);
        }
        if(rt->right)
        {
            dfs(rt->right,x+1,y+1,nodes);
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<pair<int,int>,vector<int>> nodes;
        dfs(root,0,0,nodes);
        vector<vector<int>> ans;
        int last_x = -100000;
        for(auto pr : nodes)
        {
            int x = pr.first.first;
            vector<int> tmp(pr.second);
            sort(tmp.begin(),tmp.end());
            if(x != last_x)
            {
                ans.push_back(tmp);
            }
            else
            {
                for(int j = 0; j < tmp.size(); j++)
                {
                    ans[ans.size()-1].push_back(tmp[j]);
                }
            }
            last_x = x;
        }
        return ans;
    }
};