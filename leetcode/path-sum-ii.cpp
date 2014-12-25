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
public:
    vector<int> path;
    vector<vector<int> > ans;
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        if(!root)return ans;
        path.push_back(root->val);
        dfs(root,sum-root->val);
        return ans;
    }
    void dfs(TreeNode* u,int sum){
        if(!u->left && !u->right){
            if(sum == 0)ans.push_back(path);
            return;
        }
        if(u->left){
            path.push_back(u->left->val);
            dfs(u->left,sum - u->left->val);
            path.pop_back();
        }
        if(u->right){
            path.push_back(u->right->val);
            dfs(u->right,sum - u->right->val);
            path.pop_back();
        }
    }

};
int main()
{

    return 0;
}


