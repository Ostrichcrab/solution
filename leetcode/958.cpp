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
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL) return true;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while(!q.empty()){
            TreeNode* tmp = q.front();
            if(tmp != NULL)
            {
                if(flag) return false;
                q.push(tmp->left);
                q.push(tmp->right);
            }
            else flag = true;
            q.pop();
        }
        return true;
    }
};