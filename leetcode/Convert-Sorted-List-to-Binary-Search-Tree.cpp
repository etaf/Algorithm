#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	vector< ListNode* > ls;
    TreeNode *sortedListToBST(ListNode *head) {
		if(!head)return NULL;
		while(head)
		{
			ls.push_back(head);
			head= head->next;
		}
		int l=0, r = ls.size();
		return dfs(l,r);

    }
	TreeNode* dfs(int l,int r){
		if(r-l<1)return NULL;

		int mid = (l+r)>>1;

		TreeNode*  root = new TreeNode(ls[mid]->val);

		root ->left = dfs(l,mid);
		root ->right = dfs(mid+1,r);
		return root;
	}

};

class Solution_old {
public:
    TreeNode *sortedListToBST(ListNode *head) {
		if(!head)return NULL;
		int l=0, r = get_length(head);
		return dfs(l,r,head);

    }
	TreeNode* dfs(int l,int r,ListNode* head){
		if(r-l<1)return NULL;

		int mid = (l+r)>>1;

		TreeNode*  root = new TreeNode( get_kth_val(head,mid));

		root ->left = dfs(l,mid,head);
		root ->right = dfs(mid+1,r,head);
		return root;
	}
	int get_length(ListNode* head){
		int n = 0;
		while(head){
			++n;
			head = head->next;
		}
		return n;
	}

	int get_kth_val(ListNode *head,int k)
	{

		for(int i=0;i<k;++i)
		{
			head = head->next;
		}
		return head->val;
	}
};

class Solution1 {
public:
	vector<int> ans;
    vector<int> inorderTraversal(TreeNode *root) {
		ans.clear();
		if(root)dfs(root); 
		return ans;
    }
	void dfs(TreeNode* u)
	{
		if(u->left)
		{
			dfs(u->left);
		}
		ans.push_back(u->val);
		if(u->right)
		{
			dfs(u->right);
		}
	}
};

class Solution2 {
public:
    bool isBalanced(TreeNode *root) {
        if(root)
            return dfs(root);
        else {
            return true;
        }
    }
    bool dfs(TreeNode* u){
        u->val = 0;
        int l=0,r=0;
        if(u->left){
            if(!dfs(u->left))return false;
            l = u->left->val ;
        }
        if(u->right){
            if(!dfs(u->right)) return false;
            r = u->right->val ;
        }
        u->val = max(l,r)+1;
        return abs(l-r) < 2;

    }
};

Solution sol;
void test(){
	ListNode* p[11]; 
	int n = 1;
    for(int i=0;i<n;++i)
    {
        p[i] = new ListNode(i);
    }
	p[n] = NULL;
	for(int i=0;i<n;++i)
	{
		p[i]->next = p[i+1];
	}
	TreeNode* ans = sol.sortedListToBST(p[0]);
	Solution1 sol1;
	vector<int> path = sol1.inorderTraversal(ans);
	for(int i=0;i<path.size();++i)cout<<path[i]<<"->";
	cout<<"end"<<endl;
	Solution2 sol2;
	cout<< (sol2.isBalanced(ans)?"YES":"NO")<<endl;
}
int main(){
    test();
    return 0;
}
