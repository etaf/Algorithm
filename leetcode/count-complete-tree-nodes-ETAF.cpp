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

typedef long long llong;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution_old {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lcnt = 0, rcnt=0;
        TreeNode* tmp = root;
        while(tmp->left) {tmp=tmp->left; ++lcnt;}
        tmp = root;
        while(tmp->right) {tmp=tmp->right; ++rcnt;}
        if(lcnt == rcnt) return (1<<(lcnt+1))-1;
        return countNodes(root->left) + countNodes(root->right)+1;
    }
};
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lcnt = -1, rcnt=-1;
        TreeNode* tmp  = root;

        int ans = 0;
        int mcnt = 0;
        while(root){
            if(lcnt == -1){
                lcnt = 0;
                tmp = root;
                while(tmp->left){
                    ++lcnt;
                    tmp = tmp->left;
                }
            }
            if(rcnt == -1){
                rcnt = 0;
                tmp = root;
                while(tmp->right){
                    ++rcnt;
                    tmp = tmp->right;
                }
            }
            //cout<<lcnt<<"-"<<rcnt<<endl;
            if(lcnt == rcnt){
                ans += (1<<(1+lcnt))-1;
                break;
            }
            tmp = root->left;
            mcnt = 1;
            while(tmp->right){
                ++mcnt;
                tmp = tmp->right;
            }
            if(mcnt == lcnt){
                ans += (1<<lcnt);
                root = root->right;
                --rcnt;
                lcnt = -1;
            }else{
                ans += (1<<rcnt);
                root = root->left;
                --lcnt;
                rcnt = mcnt-1;
            }
        }
        return ans;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);

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


