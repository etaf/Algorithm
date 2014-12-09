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
	int ans;
    int minDepth(TreeNode *root) {
		if(!root)return 0;
		ans = 0x3fffffff;
		dfs(root,1);
		return ans;
    }
	void dfs(TreeNode* u,int step){
		if(!(u->left) && !(u->right)) ans = min(ans,step);
		if(u->left) dfs(u->left,step+1);
		if(u->right) dfs(u->right, step+1);
	}
};