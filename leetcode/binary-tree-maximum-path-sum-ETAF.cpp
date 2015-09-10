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
    long long ans;
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        dfs(root);
        return ans;
    }
    long long dfs(TreeNode* root){
        if(!root) return INT_MIN;
        long long la = dfs(root->left);
        long long ra = dfs(root->right);
        long long tmp = root->val +  max(0LL, max(la,ra)) ;
        ans = max(ans, max(tmp, root->val + la + ra));
        return tmp;
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

    p[9] = new TreeNode(-2);
    p[8] = new TreeNode(1);
    p[9]->left = p[8];
    cout<<sol.maxPathSum(p[9])<<endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    test();
    return 0;
}


