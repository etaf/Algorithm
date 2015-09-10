#include<iostream>
#include<cmath>
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

        TreeNode *sortedArrayToBST(vector<int> &num) {
            int l=0,r=num.size();
            return dfs(l,r,num);
        }


        TreeNode* dfs(int l,int r,vector<int> & num){
            if(r-l<1)return NULL;

            int mid = (l+r)>>1;

            TreeNode*  root = new TreeNode(num[mid]);

            root ->left = dfs(l,mid,num);
            root ->right = dfs(mid+1,r,num);
            return root;
        }

};


class Solution1 {
    public:
        vector<int> ans;
        vector<int> inorderTraversal(TreeNode *root) {
            ans.clear();
            if(root)dfs(root); 
            return ans;
        }
        void dfs(TreeNode* u)
        {
            if(u->left)
            {
                dfs(u->left);
            }
            ans.push_back(u->val);
            if(u->right)
            {
                dfs(u->right);
            }
        }
};

class Solution2 {
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

Solution sol;
void test(){
    int n = 10;
    vector<int> p;
    for(int i=0;i<n;++i)
    {
        p.push_back(i);
    }

    TreeNode* ans = sol.sortedArrayToBST(p);
    Solution1 sol1;
    vector<int> path = sol1.inorderTraversal(ans);
    for(int i=0;i<path.size();++i)cout<<path[i]<<"->";
    cout<<"end"<<endl;
    Solution2 sol2;
    cout<< (sol2.isBalanced(ans)?"YES":"NO")<<endl;
}
int main(){
    test();
    return 0;
}
