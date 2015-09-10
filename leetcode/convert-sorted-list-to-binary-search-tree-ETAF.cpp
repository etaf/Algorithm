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
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        queue<TreeNode*> Q;
        TreeNode* root = new TreeNode(head->val);
        head = head->next;
        Q.push(root);
        while(!Q.empty() && head){
            TreeNode* p = Q.front();
            Q.pop();
            p->left = new TreeNode(head->val);
            head = head->next;
            Q.push(p->left);
            if(!head) return root;
            p->right = new TreeNode(head->val);
            head = head->next;
            Q.push(p->right);
        }
        return root;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    return 0;
}


