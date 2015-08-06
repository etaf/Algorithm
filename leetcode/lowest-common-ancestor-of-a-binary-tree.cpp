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
        if(root == p || root == q || root == NULL) return root;
        TreeNode *l = lowestCommonAncestor(root->left, p, q),
                 *r = lowestCommonAncestor(root->right, p, q);
        return l && r ? root : l ? l : r;
    }
};
int main()
{
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    n1.left = &n2;
    n1.right = &n3;
    Solution sol;
    TreeNode* ans = sol.lowestCommonAncestor(&n1, &n2, &n3);
    cout<<ans->val<<endl;
    return 0;
}


