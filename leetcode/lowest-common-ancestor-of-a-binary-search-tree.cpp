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
            if( root->val > max(p->val, q->val) ) root = root->left;
            else if( root->val < min(p->val, q->val)) root = root->right;
            else return root;
        }
        return root;
    }
};
class Solution_old {
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
    Solution sol;
    TreeNode* p[10];
    for(int i=0; i<10; ++i) p[i] = new TreeNode(i);
    p[5]->left = p[3];
    p[5]->right= p[6];
    p[3]->left = p[2];
    p[3]->right = p[4];
    p[2]->left = p[1];
    TreeNode* res = sol.lowestCommonAncestor(p[5],p[1],p[4]);
    cout<<res->val<<endl;
    return 0;
}


