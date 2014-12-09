#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<algorithm>
class Solution {
    public:
         vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
            vector<vector<int> > ans;
            if(!root)return ans;
            TreeNode* *p = new TreeNode* [10010];
            TreeNode* *q = new TreeNode* [10010];
            int cntp=0,cntq=0;
            p[cntp++] = root;
            int f = 0;
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
                if(f) std::reverse(tmp.begin(),tmp.end());
                f^=1;
                ans.push_back(tmp);
                swap(p,q);
                swap(cntp,cntq);
            }
            return ans;
        }
};
void test(){
    TreeNode* p[10];//array with pointer element
    for(int i=1;i<7;++i)
    {
        p[i] = new TreeNode(i);
    }
    p[1]->left = p[2];
    p[1]->right = p[5];
    p[2] ->left = p[3];
    p[2] ->right = p[4];
    p[5]->right = p[6];
    Solution sol;
    vector< vector<int> > ans = sol.zigzagLevelOrder(p[1]);
    for(int i=0;i<ans.size();++i)
    {
        for(int j=0;j<ans[i].size();++j){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
}
int main(){
    test();
    return 0;
}
