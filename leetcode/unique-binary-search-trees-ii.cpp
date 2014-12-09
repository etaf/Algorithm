#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode *> ans;
    vector<TreeNode *> generateTrees(int n) {
       return dfs(1,n+1);
    }
    vector<TreeNode *> dfs(int l,int r){

        vector<TreeNode* >ans;
        if(r-l<1){
            ans.push_back(NULL);
            return ans;
        }
        if(r-l == 1){

            ans.push_back(new TreeNode(l));
            return ans;
        }
        vector<TreeNode * > ltree, rtree;
        for(int mid = l;mid<r;++mid){
            ltree = dfs(l,mid);
            rtree = dfs(mid+1,r);
            for(int i=0;i<ltree.size();++i)
            {
                for(int j=0;j<rtree.size();++j)
                {
                    TreeNode* tmp = new TreeNode(mid);
                    tmp->left = ltree[i];
                    tmp->right = rtree[j];
                    ans.push_back(tmp);
                }
            }
        }
        return ans;
    }

};

void output_tree(TreeNode* u)
{
    if(!u)return;

    cout<<u->val<<" ";
    output_tree(u->left);
    output_tree(u->right);
}
void test(){

    Solution sol;
    vector<TreeNode*> ans = sol.generateTrees(3);
    for(int i=0;i<ans.size();++i)
    {
        output_tree(ans[i]);
        cout<<endl;
    }
}
int main(){

    test();
    return 0;
}
