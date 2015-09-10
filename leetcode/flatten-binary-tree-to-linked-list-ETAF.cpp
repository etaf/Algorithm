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
    void flatten(TreeNode* root) {
        dfs(root);
    }
    TreeNode* dfs(TreeNode* root){
        if(!root)return NULL;
        TreeNode* le = dfs(root->left);
        TreeNode* re = dfs(root->right);
        if(le){
            le ->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        if(re) return re;
        if(le) return le;
        return root;
    }
};
void test(){
    Solution sol;
    TreeNode* p[10];//array with pointer element
    TreeNode (*q)[10];//pointer for an array
    //cout<<sizeof(p)<<endl<<sizeof(q)<<endl;
    for(int i=1;i<7;++i)
    {
        p[i] = new TreeNode(i);
    }
    p[1]->left = p[2];
    p[1]->right = p[5];
    p[2] ->left = p[3];
    p[2] ->right = p[4];
    p[5]->right = p[6];
    sol.flatten(p[1]);
    TreeNode* u =p[1];
    while(u)
    {
        if(u->left)
            cerr<<"error"<<endl;
        cout<< u->val<<"->";
        u = u->right;
    }

        cout<<"end"<<endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    test();
    return 0;
}


