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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > ans;
		if(!root)return ans;
		TreeNode* *p = new TreeNode* [10010];
		TreeNode* *q = new TreeNode* [10010];
		int cntp=0,cntq=0;
		p[cntp++] = root;
		while(cntp)
		{
			cntq = 0;
			vector<int> tmp(cntp);
			for(int i=0;i<cntp;++i)
			{
                tmp[i] = p[i]->val;
				if(p[i]->left)q[cntq++] = p[i]->left;
				if(p[i]->right)q[cntq++] = p[i]->right;
			}
			ans.push_back(tmp);
			swap(p,q);
			swap(cntp,cntq);
		}
		return ans;

    }
};

int main(){
    return 0;
}
