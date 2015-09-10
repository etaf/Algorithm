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
    vector<TreeNode*> generateTrees(int n) {
        vector<int> ns;
        return dfs(1,n+1);
    }
    vector<TreeNode*> dfs(int l, int r){
        if(l>=r) return {NULL};
        vector<TreeNode*> ans;
        for(int i=l; i<r; ++i){
            vector<TreeNode*> lans = dfs(l,i);
            vector<TreeNode*> rans = dfs(i+1,r);
            for(int x=0; x<lans.size(); ++x){
                for(int y=0; y<rans.size(); ++y){
                    TreeNode* root = new TreeNode(i);
                    root->left = lans[x];
                    root->right = rans[y];
                    ans.emplace_back(root);
                }
            }
        }
        return ans;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    vector<TreeNode*> ans;
    Solution sol;
    //cout<<sol.generateTrees(4).size()<<endl;
    for(int i=0;i<=5; ++i){
        ans = sol.generateTrees(i);
        cout<<ans.size()<<endl;
    }

    return 0;
}


