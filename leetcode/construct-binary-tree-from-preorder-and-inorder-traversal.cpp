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

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {

        return dfs(0,preorder.size(),0,inorder.size(),preorder,inorder);
    }
    TreeNode* dfs(int pl,int pr,int il,int ir,const vector<int>& preorder,const vector<int>& inorder)
    {
        if(pr-pl<1)return NULL;
        TreeNode* u = new TreeNode(preorder[pl]);
        int imid,pmid;
        for(int i =il;i<ir; ++i){
            if(inorder[i] == u->val)
            {
                imid = i;
                break;
            }
        }
        pmid = pl+1+imid-il;
        u->left = dfs(pl+1,pmid,il,imid,preorder,inorder);
        u->right = dfs(pmid,pr,imid+1,ir,preorder,inorder);
        return u;
    }
};



class Solution4test {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
		vector<vector<int> > ans;
		if(!root)return ans;
		TreeNode* *p = new TreeNode* [10010];
		TreeNode* *q = new TreeNode* [10010];
		int cntp=0,cntq=0;
		p[cntp++] = root;
		while(cntp)
		{
			cntq = 0;
			vector<int> tmp;
			for(int i=0;i<cntp;++i)
			{
				tmp.push_back(p[i]->val);
				if(p[i]->left)q[cntq++] = p[i]->left;
				if(p[i]->right)q[cntq++] = p[i]->right;
			}
			ans.push_back(tmp);
			swap(p,q);
			swap(cntp,cntq);
		}
		vector<vector<int> > nans;
		for(int i=ans.size()-1;i>=0;--i)nans.push_back(ans[i]);
		return nans;
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
    vector<int> inorder({3,2,4,1,5,6});
    //vector<int> postorder({3,4,2,6,5,1});
    vector<int> preorder({1,2,3,4,5,6});
    TreeNode* root = sol.buildTree(preorder,inorder);
    Solution4test sol4test;
    vector< vector<int> > ans =sol4test.levelOrderBottom(root);
    for(int i=0;i<ans.size();++i)
    {
        for(int j=0;j<ans[i].size();++j){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

}
int main(){
    test();
    return 0;
}
