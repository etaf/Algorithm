#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if(!root)return true;
        int maxn,minn;
        return dfs(root,minn,maxn);
    }
    bool dfs(TreeNode* u,int& minn,int& maxn){
        bool ans = true;
        int lmax,lmin,rmax,rmin;
        if(u->left)
        {
            ans = ans && dfs(u->left,lmin,lmax);
            if(u->val <= lmax) return false;
        }
        else {
            lmin = lmax = u->val;
        }
        if(u->right)
        {
            ans = ans && dfs(u->right,rmin,rmax);
            if(u->val >= rmin) return false;
        }
        else{
            rmin = rmax = u->val;
        }
		maxn = max(lmax,rmax);
		minn = min(lmin,rmin);
        return ans;
    }
};
void test(){
    Solution sol;
    int n;
    TreeNode* p[1024];
    p[0] = new TreeNode(10);
    p[1] = new TreeNode(5);
    p[2] = new TreeNode(15);
    p[3] = new TreeNode(6);
    p[4] = new TreeNode(20);
    p[0]->left = p[1];
    p[0]->right =p[2];
    p[2]->left = p[3];
    p[2]->right = p[4];
    cout<<(sol.isValidBST(p[0])?"YES":"NO")<<endl;;

}
int main(){
    test();
    return 0;
}
