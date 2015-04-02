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
	int ans;
    int maxDepth(TreeNode *root) {
		if(!root)return 0;
       ans = 0; 
	   dfs(root,1);
	   return ans;
    }
	void dfs(TreeNode* now, int step){
		if(!now->left && !now->right){
			ans = max(ans,step);
			return;
		}
		if(now->left)
			dfs(now->left,step+1);
		if(now->right)
			dfs(now->right,step+1);
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
	cout<<sol.maxDepth(p[1])<<endl;


}
int main(){
    test();
    return 0;
}
