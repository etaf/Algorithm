
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        TreeNode* p[64], *q[64];
        uint32_t pcnt = 0, qcnt = 0;
        p[pcnt++] = root;
        while(pcnt){
            ans.push_back(p[pcnt-1]->val);
            qcnt = 0;
            for(int i=0; i<pcnt; ++i){
                if(p[i]->left)
                    q[qcnt++] = p[i]->left;
                if(p[i]->right)
                    q[qcnt++] = p[i]->right;
            }
            swap(p,q);
            pcnt = qcnt;
        }
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    return 0;
}


