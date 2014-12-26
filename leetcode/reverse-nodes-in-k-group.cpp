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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(k == 1)return head;
        ListNode* l=head,*r=NULL,*prel = NULL,*nextr=NULL;
        int i;
        while(l)
        {
            r = l;
            for(i=1;i<k && r->next;++i,r=r->next);
            if(i < k)break;
            if(prel){
                prel->next = r;
            }else{
                head = r;
            }
            nextr = r->next;
            reverse(l,r);
            l->next = nextr;
            prel = l;
            l = nextr;
        }
        return head;
    }
    void reverse(ListNode* l,ListNode* r){
        ListNode* pre = l,*now=l->next,*next,*end=r->next;
        while(now!= end){
            next = now->next;
            now ->next = pre;
            pre = now;
            now = next;
        }
    }
};
int main()
{
    Solution sol;
    ListNode* p[10];
    for(int i=1;i<10;++i)p[i] = new ListNode(i);
    for(int i=1;i<5;++i)p[i]->next = p[i+1];
    ListNode* head = sol.reverseKGroup(p[1],3);
    while(head){
        cout<<head->val<<"->";
        head = head->next;
    }
    cout<<endl;
    return 0;
}


