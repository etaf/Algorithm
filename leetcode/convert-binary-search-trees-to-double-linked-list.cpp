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

typedef long long llong;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution{
    public:
    TreeNode* convert(TreeNode* root){
        if(!root) return NULL;
        dfs(root);
        while(root->left) root = root->left;
        return root;
    }
    pair<TreeNode*,TreeNode*> dfs(TreeNode* root){
        pair<TreeNode*,TreeNode*> res = make_pair(root,root);
        if(!root) return res;
        if(root->left){
            pair<TreeNode*,TreeNode*> lres = dfs(root->left);
            res.first = lres.first;
            root->left = lres.second;
            lres.second->right = root;
        }
        if(root->right){
            pair<TreeNode*, TreeNode*> rres = dfs(root->right);
            res.second = rres.second;
            rres.first->left = root;
            root->right = rres.first;
        }
        return res;
    }
    void dispaly_list(TreeNode* root){
        TreeNode* head = root;
        if(!head) return;
        cout<<head->val;
        while(head->right){
            head = head->right;
            cout<<"->"<<head->val;
        }
        cout<<endl;
        cout<<"-------------"<<endl;
        cout<<head->val;
        while(head->left){
            head = head->left;
            cout<<"->"<<head->val;
        }
        cout<<endl;
        cout<<"-------------"<<endl;
        head = root;
        while(head){
            if(head->left) cout<<head->left->val;
            else cout<<"NULL";
            cout<<"->"<<head->val<<"->";
            if(head->right) cout<<head->right->val;
            else cout<<"NULL";
            cout<<endl;
            head = head->right;
        }
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    Solution sol;

    TreeNode* ps[100];
    for(int i=0; i<100; ++i)ps[i] = new TreeNode(i);
    ps[50]->left = ps[40];
    ps[50]->right = ps[80];
    ps[40]->left = ps[10];
    ps[40]->right = ps[45];
    ps[45]->left = ps[42];
    ps[45]->right = ps[47];
    ps[80]->left = ps[60];
    ps[60]->left = ps[55];

    TreeNode* root = sol.convert(ps[50]);
    sol.dispaly_list(root);
    return 0;
}


