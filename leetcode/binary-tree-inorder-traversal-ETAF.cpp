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
class Solution_old { //recursive
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> ans = inorderTraversal(root->left);
        vector<int> ansr = inorderTraversal(root->right);
        ans.push_back(root->val);
        for(auto it=ansr.begin(); it!=ansr.end(); ++it){
            ans.push_back(*it);
        }
        return ans;
    }
};
class Solution_old1{ //recursive
public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        ans.emplace_back(root->val);
        dfs(root->right);
    }
};

class Solution { //non recursive
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        if(!root) return ans;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();
            if(!root){
                root = st.top();
                st.pop();
                ans.push_back(root->val);
            }else{
                if(root->right) st.push(root->right);
                st.push(root);
                st.push(NULL);
                if(root->left) st.push(root->left);
            }
        }
        return ans;
    }
};
class Solution_beautiful {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        while( root){
            st.push(root);
            root = root->left;
            while(root == NULL && !st.empty()){
                root = st.top();
                st.pop();
                ans.push_back(root->val);
                root = root->right;
            }
        }
        return ans;
    }
};
class Solution_more_beautiful {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        while(!st.empty() || root){
            if(root == NULL){
                root = st.top();
                st.pop();
                ans.push_back(root->val);
                root = root->right;
            }else{
                st.push(root);
                root = root->left;
            }
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
    vector<int> ans = sol.inorderTraversal(p[0]);
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
    vector<int> ans = sol.inorderTraversal(p[1]);
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


