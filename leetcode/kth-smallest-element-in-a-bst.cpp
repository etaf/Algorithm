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
    int ans;
    bool found;
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        found = false;
        dfs(root,k,cnt);
        return ans;
    }
    void dfs(TreeNode* root, int k, int& cnt){
        if(!root || found) return;
        dfs(root->left,k,cnt);
        ++cnt;
        if(cnt == k) { ans = root->val; found = true; return;}
        dfs(root->right,k,cnt);
    }
};
class Solution_old {
    public:
        int ans;
        bool found;
        int kthSmallest(TreeNode* root, int k) {
            found = false;
            dfs(root, 0, k);
            return ans;
        }
        int dfs(TreeNode* p, int cnt, int k){
            if(!p || found) return 0;
            int lc =  dfs(p->left, cnt, k);
            if(found) return 0;
            cnt += lc + 1;
            if(cnt == k){
                ans = p->val;
                found = true;
                return 0;
            }
            int rc = dfs(p->right, cnt, k);
            return lc + rc + 1;
        }
};
int main()
{
    Solution sol;
    TreeNode* root = new TreeNode(2);
    TreeNode* l = new TreeNode(1);
    root->left = l;
    cout<<sol.kthSmallest(root,1);
    return 0;
}


