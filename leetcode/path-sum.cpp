#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<limits.h>
using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(!root)return false;
        return dfs(root,sum);
    }
    bool dfs(TreeNode *root, int sum){
        if(!root->left && !root->right) return sum == root->val;
        bool ans = false;
        if(root->left)ans = ans || dfs(root->left,sum-root->val);
        if(root->right) ans = ans || dfs(root->right,sum- root->val);
        return ans;
    }
};
void test(){
    
}
int main()
{
	return 0;
}


