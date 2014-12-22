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
    int sumNumbers(TreeNode *root) {
        if(!root)return 0;
        dfs(root,0);
    }
    int dfs(TreeNode* now,int sum)
    {
        sum = sum*10 + now->val;
        int res = 0;
        if(now->left) res +=dfs( now->left,sum);
        if(now->right) res+=dfs(now->right,sum);
        if(!now->left && !now->right) return sum;
        return res;
    }
};
int main()
{
	return 0;
}


