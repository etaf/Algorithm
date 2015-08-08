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
class Solution_TLE {
public:
    int lst,rst;
    bool found;
    int get_lst(TreeNode* root){
        return root == NULL ? 0 : 1 + get_lst(root->left);
    }
    int get_rst(TreeNode* root){
        return root == NULL ? 0 : 1 + get_rst(root->right);
    }
    int countNodes(TreeNode* root) {
        lst = get_lst(root);
        rst = get_rst(root);
        int ans = (1<<(lst)) - 1;
        if(lst == rst){
            return ans;
        }
        found = false;
        //return  ans - dfs(root,1);
        //cout<<"pre_ans="<<ans<<endl;
        return  ans - (1<<(lst-1)) + dfs(root,1);
    }
/*    int dfs(TreeNode* root, int dep){*/
        //if(found) return 0;
        //if(root->left == NULL) return dep == lst -1 ? 2 : 0;
        //if(root->right == NULL){
            //found = true;
            //return dep == lst - 1 ;
        //}
        //int cntl = 0, cntr = dfs(root->right, dep+1);
        //if(cntr)
            //cntl = dfs(root->left, dep+1);
        //if(cntr != cntl) found = true;
        //return cntr + cntl ;
    //}

    int dfs(TreeNode* root, int dep){
        if(found) return 0;
        if(root->left == NULL) return dep == lst;
        if(root->right == NULL){
            found = true;
            return 1;
        }
        int cntl = dfs(root->left, dep+1);
        int cntr = dfs(root->right, dep+1);
        if(cntr != cntl) found = true;
        return cntr + cntl ;
    }
};


class Solution_recursive {//Accept: recursive binary serarch
private:
    int get_lst(TreeNode* root){
        return root == NULL ? 0 : 1 + get_lst(root->left);
    }
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int l = get_lst(root->left);
        int r = get_lst(root->right);
        if(l == r){
            return (1<<l) + countNodes(root->right);
        }
        return (1<<r) + countNodes(root->left);
    }
};
class Solution{ //Accept: iterative binary search
private:
    int get_lst(TreeNode* root){
        int ans = 0;
        while(root){
            ++ans;
            root = root->left;
        }
        return ans;
    }
public:
    int countNodes(TreeNode* root) {
        int ans = 0;
        while(root){
            int l = get_lst(root->left);
            int r = get_lst(root->right);
            if(l == r){
                ans += (1<<l);
                root = root->right;
            }else{
                ans += (1<<r);
                root = root->left;
            }
        }
        return ans;
    }
};
int main()
{
 Solution sol;

    TreeNode* root = new TreeNode(1);
    TreeNode* l = new TreeNode(1);
    TreeNode* r = new TreeNode(1);
    TreeNode* ll = new TreeNode(1);
    TreeNode* lr = new TreeNode(1);
    TreeNode* rl = new TreeNode(1);
    TreeNode* rr = new TreeNode(1);

    cout<<sol.countNodes(root)<<endl; //1

    root->left = l;
    cout<<sol.countNodes(root)<<endl; //2

    root->right = r;
    cout<<sol.countNodes(root)<<endl; //3

    l->left = ll;
    cout<<sol.countNodes(root)<<endl; //4

    l->right = lr;
    cout<<sol.countNodes(root)<<endl; //5

    r->left = rl;
    cout<<sol.countNodes(root)<<endl; //6

    r->right = rr;
    cout<<sol.countNodes(root)<<endl; //7
    return 0;
}


