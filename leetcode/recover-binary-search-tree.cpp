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
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution { //swap 2 element means 1 6 3 4 5 2, we will find the sistuation that X1 > X2 , and X1 is the bigger one which was swapped, the find sistuation that X1 > X2, X2 is the smaller one
public:

    TreeNode* bigger;
    TreeNode* smaller;
    TreeNode* pre;
    void recoverTree(TreeNode *root) {
       if(!root)return;
       bigger = smaller = pre = NULL;
       dfs(root);
       swap(bigger->val,smaller->val);
    }

    void dfs(TreeNode* u){

        if(u->left)
            dfs(u->left);

        if(pre && !bigger && u->val < pre->val)bigger = pre;
        if(pre && bigger && u->val < pre->val)smaller = u;
        pre = u;
        if(u->right)
            dfs(u->right);

    }
};
class Solution_bubble { //冒泡排序的思想
public:

    TreeNode* pre;
    bool swapped;
    void recoverTree(TreeNode *root) {
       if(!root)return;
       swapped = true;
       while(swapped){
        pre = NULL;
        swapped = false;
        dfs(root);
       }
    }

    void dfs(TreeNode* u){

        if(u->left)
            dfs(u->left);
        if(pre && u->val < pre->val )
        {
            swapped = true;
            swap(u->val,pre->val);
        }
        pre = u;
        if(u->right)
            dfs(u->right);

    }
};
void dfs(TreeNode* u)
{
    if(u->left)dfs(u->left);
    cout<<u->val<<" ";
    if(u->right)dfs(u->right);
}
void test(){

    int n = 6;
    TreeNode * ns[100];
    for(int i=1;i<=n;++i)
    {
        ns[i] = new TreeNode(i);
    }

    ns[3]->left = ns[6];
    ns[6]->left = ns[1];
    ns[3]->right = ns[5];
    ns[5]->left = ns[4];
    ns[5]->right = ns[2];

    Solution sol;

    dfs(ns[3]);
    cout<<endl;
    sol.recoverTree(ns[3]);
    dfs(ns[3]);
    cout<<endl;

}
int main()
{
    test();
	return 0;
}


