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

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(!head)return NULL;
        ListNode* now = head;
        int n = 0;
        while(now){
            now = now->next;
            ++n;
        }
        k%=n;
        if(n == 1 || k==0)return head;
        int t = n-k;
        now = head;
        while(--t){
           now = now->next;
        }
        ListNode* h2 = now->next;
        now->next =  NULL;
        now = h2;
        while(now->next){
            now = now->next;
        }
        now->next = head;
        return h2;
    }
};
void show(ListNode* head){
while(head){
        cout<<head->val<<"->";
        head=head->next;
    }
cout<<endl;
}
int main()
{
    ListNode* p[10];
    for(int i=1;i<=5;++i)p[i] = new ListNode(i);
    for(int i=1;i<5;++i)p[i]->next = p[i+1];
    show(p[1]);
    Solution sol;
    ListNode* head = sol.rotateRight(p[1],2);
    show(head);
    return 0;
}


