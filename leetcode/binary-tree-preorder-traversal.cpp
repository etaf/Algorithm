/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<int> ans;
    vector<int> preorderTraversal(TreeNode *root) {
       ans.clear();
	   if(root)dfs(root);
	   return ans;
    }
	void dfs(TreeNode* u){
		ans.push_back(u->val);
		if(u->left)dfs(u->left);
		if(u->right)dfs(u->right);
	}
};