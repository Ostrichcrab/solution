/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*
 统计以当前节点为根节点，包括以下（其子孙）共有多少个节点，多少个金币，节点-金币个数的差值的绝对值为不平衡量，需要运进去或运出来，
 递归处理，递归的过程中更新答案
 */
class Solution {
public:
	int res = 0;
	pair<int, int> dfs(TreeNode* root) {

		pair<int, int> p;
		p.first = 1;
		p.second = root->val;   
		if (root->left != NULL) {
			pair<int, int> x = dfs(root->left);
			p.first += x.first;
			p.second += x.second;
		}
		if (root->right != NULL) {
			pair<int, int> x = dfs(root->right); 
			p.first += x.first;
			p.second += x.second;
		}
		res += abs(p.first - p.second);
        return p;
	}
	int distributeCoins(TreeNode* root) {
		dfs(root);

		return res;
	}
};