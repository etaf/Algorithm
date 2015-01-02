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
class BSTIterator {
    private: TreeNode* now;
             stack<TreeNode*> st;
public:
    BSTIterator(TreeNode *root) {
        now = root;
        while(now){
            st.push(now);
            now = now->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(st.empty())return false;
        return true;
    }

    /** @return the next smallest number */
    int next() {
       TreeNode* now = st.top();
       st.pop();
       int res = now->val;
       now = now->right;
       while(now){
           st.push(now);
           now= now->left;
       }
       return res;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
int main()
{
    return 0;
}


