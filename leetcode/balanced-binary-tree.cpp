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
    bool isBalanced(TreeNode *root) {
        if(root)
            return dfs(root);
        else {
            return true;
        }
    }
    bool dfs(TreeNode* u){
        u->val = 0;
        int l=0,r=0;
        if(u->left){
            if(!dfs(u->left))return false;
            l = u->left->val ;
        }
        if(u->right){
            if(!dfs(u->right)) return false;
            r = u->right->val ;
        }
        u->val = max(l,r)+1;
        return abs(l-r) < 2;

    }
};

Solution solution;
void test(){
    TreeNode* root = new TreeNode(0);
    TreeNode* left = new TreeNode(0);
    TreeNode* ll = new TreeNode(0);
    TreeNode* r = new TreeNode(0);
    root->left = left;
    root->right = r;
    left->left = ll;
    cout<<solution.isBalanced(root)<<endl;
}
int main(){
    test();
    return 0;
}
