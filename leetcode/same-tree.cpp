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


class Solution {
    public:
         bool isSameTree(TreeNode *p, TreeNode *q) {
             if(p && q)
                return dfs(p,q);
             else if(p || q) return false;
             else return true;
        }
         bool dfs(TreeNode* p,TreeNode* q)
         {
             if(p->val != q->val) return false;
             bool ans = true;
             if(p->left && q->left)
                 ans = ans && dfs(p->left, q->left);
             else if(p->left || q->left) return false;

             if(p->right && q->right)
                 ans = ans && dfs(p->right ,q->right);
             else if(p->right || q->right)return false;

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
    //p[2] ->left = p[3];
    //p[2]->val = 2;
    //p[5]->val = 2;
    //p[2] ->left = new TreeNode(3);
    //p[5]->right = new TreeNode(3);
    Solution sol;
    cout<<(sol.isSameTree(p[2],p[5])? "Yes":"No")<<endl;;
}
int main(){
    test();
    return 0;
}
