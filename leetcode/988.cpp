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
    string ans;
    void dfs(TreeNode* root, string& str)
    {
        str.push_back('a'+root->val);
        if(root->left==NULL && root->right==NULL)
        {
            string t = str;
            reverse(t.begin(),t.end());
            ans = min(ans,t);
        }
        if(root->left){dfs(root->left,str);}
        if(root->right){dfs(root->right,str);}
        str.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        ans.push_back('a'+27);
        string cur = "";
        dfs(root,cur);
        return ans;
    }
};