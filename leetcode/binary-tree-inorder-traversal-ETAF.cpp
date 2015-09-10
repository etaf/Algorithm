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
class Solution_old {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> ans = inorderTraversal(root->left);
        vector<int> ansr = inorderTraversal(root->right);
        ans.push_back(root->val);
        for(auto it=ansr.begin(); it!=ansr.end(); ++it){
            ans.push_back(*it);
        }
        return ans;
    }
};
class Solution{
public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        ans.emplace_back(root->val);
        dfs(root->right);
    }
};
int main()
{
    std::ios::sync_with_stdio(false);

    return 0;
}


