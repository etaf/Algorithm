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
class Solution_old {
    public:
        bool isSymmetric(TreeNode *root) {
            if(!root)return true;
            TreeNode* *p = new TreeNode* [10010];
            TreeNode* *q = new TreeNode* [10010];
            int cntp=0,cntq=0;
            if(root->left && root->right)
            {
                p[cntp++] = root->left;
                p[cntp++] = root->right;
            }
            else if(root->left || root->right)return false;

            while(cntp)
            {
                cntq = 0;
                for(int i=0;i<cntp;i+=2)
                {
                    if(p[i]->val != p[i+1]->val)return false;
                    if(p[i]->left && p[i+1]->right)
                    {
                        q[cntq++] = p[i]->left;
                        q[cntq++] = p[i+1]->right;
                    }else if(p[i]->left || p[i+1]->right) return false;

                    if(p[i]->right && p[i+1]->left){
                        q[cntq++] = p[i]->right;
                        q[cntq++] = p[i+1]->left;
                    }else if(p[i]->right || p[i+1]->left) return false;
                }
                swap(p,q);
                swap(cntp,cntq);
            }
            return true;
        }
};
class Solution_recursively {
    public:
        bool isSymmetric(TreeNode *root) {
            if(!root)return true;
            if(root->left && root->right)
                return dfs(root->left,root->right);
            else if(!root->left && !root->right)
                return true;
            else return false;
        }
        bool dfs(TreeNode *l, TreeNode* r){
            if(l->val != r->val) return false;
            bool ans = true;
            if(l->left && r->right)
                ans = ans && dfs(l->left,r->right);
            else if(l->left || r->right)return false;
            if(l->right && r->left)
                ans = ans && dfs(l->right,r->left);
            else if(l->right || r->left) return false;
            return ans;
        }
};
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        if(!root->left && !root->right){
            return true;
        }
        if(root->left && root->right) return dfs(root->left, root->right);
        return false;
    }
    bool dfs(TreeNode* l, TreeNode* r){
        if(l == NULL) return r == NULL;
        if(r == NULL) return l == NULL;
        if(l->val != r->val) return false;
        return dfs(l->left, r->right) && dfs(l->right, r->left);
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
    //p[2] ->left = p[3];
    p[2]->val = 2;
    p[5]->val = 2;
    p[2] ->right = new TreeNode(3);
    p[5]->right = new TreeNode(3);
    Solution sol;
    cout<<(sol.isSymmetric(p[1])? "Yes":"No")<<endl;;
}
int main(){
    test();
    return 0;
}
