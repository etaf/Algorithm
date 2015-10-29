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
class Solution_general {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        if(!root)return ans;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            if(!root){
                st.pop();
                root = st.top();
                st.pop();
                ans.push_back(root->val);
            }else{
                st.push(NULL);
                if(root->right) st.push(root->right);
                if(root->left) st.push(root->left);
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        if(!root) return ans;
        st.push(root);
        TreeNode* pre = root;
        while(!st.empty()){
            root = st.top();
            if(root->left && root->left != pre && root->right != pre){
                st.push(root->left);
            }else if(root->right && root->right != pre){
                st.push(root->right);
            }else{
                ans.push_back(root->val);
                pre = root;
                st.pop();
            }
        }
        return ans;
    }
};
class Solution_old {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        //if(!root) return ans;
        while(!st.empty() || root){
            if(!root){
                root=st.top();
                st.pop();
                if(!root){
                    ans.push_back(st.top()->val);
                    st.pop();
                    root = NULL;
                    continue;
                }
            }
            st.push(root);
            st.push(NULL);
            if(root->right)
                st.push(root->right);
            root = root->left;
        }
        return ans;
    }
};
void test(){
    TreeNode* p[10];
    for(int i=0; i<10; ++i){
        p[i] = new TreeNode(i);
    }
    p[0]->left = p[1];
    p[0]->right = p[2];
    p[1]->left = p[3];
    p[1]->right = p[4];
    p[2]->left = p[5];
    p[2]->right = p[6];
    p[3]->right = p[7];
    Solution sol;
    vector<int> ans = sol.postorderTraversal(p[0]);
    for(auto x : ans) cout<<x<<" ";
    cout<<endl;
}
void test1(){
    TreeNode* p[10];
    for(int i=0; i<10; ++i){
        p[i] = new TreeNode(i);
    }
    p[1]->right = p[2];
    p[2]->left = p[3];
    Solution sol;
    vector<int> ans = sol.postorderTraversal(p[1]);
    for(auto x : ans) cout<<x<<" ";
    cout<<endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    test();
    test1();
    return 0;
}


