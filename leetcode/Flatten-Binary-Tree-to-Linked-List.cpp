#include<iostream>
#include<cmath>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    void flatten(TreeNode *root) {
        if(root)
            dfs(root);
    }
    TreeNode* dfs(TreeNode* u)
    {
        TreeNode* trail = u;
        TreeNode* original_left = u->left;
        TreeNode* original_right = u->right;
        if(original_left){
           trail = dfs(original_left);
           u->right = original_left;
           u->left = NULL;
        }
        if(original_right){
            trail->right = original_right;
            trail = dfs(original_right);
        }
        return trail;
    }
};
Solution sol;
void test(){
    TreeNode* p[10];//array with pointer element
    TreeNode (*q)[10];//pointer for an array
    cout<<sizeof(p)<<endl<<sizeof(q)<<endl;
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
int main(){
    test();
    return 0;
}
