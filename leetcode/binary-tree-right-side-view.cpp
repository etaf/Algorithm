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
        //level traverse
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> ans;
        if(!root) return ans;
        TreeNode* p[64];
        TreeNode* q[64];
        int cntp=0,cntq=0;
        p[cntp++] = root;
        while(cntp>0){
            ans.emplace_back(p[cntp-1]->val);
            cntq = 0;
            for(int i=0;i<cntp;++i){
                if(p[i]->left) q[cntq++] = p[i]->left;
                if(p[i]->right) q[cntq++] = p[i]->right;
            }
            swap(p,q);
            cntp = cntq;
        }
        return ans;
    }

};
int main()
{
    Solution sol;
    return 0;
}


