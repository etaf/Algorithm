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
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            while(root){
                if(root->val == p->val || root->val == q->val || 
                        (root->val < p->val && root->val > q->val) || 
                        (root->val > p->val && root->val < q->val)) return root;
                if(p->val < root->val)
                    root = root->left;
                else
                    root = root->right;
            }
            return root;
        }
};
int main()
{
    return 0;
}


