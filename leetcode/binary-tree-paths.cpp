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
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<cstdlib>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
    private:
        vector<int> path;
        vector<string> ans;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL) return ans;
        path.clear();
        path.push_back(root->val);
        dfs(root);
        return ans;
    }
    void dfs(TreeNode* root){
        if(root->left == NULL && root->right == NULL){
            string s = to_string(path[0]);
            for(int i=1; i<path.size(); ++i){
                s.append("->");
                s.append(to_string(path[i]));
            }
            ans.push_back(s);
            return;
        }
        if(root->left){
            path.push_back(root->left->val);
            dfs(root->left);
            path.pop_back();
        }
        if(root->right){
            path.push_back(root->right->val);
            dfs(root->right);
            path.pop_back();
        }
    }
};
int main()
{
    Solution sol;
    TreeNode* root = new TreeNode(11);
    root->left = new TreeNode(12);
    root->right = new TreeNode(13);
    root->left ->right = new TreeNode(15);
    vector<string> ans = sol.binaryTreePaths(root);
    for(int i=0; i<ans.size(); ++i){
        cout<<ans[i]<<endl;
    }
    return 0;
}


