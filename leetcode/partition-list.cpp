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
    ListNode *partition(ListNode *head, int x) {
        ListNode* l = NULL, *r = NULL, *now=head, *prel=NULL,*preNow = NULL;
        while(now){
            if(now->val < x ){
                if(l!=NULL){
                    r->next = now->next;
                    if(prel != NULL) prel->next = now;
                    else head = now;
                    prel = now;
                    now->next = l;
                    now = r;
                }
            }
            else if(now->val >= x){
                if( NULL == l ){
                    prel = preNow;
                    l = now;
                    r = now;
                }else{
                    r = now;
                }
            }
            preNow = now;
            now = now->next;
        }
        return head;
    }
};
void show(ListNode* head){
    while(head){
        cout<<head->val<<" ";
        head= head->next;
    }
    cout<<endl;
}
int main()
{
    ListNode* p[10];
    for(int i=1;i<=6;++i){
        p[i] = new ListNode(7-i);
    }
    for(int i=1;i<6;++i) p[i]->next = p[i+1];
    Solution sol;
    show(p[1]);
    show(sol.partition(p[1],3));
    return 0;
}


