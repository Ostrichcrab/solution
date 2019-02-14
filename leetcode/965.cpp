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
    bool isUnivalTree(TreeNode* root) {
        if(root==NULL) return true;
        int vall = root->val;
        if(root->left==NULL&&root->right==NULL) return true;
        if(root->left){
            if(root->left->val != vall) return false;
            bool le = isUnivalTree(root->left);
            if(!le) return false;
        }
        if(root->right){
            if(root->right->val !=vall) return false;
            bool ri = isUnivalTree(root->right);
            if(!ri) return false;
        }
         return true;
       
    }
};