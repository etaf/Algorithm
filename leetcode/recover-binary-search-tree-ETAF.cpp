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
    TreeNode* pre;
    TreeNode* p, *q;
    void recoverTree(TreeNode* root) {
        pre = p = q = NULL;
        dfs(root);
        if(p && q) std::swap(p->val, q->val);
    }
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        if(pre && pre->val > root->val){
            if(p){
                q = root;
            }else{
                p = pre;
                q = root;
            }
        }
        pre = root;
        dfs(root->right);
    }
};
class Solution_bubble {//bubble
public:
    TreeNode* pre;
    bool swapped;
    void recoverTree(TreeNode* root) {
        pre = NULL;
        swapped = true;
        while(swapped){
            swapped = false;
            pre = NULL;
            dfs(root);
        }
    }
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        if(pre && pre->val > root->val){
            swap(pre->val, root->val);
            swapped = true;
        }
        pre=root;
        dfs(root->right);

    }
};
void dfs(TreeNode* u)
{
    if(u->left)dfs(u->left);
    cout<<u->val<<" ";
    if(u->right)dfs(u->right);
}
void test(){

    int n = 6;
    TreeNode * ns[100];
    for(int i=1;i<=n;++i)
    {
        ns[i] = new TreeNode(i);
    }

    ns[3]->left = ns[6];
    ns[6]->left = ns[1];
    ns[3]->right = ns[5];
    ns[5]->left = ns[4];
    ns[5]->right = ns[2];

    Solution sol;

    dfs(ns[3]);
    cout<<endl;
    sol.recoverTree(ns[3]);
    dfs(ns[3]);
    cout<<endl;

}
int main()
{
    std::ios::sync_with_stdio(false);
    test();
    return 0;
}


