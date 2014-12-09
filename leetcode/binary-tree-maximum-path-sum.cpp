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
#define INF 0x3fffffff
class Solution {
public:
    int ans;
    int maxPathSum(TreeNode *root) {
        if(!root)return 0;
        ans = -INF;
        int ans1,ans2;
        dfs(root,ans1,ans2);
        return max(ans,ans1);
    }
    void dfs(TreeNode* u, int& ans1,int& ans2)
    {
        ans1 = -INF;
        ans2 = u->val;
        int lans2=0,rans2=0;
        if(u->left)
        {
            int lans1;
            dfs(u->left,lans1,lans2);
            ans1 = max(ans1,max(lans1,lans2));
        }
        if(u->right){
            int rans1;
            dfs(u->right,rans1,rans2);
            ans1 = max(ans1,max(rans1,rans2));
        }
        ans = max(ans,u->val+max(0,lans2)+max(0,rans2));
        ans2 += max(0,max(lans2,rans2));
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
    cout<<sol.maxPathSum(p[1])<<endl;

}
int main(){
    test();
    return 0;
}
