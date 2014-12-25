#include<vector>
using namespace std;
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
        vector<vector<int> > levelOrderBottom(TreeNode *root) {
            vector<vector<int> > ans;
            if(!root)return ans;
            TreeNode* *p = new TreeNode* [10010];
            TreeNode* *q = new TreeNode* [10010];
            int cntp=0,cntq=0;
            p[cntp++] = root;
            while(cntp)
            {
                cntq = 0;
                vector<int> tmp;
                for(int i=0;i<cntp;++i)
                {
                    tmp.push_back(p[i]->val);
                    if(p[i]->left)q[cntq++] = p[i]->left;
                    if(p[i]->right)q[cntq++] = p[i]->right;
                }
                ans.push_back(tmp);
                swap(p,q);
                swap(cntp,cntq);
            }
            vector<vector<int> > nans;
            for(int i=ans.size()-1;i>=0;--i)nans.push_back(ans[i]);
            return nans;
        }
};
