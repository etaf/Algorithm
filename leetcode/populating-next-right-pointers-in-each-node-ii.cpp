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
struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class Solution {
    public:
    void connect(TreeLinkNode *root) {
        if(!root)return;
        TreeLinkNode* p = root,*np=NULL;
        TreeLinkNode* q = NULL;
            while(p)
            {
                np = NULL;
                q = NULL;
                for(;p;p=p->next)
                {
                    if(p->left){
                        if(!np){ np = p->left;q = np;}
                        else{
                            q->next = p->left;
                            q = q->next;
                        }
                    }
                    if(p->right){
                        if(!np){ np = p->right;q = np;}
                        else{
                            q->next= p->right;
                            q = q->next;
                        }
                    }
                }
                p = np;
            }
    }
};
class Solution_extra_space { public:
    void connect(TreeLinkNode *root) {
        if(!root)return;
        TreeLinkNode* *p = new TreeLinkNode* [10010];
        TreeLinkNode* *q = new TreeLinkNode* [10010];
            int cntp=0,cntq=0;
            p[cntp++] = root;
            while(cntp)
            {
                cntq = 0;
                for(int i=0;i<cntp;++i)
                {
                    p[i]->next = (i+1<cntp ? p[i+1] : NULL);
                    if(p[i]->left)q[cntq++] = p[i]->left;
                    if(p[i]->right)q[cntq++] = p[i]->right;
                }

                swap(p,q);
                swap(cntp,cntq);
            }
    }
};
int main()
{
    TreeLinkNode* p[10];
    for(int i=1;i<=10;++i){
        p[i] = new TreeLinkNode(i);
    }
    p[1]->left = p[2];
    p[1]->right = p[3];
    p[2]->left = p[4];
    p[2]->right = p[5];
    p[3]->right = p[6];
    p[4]->left = p[7];
    p[6]->right = p[8];
    Solution sol;
    sol.connect(p[1]);
    for(int i=1;i<=8;++i){
        if(p[i]->next == NULL)
            cout<<i<<"->NULL"<<endl;
        else
            cout<<i<<"->"<<p[i]->next->val<<endl;
    }

	return 0;
}


